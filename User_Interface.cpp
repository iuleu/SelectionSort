#include "User_Interface.h"
#include "Input_From_File.h"
#include "Output_Into_File.h"
#include "Sort.h"
#include "Algorithm_Filework.h"

/// <summary>
/// ������� ������� ��������� ��������� ���� � ��, ������� ������, ������� ������������ ������, ��������� ������������ ������,
/// ��������� ����������, �������� ������� ����
/// </summary>
void Print_Menu()
{
	system("cls");
	std::cout << "���� ������, ����� ������. 425 ������." << std::endl << "������������ ������ �2. ������� 12." << std::endl;
	std::cout << "���������� �������/Selection sort." << std::endl;
	std::cout << "------------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "�������� ������ ����� ����:" << std::endl << "1 - ������ ������ ���������." << std::endl << "2 - ��������� ��������� �����." << std::endl
		<< "3 - ��������� ������ ���������" << std::endl << "> ";
}

/// <summary>
/// ������� ����� �������� ������� �� �����, ���������� �������, ������ ����������, ����� ������ ���������� ������ ��������� � ��������� ����
/// </summary>
/// <param name="vect"> �������� ������, �� �������� ���������� �������� </param>
/// <param name="copyVect"> ������-�����, ������� ����� ������������� </param>
void Start_Programm(std::vector <int>& vect, std::vector <int>& copyVect) {

	Input_From_File(vect);
	copyVect = vect; //�������� ������
	SelectionSort(copyVect); //��������� �����

	std::cout << "�������� ������: " << std::endl;
	for (int i = 0; i < vect.size(); i++) {
		std::cout << vect[i] << ' ';
	}
	std::cout << std::endl;
	std::cout << "������������� ������: " << std::endl;
	for (int i = 0; i < copyVect.size(); i++) {
		std::cout << copyVect[i] << ' ';
	}
	std::cout << std::endl;

	Output_Into_File(vect, copyVect);
}

/// <summary>
/// ������� ������� ������� ����
/// </summary>
void Main_Menu()
{
	//������� ��������� ������� ����������� ����
	std::vector <int> vect;
	std::vector <int> copyVect;
	setlocale(LC_ALL, "RU");
	int user�hoise = 0;

	do {
		system("cls"); //�������� �������
		Print_Menu();
		user�hoise = Check_Int();
		switch (user�hoise) {
		case StartProgramm:
			Start_Programm(vect, copyVect);
			break;
		case StopProgramm:
			break;
		default:
			std::cout << "������ ������ ��� � ����, ���������� ��� ���" << std::endl;
			break;
		}

		if (user�hoise != StopProgramm)	system("pause");

	} while (user�hoise != StopProgramm);
}
