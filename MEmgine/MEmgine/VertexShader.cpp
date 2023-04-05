#include "VertexShader.h"
#include "GraphicsEngine.h"

VertexShader::VertexShader()
{
}

VertexShader::~VertexShader()
{
}

bool VertexShader::init(const void* shaderByteCode, size_t sizeByteCode)
{
	GraphicsEngine* engine = GraphicsEngine::getInstance();

	if (!SUCCEEDED(engine->mDevice->CreateVertexShader(shaderByteCode, sizeByteCode, nullptr, &mVertexShader))) return false;

	return true;
}

bool VertexShader::release()
{
	mVertexShader->Release();
	delete this;
	return true;
}
