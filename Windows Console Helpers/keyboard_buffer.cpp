#include "keyboard_buffer.h"

static KeyboardBuffer keyboard_buffer;

namespace keyboardbuffer
{
    void ReadInput()
    {
        keyboard_buffer.ReadInput();
    }

    bool IsInput(const WORD& key)
    {
        return keyboard_buffer.IsInput(key);
    }
}

namespace
{
    KeyboardBuffer::KeyboardBuffer() :
        handle_(GetStdHandle(STD_INPUT_HANDLE)),
        key_pressed_(keyboardbuffer::kNone)
    {
    }

    KeyboardBuffer::~KeyboardBuffer()
    {
    }

    void KeyboardBuffer::ReadInput()
    {
        key_pressed_ = keyboardbuffer::kNone;

        PeekConsoleInput(handle_, &buffer_, 1, &events_);
        if (!(events_ > 0))
        {
            return;
        }

        ReadConsoleInput(handle_, &buffer_, 1, &events_);
        if (!buffer_.Event.KeyEvent.bKeyDown)
        {
            return;
        }

        key_pressed_ = buffer_.Event.KeyEvent.wVirtualKeyCode;
    }

    bool KeyboardBuffer::IsInput(const WORD & key)
    {
        return key_pressed_ == key;
    }
}
