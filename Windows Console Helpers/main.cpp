#include <iostream>
#include <vector>

#include "keyboard_buffer.h"
#include "screen_buffer.h"

void try_keyboard_buffer()
{
    bool quit = false;
    while (!quit)
    {
        keyboardbuffer::ReadInput();
        if (keyboardbuffer::IsInput(keyboardbuffer::kArrowUp))
        {
            std::cout << "Arrow up\n";
        }
        if (keyboardbuffer::IsInput(keyboardbuffer::kArrowDown))
        {
            std::cout << "Arrow down\n";
        }
        if (keyboardbuffer::IsInput(keyboardbuffer::kEnter))
        {
            std::cout << "Enter\n";
        }
        if (keyboardbuffer::IsInput(keyboardbuffer::kEsc))
        {
            quit = true;
        }
    }
}



int main(void)
{
    //try_keyboard_buffer();
    std::cout << "Standard text\n";
    screenbuffer::InvertColors();
    std::cout << "Highlighted text\n";
    screenbuffer::InvertColors();
    std::cout << "Standard text again\n";
    screenbuffer::InvertColors();
    std::cout << "Highlighted text once more";
    screenbuffer::InvertColors();
    keyboardbuffer::WaitUntilInput({ keyboardbuffer::kEnter });
    screenbuffer::ClearScreen();
    keyboardbuffer::WaitUntilInput({ keyboardbuffer::kEnter });
    screenbuffer::ClearRow();
    screenbuffer::SetCursorPosition(0, 3);
    std::cout << "                          ";
    // FillConsoleOutputCharacter ei vaikuta taustavärillisiin kohtiin.

    //std::cout << "position 0,0\n";
    //keyboardbuffer::WaitUntilInput({ keyboardbuffer::kEnter });
    //std::cout << "Highlighted text?!\n";



}
