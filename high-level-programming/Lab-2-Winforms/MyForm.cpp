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

int M = 0, N = 0;
std::vector< std::vector<int> > matrix(N, std::vector<int>(M, 0));
//int** matrix;


void Lab2Winforms::MyForm::Show()
{
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++) {
			dataGridViewMatrix->TopLeftHeaderCell->Value = "Matrix";
			dataGridViewMatrix->Rows[i]->Cells[j]->Style->BackColor = Color::White;

			dataGridViewMatrix->Rows[i]->HeaderCell->Value = Convert::ToString(i + 1);
			dataGridViewMatrix->Columns[j]->HeaderCell->Value = Convert::ToString(j + 1);

			dataGridViewMatrix->Rows[i]->Cells[j]->Value = matrix[i][j];
		}
	}
}

//Обработчик кнопки Посчитать
System::Void Lab2Winforms::MyForm::button_calculate_Click(System::Object^ sender, System::EventArgs^ e) {
	bool error = false;
	if (M == 0 || N == 0) {
		MessageBox::Show("Вы не можете запустить алгоритм для несуществующей матрицы", "Ошибка ввода размера");
		return System::Void();
	}
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++) {
			try {
				matrix[i][j] = Convert::ToInt32(dataGridViewMatrix->Rows[i]->Cells[j]->Value);
			}
			catch (...) {
				error = true;
				dataGridViewMatrix->Rows[i]->Cells[j]->Style->BackColor = Color::Red;
			}
			
		}
	}
	if (error == false) {
		int result = countRows(matrix);
		if (result == -1) {
			label_result->Text = "Столбцы состоят из одного элемента\nНевозможно определить порядок убывания/неубывания столбца";
		}
		else {
			label_result->Text = Convert::ToString(result);
		}
	}
	else {
		label_result->Text = "Отсутствует";
		MessageBox::Show("Вы вместо числа написали строку, исправьте ввод\nНекорректный элемент выделен красным", "Ошибка ввода матрицы");
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
// обработка пересчета размера
System::Void Lab2Winforms::MyForm::button2_Click(System::Object^ sender, System::EventArgs^ e) {
	bool error = false;
	int M_old = M, N_old = N;
	M = Convert::ToInt32(numericUpDownM->Value);
	N = Convert::ToInt32(numericUpDownN->Value);

	if (dataGridViewMatrix->RowCount == 0) {
		MessageBox::Show("Вы не можете изменить несуществующую матрицу. Создайте её сначала.", "Ошибка переназначения матрицы");
		return System::Void();
	}
	for (int i = 0; i < N_old; i++) { // здесь были олды
		for (int j = 0; j < M_old; j++) {
			try {
				matrix[i][j] = Convert::ToInt32(dataGridViewMatrix->Rows[i]->Cells[j]->Value);
			}
			catch (...) {
				error = true;
				dataGridViewMatrix->Rows[i]->Cells[j]->Style->BackColor = Color::Red;
			}
		}
	}
	
	if (error == false) {
		resizeMatrix(matrix, N, M);
		dataGridViewMatrix->RowCount = matrix.size();
		dataGridViewMatrix->ColumnCount = matrix[0].size();

		label_result->Text = "Отсутствует";
		Show();

		dataGridViewMatrix->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
		dataGridViewMatrix->AutoResizeColumns();
	}
	else {
		M = M_old;
		N = N_old;
		label_result->Text = "Отсутствует";
		MessageBox::Show("Вы вместо числа написали строку, исправьте ввод\nНекорректный элемент выделен красным", "Ошибка ввода матрицы");
	}
}

System::Void Lab2Winforms::MyForm::выходToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	Application::Exit();
	return System::Void();
}

System::Void Lab2Winforms::MyForm::оПрограммеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show("Создана Виктором для лабораторной работы №2", "Информация о программе");
	return System::Void();
}
System::Void Lab2Winforms::MyForm::dataGridViewMatrix_CellValidating(System::Object^ sender, System::Windows::Forms::DataGridViewCellValidatingEventArgs^ e) {
	if (e->ColumnIndex == 0) { // Проверяем корректность ввода в определенном столбце
		// Получаем введенное значение
		String^ input = e->FormattedValue->ToString();

		// Проверяем корректность ввода (например, что значение не пустое и соответствует определенному формату)
		if (String::IsNullOrEmpty(input)) {
			e->Cancel = true; // Отменяем ввод, если значение некорректное
			MessageBox::Show("Значение не может быть пустым", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else if (!System::Text::RegularExpressions::Regex::IsMatch(input, "^[0-9]+$")) {
			e->Cancel = true;
			MessageBox::Show("Значение должно быть числом", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
}