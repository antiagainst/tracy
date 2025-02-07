#ifndef __BACKEND_HPP__
#define __BACKEND_HPP__

#include <functional>
#include <stdint.h>

#include "WindowPosition.hpp"

class RunQueue;

class Backend
{
public:
    Backend( const char* title, std::function<void()> redraw, RunQueue* mainThreadTasks );
    ~Backend();

    void Show();
    void Run();

    void NewFrame( int& w, int& h );
    void EndFrame();

    void SetIcon( uint8_t* data, int w, int h );
    void SetTitle( const char* title );

    float GetDpiScale();
    void* GetNativeWindow();

private:
    WindowPosition m_winPos;
    int m_w, m_h;
};

#endif
