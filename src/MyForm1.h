#pragma once
//#include <fstream>
#include <msclr\marshal.h>
#include <msclr/marshal_cppstd.h>
#include <msclr/marshal_atl.h>
#include <msclr/marshal_windows.h>
#include <vcclr.h>
//#include <filesystem>
#include "DataBank.h"
//namespace fs = std::filesystem;
namespace HideN3 {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace msclr::interop;

	/// <summary>
	/// Summary for MyForm1
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:
		MyForm1()
		{
			InitializeComponent();
			
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::ListBox^ listBox1;




	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(3, 457);
			this->button1->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(158, 27);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Hide file";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm1::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(169, 457);
			this->button2->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(163, 27);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Close";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm1::button2_Click);
			// 
			// listBox1
			// 
			this->listBox1->AllowDrop = true;
			this->listBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 16;
			this->listBox1->Location = System::Drawing::Point(-3, -1);
			this->listBox1->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(335, 436);
			this->listBox1->TabIndex = 2;
			this->listBox1->DoubleClick += gcnew System::EventHandler(this, &MyForm1::listBox1_DoubleClick);
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(331, 493);
			this->ControlBox = false;
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.249999F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->MaximizeBox = false;
			this->Name = L"MyForm1";
			this->Text = L"FileHider";
			this->Load += gcnew System::EventHandler(this, &MyForm1::MyForm1_Load);
			this->ResumeLayout(false);

		}
		auto Hider() {
			marshal_context^ context = gcnew marshal_context();

			DataBank db;

			String^ path = db.FilePath + "\\" + listBox1->SelectedItem;
			//String^ path_file = path + "\\" + listBox1->SelectedItem;

			pin_ptr<const wchar_t> wfilename = PtrToStringChars(path);

			//std::string converted_filename = marshal_as< std::string >(path);
			std::string converted_filename2 = marshal_as< std::string >(path);

			//const char* wfilename1 = context->marshal_as< const char* >(path);

			String^ cd = "cd " + path;

			std::string hidefile = "attrib +h +s \"" + converted_filename2 + "\"";
			std::string showfile = "attrib -h -s \"" + converted_filename2 + "\"";

			const char* cfilename = context->marshal_as< const char* >(cd);

			int attr = GetFileAttributes(wfilename);
			if ((attr & FILE_ATTRIBUTE_HIDDEN) == 0) {
				system(cfilename);
				system(hidefile.c_str());
			}
			else {
				System::Windows::Forms::DialogResult dr = MessageBox::Show("Раскрыть файл?", "Файл уже скрыт!", MessageBoxButtons::YesNo);
				if (dr == System::Windows::Forms::DialogResult::Yes)
				{
					system(cfilename);
					system(showfile.c_str());
				}
			}
		}
#pragma endregion
	private: System::Void MyForm1_Load(System::Object^ sender, System::EventArgs^ e) {
		this->Opacity = 0.9;
		DataBank db;

		String^ filename1 = db.FilePath;

		auto di = gcnew DirectoryInfo(filename1);
		for each (auto f in di->GetFiles("*")) listBox1->Items->Add(f->Name);

	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		Hider();
	}
private: System::Void listBox1_DoubleClick(System::Object^ sender, System::EventArgs^ e) {
		Hider();
}
};
}
