#ifndef KEYBOARD_BUFFER_H
#define KEYBOARD_BUFFER_H

#include <Windows.h>
#include <vector>

namespace keyboardbuffer
{
    const WORD kNone = 0;
    const WORD kArrowUp = 38;
    const WORD kArrowDown = 40;
    const WORD kArrowLeft = 37;
    const WORD kArrowRight = 39;
    const WORD kSpace = 32;
    const WORD kEnter = 13;
    const WORD kEsc = 27;
    const WORD kBackspace = 8;
    const WORD kE = 69;
    const WORD kOne = 49;
    const WORD kTwo = 50;
    const WORD kThree = 51;

    void ReadInput();
    bool IsInput(const WORD& key);
    void WaitUntilInput(std::vector<WORD> allowed_input);
    char GetInput();
}

#endif // KEYBOARD_BUFFER_H
