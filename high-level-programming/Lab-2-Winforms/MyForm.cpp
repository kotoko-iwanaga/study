#include "MyForm.h"
#include "Functions.h"
#include <vector>
#include <string>

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]


void main(array< String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Lab2Winforms::MyForm form;
	Application::Run(% form);
}

int M, N;
std::vector< std::vector<int> > matrix(N, std::vector<int>(M, 0));
//int** matrix;


void Lab2Winforms::MyForm::Show()
{
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++) {
			dataGridViewMatrix->TopLeftHeaderCell->Value = "N/M";


			dataGridViewMatrix->Rows[i]->HeaderCell->Value = Convert::ToString(i + 1);
			dataGridViewMatrix->Columns[j]->HeaderCell->Value = Convert::ToString(j + 1);

			dataGridViewMatrix->Rows[i]->Cells[j]->Value = matrix[i][j];
		}
	}
}

System::Void Lab2Winforms::MyForm::button_calculate_Click(System::Object^ sender, System::EventArgs^ e) {
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++) {
			matrix[i][j] = Convert::ToInt32(dataGridViewMatrix->Rows[i]->Cells[j]->Value);
		}
	}
	int result = countRows(matrix);
	if (result == -1) {
		label_result->Text = "Столбцы состоят из одного элемента\nНевозможно определить порядок убывания/неубывания столбца";
	}
	else {
		label_result->Text = Convert::ToString(result);
	}
	
}

System::Void Lab2Winforms::MyForm::button_create_Click(System::Object^ sender, System::EventArgs^ e) {
	M = Convert::ToInt32(numericUpDownM->Value);
	N = Convert::ToInt32(numericUpDownN->Value);

	resizeMatrix(matrix, N, M);
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++) {
			matrix[i][j] = 0;
		}
	}

	dataGridViewMatrix->RowCount = N;
	dataGridViewMatrix->ColumnCount = M;
	label_result->Text = "Отсутствует";
	Show();

	dataGridViewMatrix->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
	dataGridViewMatrix->AutoResizeColumns();
	
}

System::Void Lab2Winforms::MyForm::button2_Click(System::Object^ sender, System::EventArgs^ e) {
	int M_old = M, N_old = N;
	M = Convert::ToInt32(numericUpDownM->Value);
	N = Convert::ToInt32(numericUpDownN->Value);

	if (dataGridViewMatrix->RowCount == 0) {
		MessageBox::Show("Вы не можете изменить несуществующую матрицу. Создайте её сначала.", "Ошибка переназначения матрицы");
		return System::Void();
	}
	for (int i = 0; i < N_old; i++) {
		for (int j = 0; j < M_old; j++) {
			matrix[i][j] = Convert::ToInt32(dataGridViewMatrix->Rows[i]->Cells[j]->Value);
		}
	}
	resizeMatrix(matrix, N, M);
	dataGridViewMatrix->RowCount = matrix.size();
	dataGridViewMatrix->ColumnCount = matrix[0].size();
		
	label_result->Text = "Отсутствует";
	Show();

	dataGridViewMatrix->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
	dataGridViewMatrix->AutoResizeColumns();
}

System::Void Lab2Winforms::MyForm::выходToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	Application::Exit();
	return System::Void();
}

System::Void Lab2Winforms::MyForm::оПрограммеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show("Создана Виктором для лабораторной работы №2", "Информация о программе");
	return System::Void();
}