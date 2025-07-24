#pragma once
// dll 외부로 템플릿을 내보낼 때 발생하는 경고
//#pragma warning(disable: 4251)
// warning C4172: 지역 변수 또는 임시 의 주소를 반환하는 중
// RTTI 클래스가 인지하고 사용 증
#pragma warning(disable: 4172)

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#if BuildEngineDLL
#define Engine_API __declspec(dllexport)
#else
#define Engine_API __declspec(dllimport)
#endif 
