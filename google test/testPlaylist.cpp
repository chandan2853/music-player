#include <iostream>
#include "./gtest/gtest.h"
#include "playlist.cpp"
Playlist playlist;
TEST(addplaylist,test_playlist)
{
    bool result=playlist.createPlaylist("rock");
    ASSERT_EQ(result,true);
}
TEST(addsong,test_song)
{
    bool result=playlist.addSong("rock","alive.mp3");
    ASSERT_EQ(result,true);
}
TEST(displayplaylist,test_playlist)
{
    bool result=playlist.displayPlaylist();
    ASSERT_EQ(result,true);
}
TEST(changeposition,moveup)
{
    playlist.addSong("rock","ali.mp3");
    playlist.addSong("rock","bass.mp3");
    bool result=playlist.changePosition("rock","bass.mp3",'+');
    ASSERT_EQ(result,true);
}
TEST(changeposition,movedown)
{
    bool result=playlist.changePosition("rock","bass.mp3",'-');
    ASSERT_EQ(result,true);
}
TEST(deletesong,test_song)
{
    bool result=playlist.deleteSong("rock","alive.mp3");
    ASSERT_EQ(result,true);
}
TEST(deleteplaylist,test_playlist)
{
    bool result=playlist.deletePlaylist("rock");
    ASSERT_EQ(result,true);
}
int main(int argc, char **argv)
{
    Playlist playlist;

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
