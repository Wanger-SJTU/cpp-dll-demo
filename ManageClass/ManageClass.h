#pragma once

#include "NativeClass.h"

using namespace System;

namespace ManageClass
{
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
	protected:
		!NativeClassEx(void)
		{
			delete this->m_pnClass;
		}
	};
}