#pragma once
#include <d3d11.h>

class DeviceContext;

class ConstantBuffer
{
public:
	ConstantBuffer();
	~ConstantBuffer();

	bool load(void* buffer, UINT sizeBuffer);
	void update(DeviceContext* context, void* buffer);
	bool release();

private:
	ID3D11Buffer* mBuffer;

private:
	friend class DeviceContext;
};

