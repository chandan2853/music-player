#include <iostream>
#include <algorithm>
#include <fstream>
#include "playlist.h"
bool Playlist :: createPlaylist(std::string playlistName)
{
    bool success=false;
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
        success=true;
    }
    return success;
}

bool Playlist::displayPlaylist()
{
    bool success=true;
    if(playlists.size()==0)
    {
        std::cout<<"Playlist is empty!"<<std::endl;
        success=false;
    }
    for(auto playlist:playlists)
    {
        std::cout<<playlist.first<<std::endl;
    }
    return success;
}

bool Playlist::addSong(std::string playlistName,std::string songName)
{
    bool success=false;
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
            std::string path="/home/chandan/c++proj/music player/data/";
            path+=songName;
            std::ifstream audioFile;
            audioFile.open(path);
            if(audioFile)
            {
                playlists[playlistName].push_back(songName);

                std::cout<<"Song added successfully!"<<std::endl;
                success=true;
            }
            else
            {
                std::cout<<"File not available in local storage!"<<std::endl;
            }
        }
    }
    return success;
}

bool Playlist::displaySongInPlaylist(std::string playlistName)
{
    bool success=true;
    if(playlists.size()==0)
    {
        std::cout<<"Playlist is empty!"<<std::endl;
        success=false;
    }
    else
    {
        if(playlists.find(playlistName)==playlists.end())
        {
            std::cout<<"Playlist not found!"<<std::endl;
            success=false;
        }
        else
        {
            for(auto playlist: playlists[playlistName])
            {
                std::cout<<playlist<<std::endl;
            }
        }
    }
    return success;
}

bool Playlist::deletePlaylist(std::string playlistName)
{
    bool success=false;
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
                success=true;
                break;
            }
        }
        if(flag==0)
        {
            std::cout<<"Playlist not found!"<<std::endl;
        }
    }
    return success;
}

bool Playlist::deleteSong(std::string playlistName,std::string songName)
{
    bool success=false;
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
                for(auto index=playlist.second.begin();index!=playlist.second.end();index++)
                {
                    if(*index==songName)
                    {
                        flag=1;
                        playlists[playlistName].erase(std::remove(playlists[playlistName].begin(), playlists[playlistName].end(), songName), playlists[playlistName].end());
                        std::cout<<"Song deleted successfully!"<<std::endl;
                        success=true;
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
    return success;
}

bool Playlist::changePosition(std::string playlistName,std::string songName,char choice)
{
    bool success=false;
    
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
            int j=0;
            for(auto index=playlists[playlistName].begin();index!=playlists[playlistName].end();index++,j++)
            {
                if(*index==songName)
                {
                    
                    if(choice=='+' && j>0)
                    {
                        std::swap(playlists[playlistName][j],playlists[playlistName][j-1]);
                        std::cout<<"Song moved up successfully!"<<std::endl;
                        success=true;
                    }
                    if(choice=='-' && j<playlists[playlistName].size()-1)
                    {
                        std::swap(playlists[playlistName][j],playlists[playlistName][j+1]);
                        std::cout<<"Song moved down successfully!"<<std::endl;
                        success=true;
                    }
                    break;
                }
            }
        }
    }
    return success;
}