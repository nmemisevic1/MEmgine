#pragma once
#include <d3d11.h>


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
	static GraphicsEngine* getInstance();

private:
	// The device
	ID3D11Device* mDevice;
	
	// The feature level
	D3D_FEATURE_LEVEL mFeatureLevel;
	
	// The device context
	ID3D11DeviceContext* mDeviceContext;


};

