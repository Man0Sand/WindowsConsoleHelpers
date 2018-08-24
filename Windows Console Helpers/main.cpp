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
    screenbuffer::SetCursorPosition(10, 20);
    std::cout << "position 10 , 20\n";
    keyboardbuffer::WaitUntilInput({ keyboardbuffer::kEnter });
    screenbuffer::ClearScreen();
    keyboardbuffer::WaitUntilInput({ keyboardbuffer::kEnter });
    std::cout << "position 0,0\n";
    keyboardbuffer::WaitUntilInput({ keyboardbuffer::kEnter });



}
