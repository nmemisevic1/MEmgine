#pragma once
#include <d3d11.h>

class DeviceContext;

class SwapChain
{
public:
	SwapChain();

	~SwapChain();

	bool present(bool vsync);

	// Initialize SwapChain for a window
	bool init(HWND hwnd, UINT width, UINT height);

	// Release all resources loaded
	bool release();

private:
	IDXGISwapChain* mSwapChain;
	ID3D11RenderTargetView *mRenderTargetView;

private:
	friend class DeviceContext;
};

