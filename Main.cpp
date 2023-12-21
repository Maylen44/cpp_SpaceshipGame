#include "Game.h"
#include <SFML/Audio.hpp>



int main()
{
    Game game;

    /* Problems with compiler version. fix if posible. source info on problem: https://en.sfml-dev.org/forums/index.php?topic=28804.0
    sf::SoundBuffer buffer;
    
    if (!buffer.loadFromFile("laser10.wav"))
    { }
    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.play();
    
    sf::Music music;
    if (!music.openFromFile("outerspace.ogg"))
    {
    }
    music.play();
    */
    game.run();

    return 0;
}