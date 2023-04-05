#include "PixelShader.h"
#include "GraphicsEngine.h"

PixelShader::PixelShader()
{
}

PixelShader::~PixelShader()
{
}

bool PixelShader::init(const void* shaderByteCode, size_t sizeByteCode)
{
	GraphicsEngine* engine = GraphicsEngine::getInstance();

	if (!SUCCEEDED(engine->mDevice->CreatePixelShader(shaderByteCode, sizeByteCode, nullptr, &mPixelShader))) return false;

	return true;
}

bool PixelShader::release()
{
	mPixelShader->Release();
	delete this;
	return true;
}
