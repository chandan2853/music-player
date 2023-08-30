#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#include "./src/playlist.cpp"
int main()
{
    Playlist list;
    int choice;
    std::cout<<"Music Player"<<std::endl;
    std::cout<<"1. Create Playlist \n2. Add Song \n3. Display Playlist\n4. Display Playlist Songs \n5. Delete Playlist \n6. Delete Playlist Song \n7. Change Position of Song \n8. Play Song"<<std::endl;
    while(true)
    {
        std::cout<<"Enter Choice : ";
        std::cin>>choice;
        switch (choice)
        {
            case 1:
                list.createPlaylist();
                break;
            case 2:
                list.addSong();
                break;
            case 3:
                list.displayPlaylist();
                break;
            case 4:
                list.displaySongInPlaylist();
                break;
            case 5:
                list.deletePlaylist();
                break;
            case 6:
                list.deleteSong();
                break;
            case 7:
                list.changePosition();
                break;
            case 8:
                list.playSong();
                break;
            default:
                goto terminate;
                break;
        }
    }
    terminate:
    return 0;
}
