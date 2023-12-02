#include "MyForm.h"
#include "string"
#include "vector"
#include "msclr\marshal_cppstd.h"
using namespace System;
using namespace System::Windows::Forms;
int main(array<String^> ^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Проект1::MyForm form;
	Application::Run(%form);
}
