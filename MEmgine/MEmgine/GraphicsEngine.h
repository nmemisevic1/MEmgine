#pragma once
#include <d3d11.h>
#include <d3dcompiler.h>

#include "SwapChain.h"
#include "DeviceContext.h"

class SwapChain;
class DeviceContext;
class VertexBuffer;

class GraphicsEngine
{
public:
	GraphicsEngine();
	~GraphicsEngine();

	// Initialize the graphics engine and directX11
	bool init();
	// Release all resources loaded
	bool release();

public:
	SwapChain* createSwapChain();
	DeviceContext* getImmediateDeviceContext();
	VertexBuffer* createVertexBuffer();

private:
	DeviceContext* mImmDeviceContext;

private:
	// The device
	ID3D11Device* mDevice;
	
	// The feature level
	D3D_FEATURE_LEVEL mFeatureLevel;

	IDXGIDevice *mDXGIDevice;

	IDXGIAdapter* mDXGIAdapter;

	IDXGIFactory* mDXGIFactory;


private:
	friend class SwapChain;
	friend class VertexBuffer;

public:
	static GraphicsEngine* getInstance();
	bool createShaders();
	bool setShaders();
	void getShaderBufferAndSize(void** bytecode, UINT* size);
};

