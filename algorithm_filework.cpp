#include "Algorithm_Filework.h"

/// <summary>
/// �������, ����������� ���� �� � �������� ������ �������
/// </summary>
/// <returns> ���������� �������� ������ ��� ��������� �� ������, ���� �������� ������ �������� ������ </returns>
std::string Read_String_Without_Whitespace() {
	std::string input; //���������� ��� �������� ����������������� �����

	while (true) {
		std::getline(std::cin, input); //���� ������
		std::istringstream iss(input); //����������� ������ � input � ���������� iss, � ������� �������� ������ ��� ��������
		//����� ������� ��� ������� �� ������� �������.

		if (iss >> input && !isspace(input[0])) { //���������� �������� iss � input � ��������� �� ��� �� ������ ��������
			return input;                         //� input ������. ���� ������� ���, �� ���������� input, ��������� ������ �������
		}
		else {
			std::cout << "������: ������� ������ �� ������ ��������� ��������. ��������� ������� �����." << std::endl; //���� ������ ����,
		} //���������� ��������� �� ������.
	}
}

/// <summary>
/// ������� ��������� ��� ��������� ��������
/// </summary>
/// <returns> ���������� �������� ��������, ���� ��� ������������� </returns>
int Check_Int() {
	int tmp = 0;
	std::cin >> tmp; //���� �������� � ������������� ����������

	while (std::cin.fail() || tmp < 0) { //���� ����� ������� �� ������������� ��������, �� ����� ����� ���������
		std::cout << "������� ������������ ��������, ���������� ��� ���: "; //���� ������ ��� 1, �� �������� ����������� 
		std::cin.clear(); //������������ ���� ��������� ��������. ����� �� ������� ����
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //������� �����
		std::cin >> tmp; //����� ������ ��������
	}

	std::cin.ignore(std::numeric_limits<std::streamsize> ::max(), '\n'); //������� �����
	return tmp;
}

/// <summary>
/// �������-�������� ��������� ���������� �� ����
/// </summary>
/// <param name="FileName"> �������� �����</param>
/// <returns> ������� ���������� 1, ���� ���� ����������, � 0, ���� ���� �� ���������� </returns>
bool File_Exists(std::string FileName) //������� ���������� true ��� false � ����������� �� ����
{									   //���������� ���� ��� ���.
	const char* path = FileName.c_str(); //����������� �������� ���������� ����-��������������� ������
	//��� ����, ����� �������� ��������������� ������ ������ ������.
	int a = 0;
	a = _access(path, 0);

	return  (!a ? true : false);//��������� �������� � ������� ����������
}

/// <summary>
/// �������-�������� ��������� �������� �� ���� ������ ��� ������
/// </summary>
/// <param name="FileName"> �������� �����</param>
/// <returns>������� ���������� 1, ���� ���� �������� ������ ��� ������, � 0, ���� ���� �� �������� ������ ��� ������</returns>
bool Only_Read(std::string FileName) { //������� ���������� true ��� false � ����������� �� ����
	const char* path = FileName.c_str();//�������� �� ���� ������ ��� ������.
	if (_access(path, 2) == -1) {
		return true;
	}
	else
		return false;
}

/// <summary>
/// �������-�������� ���������� �������� ����� �� ������� ����������������� ��������, ���������� �������� ����������
/// </summary>
/// <param name="FileName"> �������� ����� </param>
/// <returns> ������� ���������� 1, ���� �������� ����� ���������������, � 0, ���� �������� ����� ������������������ </returns>
bool Is_Reserved_Filename(std::string FileName) {
	std::string Reserved_Names[Quantity_Reserved_Names] = { "con", "prn" , "aux" , "nul" , "com1" , "com2" , "com3" , "com4" , "com5" , "com6" , "com7" , "com8" , "com9" ,
	"lpt1", "lpt2", "lpt3", "lpt4", "lpt5", "lpt6", "lpt7", "lpt8", "lpt9" };
	//����������������� ����� ������������ �������� ��� �������� ������ ��� ������������, �� ������ ������������
	//��� �������� ������.
	size_t pos = FileName.find_first_of("."); //������� ��������� ����� � �������� �����
	if (pos != std::string::npos) { //���� � ����� ����� ���� �����
		FileName = FileName.substr(0, pos); //�� �� ����������� ������ �����, ���� �������� ������ ��������
	}

	for (int i = 0; i < Quantity_Reserved_Names; i++) { //� ����� ��������� �������� �����
		if (_stricmp(FileName.c_str(), Reserved_Names[i].c_str()) == 0) { //�� ������� ����������� ��������
			return true; //���� �������� ���������, �� ������������ ����, � ������� ���������� true
		} //��� ������, ��� �������� ����� - �����������������
	}
	return false; //���� �������� �������������������, �� ������������ false
}

/// <summary>
/// �������-�������� ��������� ��������� �� ���������� � �����
/// </summary>
/// <param name="filename"> �������� ����� </param>
/// <returns> ���������� 1, ���� .txt ���� � �������� �����, � 0, ���� ����� ���������� ��� � ����� </returns>
bool Txt_Check(const std::string& filename) {
	std::string extension = ".txt";
	size_t strLength = filename.length(); //����� ������������� �������� �����
	size_t extLength = extension.length(); //����� .txt

	if (strLength < extLength) { //���� ����� �������� ����� ������, ��� .txt
		std::cout << "���� ������ ���� ���������� ����������." << std::endl; //�� ����� ������������, ���
		return false; //���� �� ���������� ����������.
	}

	if (strLength == extLength) { //���� ����� �����, �� ����� ������������,
		std::cout << "������ ������ �����!" << std::endl; //��� ������������ ��� ������ ��������.
		return false;
	}

	std::string end = filename.substr(strLength - extLength, extLength); //���������� �������� �������� �����,
	//������� ���������� � ������� ����� ������ ����� ����� �������,
	//� ���� ������� �������� �� ��������, ������� ������� ����� .txt

	return end.compare(extension) == 0; //���������� �������� ��������� .txt � �������� �����. ����� ��� ���������
	//������� ���������� 0.
	//��������� �������� 0 � 0 ����� 1
}

/// <summary>
/// �������-�������� ��������� ���������� �� � �������� ������ ����������� ������
/// </summary>
/// <param name="filename"> �������� �����</param>
/// <returns> ���������� 1, ���� � �������� ����� ���������� ����������� ������, � 0, ���� ����������� �������� � �������� �� ���������� </returns>
bool Filename_Forbidden_Characters_Check(const std::string& filename) {//�������� �������� �� ����������� �������
	std::string Reserved_Characters[Quantity_Forbidden_Characters] = { "/", "\\", "|", ":", "*", "?", "\"", "<", ">" };

	for (int i = 0; i < Quantity_Forbidden_Characters; i++) { //� ����� ������� ������� ������������ ������� � ���������� ���������

		if (filename.find(Reserved_Characters[i]) != std::string::npos) { //���� ������� ����� �������
			return true; //���������� true
		}
	}
	return false; //���� ����������� �������� �� ������� � �������� ����� ���������� false
}

/// <summary>
/// ������� ���������� ������ �������� ����� �� ��������� ���� �����.
/// </summary>
/// <param name="path"> ���� � ����� </param>
/// <returns> �������� �����</returns>
std::string Get_File_Name(const std::string& path) {
	size_t pos = path.find_last_of("\\"); // ���� ��������� ������ '/' ��� '\'

	if (pos != std::string::npos) { // ���� ������ ������
		return path.substr(pos + 1); // ���������� ��� ����� ����� ���������� �������
	}
	return path; // ���� ������ �� ������, ���������� �������� ����
}