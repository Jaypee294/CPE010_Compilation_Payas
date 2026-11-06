#include <iostream>
#include <string>
#include "double_LL.h"

int main(){

    doubleList<std::string>* playlist = nullptr;

    insertSong(&playlist, std::string("Given Up"));
    insertSong(&playlist, std::string("Bodies"));
    insertSong(&playlist, std::string("Eyeless"));
    insertSong(&playlist, std::string("Psychosocial"));

    std::cout << "Playlist: \n";
    playPlaylist(playlist);

    doubleList<std::string>* current = playlist;

    std::cout << "\nCurrent Song: " << current->data << std::endl;

    nextSong(&current);
    std::cout << "Next Song: " << current->data << std::endl;

    nextSong(&current);
    std::cout << "Next Song: " << current->data << std::endl;

    previousSong(&current);
    std::cout << "Previous Song: " << current->data << std::endl;

    insertSong(&playlist, std::string("Duality"));

    std::cout << "\nPlaylist After Adding a Song\n";
    playPlaylist(playlist);

    deleteSong(&playlist, std::string("Bodies"));

    std::cout << "\nPlaylist After Removing 'Bodies'\n";
    playPlaylist(playlist);

    return 0;
}