# ft_printf

## 가변 인자 variadic arguments
>***
>#include <stdarg.h>
>***
>
>[형식]  
>반환값자료형 함수이름(자료형 고정매개변수, ...)
>
>+ va_list :  가변 인자 목록. 가변 인자의 메모리 주소를 저장함
>+ va_start : 가변 인자를 가져올 수 있도록 포인터를 설정
>+ va_arg : 가변 인자 포인터에서 특정 자료형 크기만큼 값을 가져옴
>+ va_end : 가변 인자 처리가 끝났을 때 포인터를 NULL로 초기화

## Mandatory Part
***
int ft_printf(const char *, ...);
***
>- 실제 printf처럼 버퍼 관리를 수행해서는 안된다.
>- %c %s %p %d %i %u %x %X
>- 모든 서식문자에서 -0.* 플래그와 최소 필드 너비의 조합을 어떤 조합도 처리할 것입니다.
>- 실제 printf 함수와 비교될 것이다.

## Bonus Part
>- 다음 중 하나 이상의 변환을 구현하세요. nfge
>- 다음 중 하나 이상의 플래그를 구현하세요. l ll h hh
>- 다음의 모든 플래그를 구현하세요. # +
