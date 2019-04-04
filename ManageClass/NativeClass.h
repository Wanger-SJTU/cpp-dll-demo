#pragma once

//_declspec(dllexport)字段其实可要可不要
class _declspec(dllexport) NativeClass
{
private:
	int nCount;
public:
	NativeClass(void)
	{
		this->nCount = 0;
	}

	~NativeClass(void)
	{}
	int GetCount(void)
	{
		return this->nCount;
	}
	void Increase(void)
	{
		this->nCount++;
	}
	void Clear(void)
	{
		this->nCount = 0;
	}
};