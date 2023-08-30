#include <iostream>
#include <algorithm>
#include <fstream>
#include "..\include\playlist.h"
void Playlist :: createPlaylist()
{
    std::string playlistName,songName;
    std::cout<<"Enter Playlist name :";
    std::cin>>playlistName;
    int flag=0;
    for(auto playlist:playlists)
    {
        if(playlist.first==playlistName)
        {
            flag=1;
            std::cout<<"Playlist already exist!"<<std::endl;
        }
    }
    if(flag==0)
    {
        playlists[playlistName] = songs;

        std::cout<<"Playlist created Successfully!"<<std::endl;
    }
}

void Playlist::displayPlaylist()
{
    if(playlists.size()==0)
    {
        std::cout<<"Playlist is empty!"<<std::endl;
    }
    for(auto playlist:playlists)
    {
        std::cout<<playlist.first<<std::endl;
    }
}

void Playlist::addSong()
{
    std::string playlistName;
    std::cout<<"Enter name of playlist to add song : ";
    std::cin>>playlistName;
    if(playlists.size()==0)
    {
        std::cout<<"Playlist is empty!"<<std::endl;
    }
    else
    {

        if(playlists.find(playlistName)==playlists.end())
        {
            std::cout<<"Playlist not found!"<<std::endl;
        }
        else
        {
            std::string songName,path="C:/Users/chandan.verma/OneDrive - InTimeTec Visionsoft Pvt. Ltd.,/Desktop/music player/data/";
            std::cout<<"Enter song name : ";
            std::cin>>songName;
            path+=songName;
            std::ifstream audioFile;
            audioFile.open(path);
            if(audioFile)
            {
                playlists[playlistName].push_back(songName);

                std::cout<<"Song added successfully!"<<std::endl;
            }
            else
            {
                std::cout<<"File not available in local storage!"<<std::endl;
            }
        }

    }
}

void Playlist::displaySongInPlaylist()
{
    std::string playlistName;
    std::cout<<"Enter name of playlist to display song : ";
    std::cin>>playlistName;
    if(playlists.size()==0)
    {
        std::cout<<"Playlist is empty!"<<std::endl;
    }
    else
    {
        if(playlists.find(playlistName)==playlists.end())
        {
            std::cout<<"Playlist not found!"<<std::endl;
        }
        else
        {
            for(auto song: playlists[playlistName])
            {
                std::cout<<song<<std::endl;
            }
        }
    }
}

void Playlist::deletePlaylist()
{
    std::string playlistName;
    std::cout<<"Enter name of playlist to delete : ";
    std::cin>>playlistName;
    if(playlists.size()==0)
    {
        std::cout<<"Playlist is empty!"<<std::endl;
    }
    else
    {
        int flag=0;
        for(auto playlist:playlists)
        {
            if(playlist.first==playlistName)
            {
                flag=1;
                playlists.erase(playlistName);
                std::cout<<"Playlist deleted successfully!"<<std::endl;
                break;
            }
        }
        if(flag==0)
        {
            std::cout<<"Playlist not found!"<<std::endl;
        }
    }
}

void Playlist::deleteSong()
{

    if(playlists.size()==0)
    {
        std::cout<<"Playlist is empty!"<<std::endl;
    }
    else
    {
        std::string playlistName;
        std::cout<<"Enter name of playlist from which you want to delete the song: ";
        std::cin>>playlistName;
        int flag=0;
        for(auto playlist:playlists)
        {

            if(playlist.first==playlistName)
            {
                std::string songName;
                std::cout<<"Enter the song which you want to delete : ";
                std::cin>>songName;
                for(auto index=playlist.second.begin();index!=playlist.second.end();index++)
                {
                    if(*index==songName)
                    {
                        flag=1;
                        playlists[playlistName].erase(std::remove(playlists[playlistName].begin(), playlists[playlistName].end(), songName), playlists[playlistName].end());
                        std::cout<<"Song deleted successfully!"<<std::endl;
                        break;
                    }
                }
            }
        }
        if(flag==0)
        {
            std::cout<<"Playlist/Song not found!"<<std::endl;
        }
    }

}

void Playlist::changePosition()
{
    std::string playlistName;
    std::cout<<"Enter name of playlist : ";
    std::cin>>playlistName;
    if(playlists.size()==0)
    {
        std::cout<<"Playlist is empty!"<<std::endl;
    }
    else
    {
        if(playlists.find(playlistName)==playlists.end())
        {
            std::cout<<"Playlist not found!"<<std::endl;
        }
        else
        {
            std::string songName;
            int swapIndex=0;
            std::cout<<"Enter the song which you want to move: ";
            std::cin>>songName;
            for(auto index=playlists[playlistName].begin();index!=playlists[playlistName].end();index++,swapIndex++)
                {
                    if(*index==songName)
                    {
                        char choice;
                        std::cout<<"To move up press + and for down - : ";
                        std::cin>>choice;
                        if(choice=='+' && swapIndex>0)
                        {
                            std::swap(playlists[playlistName][swapIndex],playlists[playlistName][swapIndex-1]);
                            std::cout<<"Song moved up successfully!"<<std::endl;
                        }
                        if(choice=='-' && swapIndex<playlists[playlistName].size()-1)
                        {
                            std::swap(playlists[playlistName][swapIndex],playlists[playlistName][swapIndex+1]);
                            std::cout<<"Song moved down successfully!"<<std::endl;
                        }
                        break;
                    }
                }
        }

    }
}

void Playlist::playSong()
{

    std::string playlistName;
    std::cout<<"Enter name of playlist to play the songs : ";
    std::cin>>playlistName;
    if(playlists.size()==0)
    {
        std::cout<<"Playlist is empty!"<<std::endl;
    }
    else
    {
        for(int songIndex=0;songIndex<playlists[playlistName].size();songIndex++)
        {

            std::string path="open \"C:/Users/chandan.verma/OneDrive - InTimeTec Visionsoft Pvt. Ltd.,/Desktop/music player/data/";
            std::string songName,path1="\" type mpegvideo alias mp3";
            songName=playlists[playlistName][songIndex];
            path=path+songName+path1;
            mciSendString(path.c_str(), NULL, 0, NULL);
            std::cout<<"Current Playing : "<<songName<<std::endl;
            while(1)
            {
                int choice;
                std::cout<<"Press 1 to play the file and press 2 to exit the file."<<std::endl;
                std::cin>>choice;
                if(choice==1)
                {
                    mciSendString("play mp3", NULL, 0, NULL);
                    std::cout<<"Playing...\n\n";
                }
                else if(choice==2)
                {
                    mciSendString("close mp3", NULL, 0, NULL);
                    break;
                }
                std::cout << "Press 0 to pause the file and press 2 to exit the file." << std::endl;
                std::cin>>choice;
                if(choice==0)
                {
                    mciSendString("pause mp3", NULL, 0, NULL);
                    std::cout<<"Paused \n\n";
                }
                else if(choice==2)
                {
                    mciSendString("close mp3", NULL, 0, NULL);
                    break;
                }

            }
            char choice;
            std::cout<<"To play next song press n for previous p for exit e: ";
            std::cin>>choice;
            switch (choice)
            {
                case 'p':
                    songIndex-=2;
                    break;
                case 'n':
                    break;
                case 'e':
                    goto end;
                default:
                    std::cout<<"Invalid Input"<<std::endl;
                    break;
            }  
        }
        end:;
    }
}
