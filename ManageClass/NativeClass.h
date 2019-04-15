#pragma once
#include <string>


public struct ClassInfo
{
	std::string name;
	int count;
};

//_declspec(dllexport)字段其实可要可不要
class NativeClass
{
private:
	int nCount;
	ClassInfo mClassInfo;
	char* buffer;
	int buffer_size;
public:
	NativeClass(void)
	{
		this->nCount = 0;
		this->mClassInfo.count = 0;
		this->mClassInfo.name = "asfa";
		buffer = new char[256];
		buffer_size = 256;
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
	void setBufferContent(const char* content, int content_size)
	{
		for (int i = 0; i < content_size+1; i++)
		{
			buffer[i] = content[i];
		}
	}

	void printChar(const char chr)
	{
		printf("%c", chr);
	}
	void getBufferContent()
	{
		int i = 0;
		while (buffer[i])
		{
			printf("%c",buffer[i++]);
		}
	}
	ClassInfo GetInfo()
	{
		return this->mClassInfo;
	}
};