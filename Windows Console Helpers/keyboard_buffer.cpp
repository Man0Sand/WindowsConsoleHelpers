#include <unordered_map>
#include <Windows.h>

#include "keyboard_buffer.h"

namespace
{
    class KeyboardBuffer
    {
    public:
        KeyboardBuffer();
        ~KeyboardBuffer();
        void ReadInput();
        WORD GetInput();

    private:
        HANDLE handle_;
        DWORD events_;
        INPUT_RECORD buffer_;
        WORD key_pressed_;
    };
    
    KeyboardBuffer keyboard_buffer;
}

namespace keyboardbuffer
{
    void ReadInput()
    {
        keyboard_buffer.ReadInput();
    }

    bool IsInput(const int& key)
    {
        return keyboard_buffer.GetInput() == static_cast<WORD>(key);
    }

    char GetInput()
    {
        static std::unordered_map<WORD, char> key_mappings = { {kOne, '1'}, {kTwo, '2'}, {kThree, '3'}};
        WORD user_input = keyboard_buffer.GetInput();
        if (key_mappings.count(user_input))
        {
            return key_mappings[user_input];
        }
        else
        {
            return kNone;
        }
    }

    void WaitUntilInput(std::vector<int> allowed_input)
    {
        while (true)
        {
            ReadInput();
            for (int user_input : allowed_input)
            {
                if (IsInput(user_input))
                {
                    return;
                }
            }
        }
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

    WORD KeyboardBuffer::GetInput()
    {
        return key_pressed_;
    }
}
