#include "screen_buffer.h"

#include <Windows.h>

namespace
{
    class ScreenBuffer
    {
    public:
        ScreenBuffer();
        ~ScreenBuffer();
        void SetCursorPosition(COORD coordinates);
        void ClearScreen();

    private:
        HANDLE handle_;
    };
    
    ScreenBuffer screen_buffer;
}

namespace screenbuffer
{
    void SetCursorPosition(int x, int y)
    {
        COORD coordinates = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
        screen_buffer.SetCursorPosition(coordinates);
    }

    void ClearScreen()
    {
        screen_buffer.ClearScreen();
    }
}

namespace
{
    ScreenBuffer::ScreenBuffer() :
        handle_(GetStdHandle(STD_OUTPUT_HANDLE))
    {
    }

    ScreenBuffer::~ScreenBuffer()
    {
    }

    void ScreenBuffer::SetCursorPosition(COORD coordinates)
    {
        SetConsoleCursorPosition(handle_, coordinates);
    }

    void ScreenBuffer::ClearScreen()
    {
        CONSOLE_SCREEN_BUFFER_INFO buffer_info;
        GetConsoleScreenBufferInfo(handle_, &buffer_info);
        
        DWORD number_of_cells = buffer_info.dwSize.X * buffer_info.dwSize.Y;
        TCHAR fill_character = ' ';
        COORD beginning_point = { 0,0 };
        DWORD number_of_inserted_characters;
        FillConsoleOutputCharacter(handle_, fill_character, number_of_cells, beginning_point, &number_of_inserted_characters);

        SetCursorPosition(beginning_point);
    }
}
