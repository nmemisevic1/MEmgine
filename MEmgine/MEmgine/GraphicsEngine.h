#pragma once
#include <d3d11.h>

class SwapChain;
class DeviceContext;
class VertexBuffer;
class VertexShader;
class PixelShader;

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
	VertexShader* createVertexShader(const void* shaderByteCode, size_t sizeByteCode);
	PixelShader* createPixelShader(const void* shaderByteCode, size_t sizeByteCode);
	
	
public:
	bool compileVertexShader(const wchar_t* fileName, const char* entryPointName, void** shaderByteCode, size_t* byteCodeSize);
	bool compilePixelShader(const wchar_t* fileName, const char* entryPointName, void** shaderByteCode, size_t* byteCodeSize);
	void releaseCompiledShader();

private:
	DeviceContext* mImmDeviceContext;

private:
	ID3D11Device* mDevice;
	D3D_FEATURE_LEVEL mFeatureLevel;
	IDXGIDevice *mDXGIDevice;
	IDXGIAdapter* mDXGIAdapter;
	IDXGIFactory* mDXGIFactory;

private:
	ID3DBlob* mBlob = nullptr;
	ID3DBlob* mVertexShaderBlob = nullptr;
	ID3DBlob* mPixelShaderBlob = nullptr;
	ID3D11VertexShader* mVertexShader = nullptr;
	ID3D11PixelShader* mPixelShader = nullptr;
	
private:
	friend class SwapChain;
	friend class VertexBuffer;
	friend class VertexShader;
	friend class PixelShader;

public:
	static GraphicsEngine* getInstance();
};

