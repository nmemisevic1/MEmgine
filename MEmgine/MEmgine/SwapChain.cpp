#include "SwapChain.h"
#include "GraphicsEngine.h"

SwapChain::SwapChain()
{

}

SwapChain::~SwapChain()
{

}

bool SwapChain::present(bool vsync)
{
	mSwapChain->Present(vsync, NULL);
	return true;
}

bool SwapChain::init(HWND hwnd, UINT width, UINT height)
{
	ID3D11Device* device = GraphicsEngine::getInstance()->mDevice;
	DXGI_SWAP_CHAIN_DESC swapChainDesc;
	ZeroMemory(&swapChainDesc, sizeof(swapChainDesc));

	swapChainDesc.BufferCount = 1;
	swapChainDesc.BufferDesc.Width = width;
	swapChainDesc.BufferDesc.Height = height;
	swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	swapChainDesc.BufferDesc.RefreshRate.Numerator = 60;
	swapChainDesc.BufferDesc.RefreshRate.Denominator = 1;
	swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	swapChainDesc.OutputWindow = hwnd;
	swapChainDesc.SampleDesc.Count = 1;
	swapChainDesc.SampleDesc.Quality = 0;
	swapChainDesc.Windowed = TRUE;

	HRESULT hr = GraphicsEngine::getInstance()->mDXGIFactory->CreateSwapChain(device, &swapChainDesc, &mSwapChain);
	if (FAILED(hr)) return false;

	ID3D11Texture2D * mBackBuffer;
	hr = mSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&mBackBuffer);
	if (FAILED(hr)) return false;

	hr = device->CreateRenderTargetView(mBackBuffer, NULL, &mRenderTargetView);
	mBackBuffer->Release();
	if (FAILED(hr)) return false;

	return SUCCEEDED(hr);
}

bool SwapChain::release()
{
	if (mSwapChain) mSwapChain->Release();
	delete this;
	return true;
}
