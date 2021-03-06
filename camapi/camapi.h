// 下列 ifdef 块是创建使从 DLL 导出更简单的
// 宏的标准方法。此 DLL 中的所有文件都是用命令行上定义的 CAMAPI_EXPORT
// 符号编译的。在使用此 DLL 的
// 任何其他项目上不应定义此符号。这样，源文件中包含此文件的任何其他项目都会将
// CAMAPI_API 函数视为自 DLL 导入，而此 DLL 则将用此宏定义的
// 符号视为是被导出的。
#ifdef CAMAPI_EXPORTS
#define CAMAPI_API __declspec(dllexport)
#else
#define CAMAPI_API __declspec(dllimport)
#endif

#include <iostream>
using namespace std;
namespace camapi
{
	extern "C" __declspec(dllexport) int __stdcall Add(int x, int y)
	{
		return x + y;
	}
	extern "C" __declspec(dllexport) int __stdcall Sub(int x, int y)
	{
		return x - y;
	}
	extern "C" __declspec(dllexport) int __stdcall Multiply(int x, int y)
	{
		return x * y;
	}
	extern "C" __declspec(dllexport) int __stdcall Divide(int x, int y)
	{
		return x / y;
	}


// 结构体指针
	struct TEST
	{
		int a;
		int b;
		TEST(int x, int y)
		{
			a = x;
			b = y;
		}

	};
	typedef TEST* PTEST;


	extern "C" __declspec(dllexport)  void _stdcall ceateTest(int x, int y, PTEST tmp)
	{
		tmp->a = x;
		tmp->b = y;

		cout << tmp->a << endl;
		cout << tmp->b << endl;
	}

	extern "C" __declspec(dllexport) int _stdcall callTestByPoint(PTEST tmp)
	{
		return tmp->a + tmp->b;
	}

	extern "C" __declspec(dllexport) void _stdcall getMat(unsigned char** tmp)
	{
		*tmp = (unsigned char*)malloc(sizeof(unsigned char) * 500*500);
		for (int i = 0; i < 500*500; i++)
		{
			*(*tmp + i) = (unsigned char)i % 0x0F + 60;
		}
	}
}
