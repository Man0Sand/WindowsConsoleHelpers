#include <iostream>

#include "keyboard_buffer.h"

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
    try_keyboard_buffer();
}
