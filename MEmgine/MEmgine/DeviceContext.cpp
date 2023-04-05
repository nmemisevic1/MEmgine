#include "DeviceContext.h"
#include "SwapChain.h"
#include "VertexBuffer.h"
#include "VertexShader.h"
#include "PixelShader.h"

DeviceContext::DeviceContext(ID3D11DeviceContext* deviceContext): mDeviceContext(deviceContext)
{
}

DeviceContext::~DeviceContext()
{
}

bool DeviceContext::Init()
{
	return false;
}

bool DeviceContext::Release()
{
	mDeviceContext->Release();
	delete this;
	return true;
}

void DeviceContext::setVertexBuffer(VertexBuffer* vertexBuffer)
{
	UINT stride = vertexBuffer->sizeVertex;
	UINT offset = 0;
	mDeviceContext->IASetVertexBuffers(0, 1, &vertexBuffer->mBuffer, &stride, &offset);
	mDeviceContext->IASetInputLayout(vertexBuffer->mLayout);
}

bool DeviceContext::clearRenderTargetColor(SwapChain* swapChain, float red, float green, float blue, float alpha)
{
	FLOAT color[4] = { red, green, blue, alpha };
	mDeviceContext->ClearRenderTargetView(swapChain->mRenderTargetView, color);
	mDeviceContext->OMSetRenderTargets(1, &swapChain->mRenderTargetView, NULL);

	return true;
}

void DeviceContext::drawTriangleList(UINT vertexCount, UINT startVertexIndex)
{
	mDeviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	mDeviceContext->Draw(vertexCount, startVertexIndex);
	
}

void DeviceContext::drawTriangleStrip(UINT vertexCount, UINT startVertexIndex)
{
	mDeviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);
	mDeviceContext->Draw(vertexCount, startVertexIndex);
}

void DeviceContext::setViewportSize(UINT width, UINT height)
{
	D3D11_VIEWPORT viewport;
	viewport.Width = (FLOAT)width;
	viewport.Height = (FLOAT)height;
	viewport.MinDepth = 0.0f;
	viewport.MaxDepth = 1.0f;
	viewport.TopLeftX = 0;
	viewport.TopLeftY = 0;

	mDeviceContext->RSSetViewports(1, &viewport);

}

void DeviceContext::setVertexShader(VertexShader* vertexShader)
{
	mDeviceContext->VSSetShader(vertexShader->mVertexShader, nullptr, 0);
}

void DeviceContext::setPixelShader(PixelShader* pixelShader)
{
	mDeviceContext->PSSetShader(pixelShader->mPixelShader, nullptr, 0);
}
