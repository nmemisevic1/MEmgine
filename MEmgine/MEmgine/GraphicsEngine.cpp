#include "GraphicsEngine.h"
#include "SwapChain.h"
#include "DeviceContext.h"
#include "VertexBuffer.h"
#include "VertexShader.h"
#include "PixelShader.h"

#include <d3dcompiler.h>

GraphicsEngine::GraphicsEngine()
{
}

GraphicsEngine::~GraphicsEngine()
{
}

bool GraphicsEngine::init()
{
	D3D_DRIVER_TYPE driverTypes[] = { D3D_DRIVER_TYPE_HARDWARE, D3D_DRIVER_TYPE_WARP, D3D_DRIVER_TYPE_REFERENCE };
	D3D_FEATURE_LEVEL featureLevels[] = { D3D_FEATURE_LEVEL_11_0 };
	HRESULT result;
	ID3D11DeviceContext* mDeviceContext;

	for (UINT index = 0; index < ARRAYSIZE(driverTypes); index++)
	{
		HRESULT result = D3D11CreateDevice(NULL, driverTypes[index], NULL, 0, NULL, 0, D3D11_SDK_VERSION, &mDevice, NULL, &mDeviceContext);
		if (SUCCEEDED(result)) {
			mDevice->QueryInterface(__uuidof(IDXGIDevice), (void**)&mDXGIDevice);
			mDXGIDevice->GetParent(__uuidof(IDXGIAdapter), (void**)&mDXGIAdapter);
			mDXGIAdapter->GetParent(__uuidof(IDXGIFactory), (void**)&mDXGIFactory);

			this->mImmDeviceContext = new DeviceContext(mDeviceContext);
			return true;
		}
	}
	return false;
}

bool GraphicsEngine::release()
{
	if(mVertexShader) mVertexShader->Release();
	if(mPixelShader) mPixelShader->Release();

	//if (mBlob) mBlob->Release();
	if (mVertexShaderBlob) mVertexShaderBlob->Release();
	if (mPixelShaderBlob) mPixelShaderBlob->Release();

	if (mDXGIDevice) mDXGIDevice->Release();
	if (mDXGIAdapter) mDXGIAdapter->Release();
	if (mDXGIFactory) mDXGIFactory->Release();

	if (mImmDeviceContext) this->mImmDeviceContext->Release();
	if (mDevice) mDevice->Release();

	return true;
}

SwapChain* GraphicsEngine::createSwapChain()
{
	return new SwapChain();
}

DeviceContext* GraphicsEngine::getImmediateDeviceContext()
{
	return this->mImmDeviceContext;
}

VertexBuffer* GraphicsEngine::createVertexBuffer()
{
	return new VertexBuffer();
}

VertexShader* GraphicsEngine::createVertexShader(const void* shaderByteCode, size_t sizeByteCode)
{
	VertexShader* vertexShader = new VertexShader();
	if (!vertexShader->init(shaderByteCode, sizeByteCode)) {
		vertexShader->release();
		return nullptr;
	}
	return vertexShader;
}

PixelShader* GraphicsEngine::createPixelShader(const void* shaderByteCode, size_t sizeByteCode)
{
	PixelShader* pixelShader = new PixelShader();
	if (!pixelShader->init(shaderByteCode, sizeByteCode)) {
		pixelShader->release();
		return nullptr;
	}
	return pixelShader;
}

bool GraphicsEngine::compileVertexShader(const wchar_t* fileName, const char* entryPointName, void** shaderByteCode, size_t* byteCodeSize)
{
	ID3DBlob* errorBlob = nullptr;
	if (!SUCCEEDED(D3DCompileFromFile(fileName, nullptr, nullptr, entryPointName, "vs_5_0", 0, 0, &mBlob, &errorBlob))) {
		if (errorBlob) {
			errorBlob->Release();
			return false;
		}
	}
	*shaderByteCode = mBlob->GetBufferPointer();
	*byteCodeSize = mBlob->GetBufferSize();

	return true;
}

bool GraphicsEngine::compilePixelShader(const wchar_t* fileName, const char* entryPointName, void** shaderByteCode, size_t* byteCodeSize)
{
	ID3DBlob* errorBlob = nullptr;
	if (!SUCCEEDED(D3DCompileFromFile(fileName, nullptr, nullptr, entryPointName, "ps_5_0", 0, 0, &mBlob, &errorBlob))) {
		if (errorBlob) {
			errorBlob->Release();
			return false;
		}
	}
	*shaderByteCode = mBlob->GetBufferPointer();
	*byteCodeSize = mBlob->GetBufferSize();

	return true;
}

void GraphicsEngine::releaseCompiledShader()
{
	if (mBlob) mBlob->Release();
}

GraphicsEngine* GraphicsEngine::getInstance()
{
	static GraphicsEngine instance;
	return &instance;
}

