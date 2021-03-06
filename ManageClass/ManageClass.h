#pragma once

#include "NativeClass.h"
#include <msclr\marshal_cppstd.h>

using namespace System;

namespace ManageClass
{	
	

	[Serializable]
	public ref struct ClassInfoEx
	{
		Int32	count;
		String^ name;

		/*void UnmanagedPtr2ManagedStruct(IntPtr ptr)
		{
			ClassInfo *pStru = static_cast<ClassInfo *>(ptr.ToPointer());
			if (NULL == pStru)
				return;

			count = pStru->count;
			name = gcnew String(pStru->name.c_str());
		}*/
	};

	public ref class NativeClassEx
	{
		// TODO: 在此处添加此类的方法。
	private:
		NativeClass * m_pnClass;
	public:
		NativeClassEx(void)
		{
			this->m_pnClass = new NativeClass();
		}
		~NativeClassEx(void)
		{
			delete this->m_pnClass;
		}
		int GetCount(void)
		{
			return this->m_pnClass->GetCount();
		}
		void Increase(void)
		{
			this->m_pnClass->Increase();
		}
		void Clear(void)
		{
			this->m_pnClass->Clear();
		}
		void  getClassInfo(ClassInfoEx^ info)
		{
			info->count = this->m_pnClass->GetInfo().count;
			info->name  = gcnew String(this->m_pnClass->GetInfo().name.c_str());
		}
		void setBufferContent(String^ content, int count)
		{
			msclr::interop::marshal_context context;
			std::string standardString = context.marshal_as<std::string>(content);
			this->m_pnClass->setBufferContent(standardString.c_str(), count);
		}
		void getBufferContent()
		{
			this->m_pnClass->getBufferContent();
		}
		void printChar(Char chr)
		{
			this->m_pnClass->printChar(chr);
		}
	protected:
		!NativeClassEx(void)
		{
			delete this->m_pnClass;
		}
	};
}