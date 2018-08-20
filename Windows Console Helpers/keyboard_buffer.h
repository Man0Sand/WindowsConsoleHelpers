#ifndef KEYBOARD_BUFFER_H
#define KEYBOARD_BUFFER_H

#include <Windows.h>

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

    void ReadInput();
    bool IsInput(const WORD& key);
}

namespace
{
    class KeyboardBuffer
    {
    public:
        KeyboardBuffer();
        ~KeyboardBuffer();
        void ReadInput();
        bool IsInput(const WORD& key);

    private:
        HANDLE handle_;
        DWORD events_;
        INPUT_RECORD buffer_;
        WORD key_pressed_;
    };
}

#endif // KEYBOARD_BUFFER_H
