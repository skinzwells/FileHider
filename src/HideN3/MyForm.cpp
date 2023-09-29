#include "MyForm.h"
#include <string>
#include <Windows.h>
#include <fstream>

using namespace HideN3;

[STAThread]

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm);
	return 0;
}
