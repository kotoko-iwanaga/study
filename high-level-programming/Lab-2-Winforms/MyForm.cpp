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


System::Void Lab2Winforms::MyForm::dataGridViewMatrix_CellBeginEdit(System::Object^ sender, System::Windows::Forms::DataGridViewCellCancelEventArgs^ e) {
	label_alarm->ForeColor = Color::Red;
	label_alarm->Text = "���� ������� ���� ��������, ������� ������ ��������, ����� ����������� ���������";
}



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

//���������� ������ ���������
System::Void Lab2Winforms::MyForm::button_calculate_Click(System::Object^ sender, System::EventArgs^ e) {
	bool error = false;
	if (M != 0 && N != 0) {
		label_alarm->ForeColor = Color::Black;
		label_alarm->Text = "��������� ������� �� ����������";
	}
	if (M == 0 || N == 0) {
		MessageBox::Show("�� �� ������ ��������� �������� ��� �������������� ������� \n�������� � �������.", "������ ����� �������");
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
		Show();
		if (result == -1) {
			label_result->Text = "������� ������� �� ������ ��������\n���������� ���������� ������� ��������/���������� �������";
		}
		else {
			label_result->Text = Convert::ToString(result);
		}
	}
	else {
		label_result->Text = "�����������";
		MessageBox::Show("�� ������ ����� �������� ������, ��������� ����\n������������ ������� ������� �������", "������ ����� �������");
	}
	
}
System::Void Lab2Winforms::MyForm::noErrorSize() {
	label_sizeAlarm->ForeColor = Color::Black;
	label_sizeAlarm->Text = "��������� ������� ������� �� ����������";
}
System::Void Lab2Winforms::MyForm::noErrorEdit() {
	label_alarm->ForeColor = Color::Black;
	label_alarm->Text = "��������� � ������� �� ����������";
}
System::Void Lab2Winforms::MyForm::throwErrorEdit() {
	label_alarm->ForeColor = Color::Red;
	label_alarm->Text = "���� ������� ���� ��������, ������� ������ ��������, ����� ����������� ���������";
}

System::Void Lab2Winforms::MyForm::button_create_Click(System::Object^ sender, System::EventArgs^ e) {
	noErrorSize();
	noErrorEdit();
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
	label_result->Text = "�����������";
	Show();

	dataGridViewMatrix->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
	dataGridViewMatrix->AutoResizeColumns();
	
}
// ��������� ��������� �������
System::Void Lab2Winforms::MyForm::button2_Click(System::Object^ sender, System::EventArgs^ e) {
	bool error = false;
	int M_old = M, N_old = N;

	noErrorSize();
	throwErrorEdit();
	M = Convert::ToInt32(numericUpDownM->Value);
	N = Convert::ToInt32(numericUpDownN->Value);

	if (dataGridViewMatrix->RowCount == 0) {
		MessageBox::Show("�� �� ������ �������� �������������� �������. �������� � �������.", "������ �������������� �������");
		M = M_old; N = N_old;
		return System::Void();
	}
	for (int i = 0; i < N_old; i++) { // ����� ���� ����
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

		label_result->Text = "�����������";
		Show();

		dataGridViewMatrix->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
		dataGridViewMatrix->AutoResizeColumns();
	}
	else {
		M = M_old;
		N = N_old;
		label_result->Text = "�����������";
		MessageBox::Show("�� ������ ����� �������� ������, ��������� ����\n������������ ������� ������� �������", "������ �������������� �������");
	}
}


System::Void Lab2Winforms::MyForm::�����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	Application::Exit();
	return System::Void();
}

System::Void Lab2Winforms::MyForm::����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show("������� �������� ��� ������������ ������ �2", "���������� � ���������");
	return System::Void();
}

System::Void Lab2Winforms::MyForm::numericUpDownM_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	label_sizeAlarm->ForeColor = Color::Red;
	label_sizeAlarm->Text = "������� ������� ���� ��������, ������� �������� ��� �������� ����� �������";
	return System::Void();
}
