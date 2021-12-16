#include "stdafx.h"
#include <iostream>
#include <Windows.h>

using namespace std;
int main(){
	// First project for WriteProcessMemory and ReadProcessMemory
	DWORD pid;

	DWORD pointer = 0x00000;
	int pointerValue;

	int setCustomValue;

	HWND hwnd = FindWindowA(0, "WriteProcessMemory and ReadProcessMemory");
	GetWindowThreadProcessId(hwnd, &pid);
	HANDLE pHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);

	ReadProcessMemory(pHandle, (void*)pointer, &pointerValue, sizeof(pointer), 0); // READ VALUE

	while (pointerValue > 2000){
		// if the value of the pointer equals 2021
		// output: 2021
		cout << pointerValue << endl; 
	}

	if (pointerValue == 3000){
		// if the value of the pointer equals 3000
		// set pointer value to 100
		setCustomValue = 100;
		WriteProcessMemory(pHandle, (LPVOID)pointer, &setCustomValue, sizeof(int), 0); // WRITE VALUE
	}

	/* ******************************************************************************************************** */
	// Second project (for Test)

	// POINTER
	int *ptr;
	int x = 5;
	ptr = &x;

	SetConsoleTitle(TEXT("WriteProcessMemory and ReadProcessMemory"));

	cout << "initial value: " << *ptr << endl;
	while (*ptr < 200000){
		if (GetKeyState('A') & 0x8000){
			(*ptr)++;
			cout << "Value: " << *ptr << endl;
		}
	}
 }
