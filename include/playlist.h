#include <vector>
#include <string>
#include <utility>
#include <map>
class Playlist
{
    private:
        std::map <std::string ,std::vector<std::string> >  playlists;
        std::vector<std::string> songs;
    public:
        void createPlaylist();
        void addSong();
        void deletePlaylist();
        void deleteSong();
        void changePosition();
        void displayPlaylist();
        void displaySongInPlaylist();
        void playSong();
};
