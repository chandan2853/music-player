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
        bool createPlaylist(std::string playlistName);
        bool addSong(std::string playlistName,std::string songName);
        bool deletePlaylist(std::string playlistName);
        bool deleteSong(std::string playlistName,std::string songName);
        bool changePosition(std::string playlistName,std::string songName,char choice);
        bool displayPlaylist();
        bool displaySongInPlaylist(std::string playlistName);
};
