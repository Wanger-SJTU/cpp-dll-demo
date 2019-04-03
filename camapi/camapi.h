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

//// 此类导出自 camapi.dll
//class CAMAPI_API Ccamapi {
//public:
//	Ccamapi(void);
//	// TODO:  在此添加您的方法。
//};
//
//extern CAMAPI_API int ncamapi;
//
//CAMAPI_API int fncamapi(void);

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

}
