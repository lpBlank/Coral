#include "Window.h"

bool Window::_Create(const char* title, int x, int y, int w, int h, Uint32 flags)
{
	rect = new Rect(0, 0, w, h);
	window = SDL_CreateWindow(title, x, y, w, h, flags);
	if (window)
	{
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		return true;
	}
	return false;
}

bool Window::_Create(const char* title, int w, int h, Uint32 flags)
{
	return _Create(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, flags);
}

void Window::_Destroy()
{
	SDL_DestroyWindow(window);
}

Window::Window()
{
}

Window::Window(const char * title, int x, int y, int w, int h, Uint32 flags)
{
	_Create(title, x, y, w, h, flags);
}

Window::Window(const char * title, Rect* rect, Uint32 flags)
{
	_Create(title, rect->w, rect->h, flags);
}

Window::Window(const char * title, int w, int h, Uint32 flags)
{
	_Create(title, w, h, flags);
}

Window::Window(const char * title, Point* point, Uint32 flags)
{
	_Create(title, point->x, point->y, flags);
}

Window::~Window()
{
	_Destroy();
}

/*bool Window::UpdateSurface()
{
	if (SDL_UpdateWindowSurface(window) < 0)
		return false;
	return true;
}*/