#pragma once

#include "Core.h"


/// <summary>
/// RunTime-Type-Information: 상속 관계에 있는 클래스 간의 동적(실행중에) 형변환을 빠르게 하기 위해 사용하는 클래스.
/// </summary>
class Engine_API RTTI
{
public:
	virtual const size_t& TypeIdInstance() const = 0; // RTTI 끼리 비교 방지

	virtual bool Is(const size_t id) const
	{
		return false;
	}

	template<typename T>
	T* As()
	{
		if (Is(T::TypeIdClass()))
		{
			return (T*)this;
		}

		return nullptr;
	}

	template<typename T>
	const T* As() const
	{
		if (Is(T::TypeIdClass()))
		{
			return (T*)this;
		}

		return nullptr;
	}
};

// 자손 타입, 부모타입
#define RTTI_DECLARATIONS(Type, ParentType)												\
public:																					\
	using super = ParentType;															\ // 언리얼의 Super도 이와 같이 동작
	virtual const size_t& TypeIdInstance() const { return Type::TypeIdClass(); }		\
	static const size_t TypeIdClass()													\ // 메모리 주소의 사용
	{																					\
		static int runTimeTypeId = 0;													\
		return reinterpret_cast<size_t>(&runTimeTypeId);								\
	}																					\
	virtual bool Is(const size_t id) const												\
	{																					\
		if (id == TypeIdClass())														\
		{																				\
			return true;																\
		}																				\
		else																			\
		{																				\
			return ParentType::Is(id);													\
		}																				\
	}