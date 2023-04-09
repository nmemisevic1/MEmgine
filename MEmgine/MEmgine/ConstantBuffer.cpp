#include "ConstantBuffer.h"
#include "GraphicsEngine.h"
#include "DeviceContext.h"

ConstantBuffer::ConstantBuffer()
{
}

ConstantBuffer::~ConstantBuffer()
{
}

bool ConstantBuffer::load(void* buffer, UINT sizeBuffer)
{
	if (mBuffer) mBuffer->Release();

	D3D11_BUFFER_DESC bufferDesc = {};
	bufferDesc.Usage = D3D11_USAGE_DEFAULT;
	bufferDesc.ByteWidth = sizeBuffer;
	bufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	bufferDesc.CPUAccessFlags = 0;
	bufferDesc.MiscFlags = 0;

	D3D11_SUBRESOURCE_DATA initData = {};
	initData.pSysMem = buffer;

	GraphicsEngine* engine = GraphicsEngine::getInstance();
	if (FAILED(engine->mDevice->CreateBuffer(&bufferDesc, &initData, &mBuffer))) return false;



	return true;
}

void ConstantBuffer::update(DeviceContext* context, void* buffer)
{
	context->mDeviceContext->UpdateSubresource(mBuffer, NULL, NULL, buffer, NULL, NULL);

}

bool ConstantBuffer::release()
{
	if (mBuffer) mBuffer->Release();
	delete this;
	return true;
}
