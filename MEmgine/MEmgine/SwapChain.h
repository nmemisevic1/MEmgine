#pragma once
#include <d3d11.h>

class SwapChain
{
public:
	SwapChain();

	~SwapChain();

	// Initialize SwapChain for a window
	bool init(HWND hwnd, UINT width, UINT height);

	// Release all resources loaded
	bool release();

private:
	IDXGISwapChain* mSwapChain;
};

