#include "VertexBuffer.h"
#include "GraphicsEngine.h"

VertexBuffer::VertexBuffer() : mBuffer(0), mLayout(0)
{
}

VertexBuffer::~VertexBuffer()
{
}

bool VertexBuffer::load(void* listVertices, UINT sizeVertex, UINT sizeList, void* shaderByteCode, UINT sizeByteShader) 
{
	if(mBuffer) mBuffer->Release();
	if(mLayout) mLayout->Release();

	D3D11_BUFFER_DESC bufferDesc = {};
	bufferDesc.Usage = D3D11_USAGE_DEFAULT;
	bufferDesc.ByteWidth = sizeVertex * sizeList;
	bufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bufferDesc.CPUAccessFlags = 0;
	bufferDesc.MiscFlags = 0;

	D3D11_SUBRESOURCE_DATA initData = {};
	initData.pSysMem = listVertices;

	this->sizeVertex = sizeVertex;
	this->sizeList = sizeList;


	GraphicsEngine* engine = GraphicsEngine::getInstance();
	if (FAILED(engine->mDevice->CreateBuffer(&bufferDesc, &initData, &mBuffer))) return false;

	D3D11_INPUT_ELEMENT_DESC layout[] =
	{
		// SemanticName, SemanticIndex, Format, InputSlot, AlignedByteOffset, InputSlotClass, InstanceDataStepRate
		{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
//		{ "COLOR", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0 },
	};

	UINT sizeLayout = ARRAYSIZE(layout);

	if (FAILED(engine->mDevice->CreateInputLayout(layout, sizeLayout, shaderByteCode, sizeByteShader, &mLayout))) return false;


	return true;
}

bool VertexBuffer::release()
{
	mLayout->Release();
	mBuffer->Release();
	delete this;
	return true;
}
