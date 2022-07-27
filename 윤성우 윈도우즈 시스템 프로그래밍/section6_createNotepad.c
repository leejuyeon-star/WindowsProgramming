// Section 6 명령 프롬프트 프로젝트 기능 추가
// 메모장(notepad.exe) 실행하기

#include <stdio.h>
#include <tchar.h>
#include <windows.h>

#define DIR_LEN MAX_PATH+1      //정보가 저장될 메모리 버퍼의 크기

int _tmain(int argc, TCHAR* argv[]){
    STARTUPINFO si = {0, };     //STARTUPINFO 구조체 초기화
    PROCESS_INFORMATION pi;      //PROCESS_INFOMATION 구조체 선언

    si.cb = sizeof(si);     //STARTUPINFO 구조체 변수의 크기
    TCHAR command[] = _T("notepad.exe");       //실행할 파일명 or 완전경로
    TCHAR cDir[DIR_LEN];       //메모리 버퍼
    BOOL state;


    SetCurrentDirectory("C:\\WINDOWS\\system32");       //시스템 디렉터리(표준 검색경로)로 경로 수정
    GetCurrentDirectory(DIR_LEN, cDir);     //현 디렉토리 위치 확인. (인수 : (정보가 저장될 메모리버퍼의 크기, 메모리 버퍼의 포인터))


    CreateProcess(
                    NULL,     //생성할 프로세스명 or 경로, NULL이면 현 디렉터리에서 찾음
                    command,	//위가 NULL이면 이번 값을 통해 생성할 프로세스 이름과 인자까지 함께 전달가능, 문자열불가, 변수만 가능
                    NULL,
                    NULL, 
                    TRUE, 
                    0,
                    NULL, 
                    NULL, 
                    &si, 	//STARTUPINFO 구조체 변수의 주소값
                    &pi		//LPPROCESS_INFORMATION 구조체 변수의 주소값
    );   //CreateProcess

    if(state!=0)
	_fputts(_T("Create OK! \n"), stdout);
    else
	_fputts(_T("Create Error! \n"), stdout);

    return 0;
}
