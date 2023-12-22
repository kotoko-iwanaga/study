#pragma once

namespace Lab2Winforms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::DataGridView^ dataGridViewMatrix;
	protected:


	private: System::Windows::Forms::Button^ button_create;




	private: System::Windows::Forms::Label^ label2;

	private: System::Windows::Forms::Label^ label3;


	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ button_resize;
	private: System::Windows::Forms::Label^ label_result;
	private: System::Windows::Forms::Label^ label_alarm;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownM;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownN;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ выходToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ оПрограммеToolStripMenuItem;
	private: System::Windows::Forms::Button^ button_calculate;











	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dataGridViewMatrix = (gcnew System::Windows::Forms::DataGridView());
			this->button_create = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button_resize = (gcnew System::Windows::Forms::Button());
			this->label_result = (gcnew System::Windows::Forms::Label());
			this->label_alarm = (gcnew System::Windows::Forms::Label());
			this->numericUpDownM = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDownN = (gcnew System::Windows::Forms::NumericUpDown());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->выходToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->оПрограммеToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->button_calculate = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewMatrix))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownM))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownN))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(120, 28);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(113, 31);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Матрица";
			// 
			// dataGridViewMatrix
			// 
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridViewMatrix->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridViewMatrix->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridViewMatrix->DefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridViewMatrix->Location = System::Drawing::Point(35, 73);
			this->dataGridViewMatrix->Name = L"dataGridViewMatrix";
			this->dataGridViewMatrix->RowHeadersWidth = 51;
			this->dataGridViewMatrix->RowTemplate->Height = 24;
			this->dataGridViewMatrix->Size = System::Drawing::Size(314, 256);
			this->dataGridViewMatrix->TabIndex = 1;
			this->dataGridViewMatrix->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellContentClick);
			// 
			// button_create
			// 
			this->button_create->Location = System::Drawing::Point(522, 73);
			this->button_create->Name = L"button_create";
			this->button_create->Size = System::Drawing::Size(88, 57);
			this->button_create->TabIndex = 6;
			this->button_create->Text = L"Создать пустую матрицу";
			this->button_create->UseVisualStyleBackColor = true;
			this->button_create->Click += gcnew System::EventHandler(this, &MyForm::button_create_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(31, 362);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(98, 23);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Результат: ";
			// 
			// label3
			// 
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(445, 58);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(48, 31);
			this->label3->TabIndex = 9;
			this->label3->Text = L"M";
			this->label3->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->label3->Click += gcnew System::EventHandler(this, &MyForm::label3_Click);
			// 
			// label4
			// 
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(380, 58);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(52, 31);
			this->label4->TabIndex = 11;
			this->label4->Text = L"N";
			this->label4->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			// 
			// button_resize
			// 
			this->button_resize->Location = System::Drawing::Point(626, 73);
			this->button_resize->Name = L"button_resize";
			this->button_resize->Size = System::Drawing::Size(95, 57);
			this->button_resize->TabIndex = 12;
			this->button_resize->Text = L"Обновить текущую матрицу";
			this->button_resize->UseVisualStyleBackColor = true;
			this->button_resize->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label_result
			// 
			this->label_result->AutoSize = true;
			this->label_result->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_result->ForeColor = System::Drawing::Color::Indigo;
			this->label_result->Location = System::Drawing::Point(149, 362);
			this->label_result->Name = L"label_result";
			this->label_result->Size = System::Drawing::Size(108, 23);
			this->label_result->TabIndex = 13;
			this->label_result->Text = L"Отсутствует";
			this->label_result->Click += gcnew System::EventHandler(this, &MyForm::label5_Click);
			// 
			// label_alarm
			// 
			this->label_alarm->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_alarm->ForeColor = System::Drawing::Color::Brown;
			this->label_alarm->Location = System::Drawing::Point(391, 153);
			this->label_alarm->Name = L"label_alarm";
			this->label_alarm->Size = System::Drawing::Size(343, 99);
			this->label_alarm->TabIndex = 14;
			this->label_alarm->Text = L"Ваша матрица была изменена, нажмите кнопку обновить, чтобы пересчитать результат";
			this->label_alarm->Visible = false;
			// 
			// numericUpDownM
			// 
			this->numericUpDownM->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->numericUpDownM->Location = System::Drawing::Point(445, 92);
			this->numericUpDownM->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99, 0, 0, 0 });
			this->numericUpDownM->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDownM->Name = L"numericUpDownM";
			this->numericUpDownM->Size = System::Drawing::Size(48, 27);
			this->numericUpDownM->TabIndex = 15;
			this->numericUpDownM->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDownM->ValueChanged += gcnew System::EventHandler(this, &MyForm::numericUpDownM_ValueChanged);
			// 
			// numericUpDownN
			// 
			this->numericUpDownN->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->numericUpDownN->Location = System::Drawing::Point(384, 92);
			this->numericUpDownN->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99, 0, 0, 0 });
			this->numericUpDownN->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDownN->Name = L"numericUpDownN";
			this->numericUpDownN->Size = System::Drawing::Size(48, 27);
			this->numericUpDownN->TabIndex = 16;
			this->numericUpDownN->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->выходToolStripMenuItem,
					this->оПрограммеToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(748, 28);
			this->menuStrip1->TabIndex = 17;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// выходToolStripMenuItem
			// 
			this->выходToolStripMenuItem->Name = L"выходToolStripMenuItem";
			this->выходToolStripMenuItem->Size = System::Drawing::Size(67, 24);
			this->выходToolStripMenuItem->Text = L"Выход";
			this->выходToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::выходToolStripMenuItem_Click);
			// 
			// оПрограммеToolStripMenuItem
			// 
			this->оПрограммеToolStripMenuItem->Name = L"оПрограммеToolStripMenuItem";
			this->оПрограммеToolStripMenuItem->Size = System::Drawing::Size(118, 24);
			this->оПрограммеToolStripMenuItem->Text = L"О программе";
			this->оПрограммеToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::оПрограммеToolStripMenuItem_Click);
			// 
			// button_calculate
			// 
			this->button_calculate->Location = System::Drawing::Point(396, 272);
			this->button_calculate->Name = L"button_calculate";
			this->button_calculate->Size = System::Drawing::Size(88, 57);
			this->button_calculate->TabIndex = 18;
			this->button_calculate->Text = L"Вычислить";
			this->button_calculate->UseVisualStyleBackColor = true;
			this->button_calculate->Click += gcnew System::EventHandler(this, &MyForm::button_calculate_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(748, 477);
			this->Controls->Add(this->button_calculate);
			this->Controls->Add(this->numericUpDownN);
			this->Controls->Add(this->numericUpDownM);
			this->Controls->Add(this->label_alarm);
			this->Controls->Add(this->label_result);
			this->Controls->Add(this->button_resize);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button_create);
			this->Controls->Add(this->dataGridViewMatrix);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->menuStrip1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"Алгоритм для матриц";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewMatrix))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownM))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownN))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	}
	private: System::Void listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void выходToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void оПрограммеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void numericUpDownM_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button_create_Click(System::Object^ sender, System::EventArgs^ e);
	   private: void Show();
private: System::Void button_calculate_Click(System::Object^ sender, System::EventArgs^ e);
};



}
