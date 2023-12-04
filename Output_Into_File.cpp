#include "Output_Into_File.h"
#include "Algorithm_Filework.h"

/// <summary>
/// ������� ������ ���������� ������ ��������� � ��������� ����
/// </summary>
/// <param name="vect"> �������� ������ </param>
/// <param name="vect2"> ������������� ������-����� </param>
void Output_Into_File(std::vector<int>& vect, std::vector<int>& vect2)
{
	std::string fileName;
	std::ofstream file;
	int saveChoise = 0; //����������, �������� ����� '��������� ��� ���' ������������
	int saveMethod = 0; //����� ���������� (���������� � �����, ����������, ����� ������� �����) ����� ����� ����
	int fileMethod = 0; //����������, �������� ����� "������� �� ���� ��� ���", ���� ��������� ����� �� ����������.

	do {
		std::cout << "1 - ��������� � ����." << std::endl << "2 - ���������� ��� ����������." << std::endl << "> ";
		saveChoise = Check_Int();
		switch (saveChoise) {
		case Save:

			while (true) {
				std::cout << "������� ���� � ����� ��� ����������:" << std::endl << "> ";
				fileName = Read_String_Without_Whitespace();
				//������ ������� ����� ��� ����� ����������� �� ������� ���������� .txt, �������� �� ��� ����� ����������������� � ���� �� � ����� ����� ������������ �������
				while (Is_Reserved_Filename(Get_File_Name(fileName)) || Filename_Forbidden_Characters_Check(Get_File_Name(fileName)) || !Txt_Check(Get_File_Name(fileName))) {
					std::cout << "������������ �������� ��� ������ �����. ���������� ��� ���." << std::endl << "> ";
					fileName = Read_String_Without_Whitespace();
				}
				//�������� ������������� �����. ���� ���� ����������, ��� ������������ ��������� � ����� �� ���� �������, ���� ������� ������ ����.
				if (File_Exists(fileName)) {

					do {
						std::cout << "���� ��� ����������. �������� ����� �����: " << std::endl << "1 - ������������ ����" << std::endl << "2 - �������� � ����� �����" << std::endl << "3 - ������� ������ ����" << std::endl << "> ";
						saveMethod = Check_Int();
						switch (saveMethod) {
							//� ����������� �� ������ ������������, ���� �����������, � ���������� ���������, ���� �����������,
							//� � ����������� � ����� ����������� ���������� ������
						case RewriteFile:
							file.open(fileName, std::ios::trunc);
							break;
						case WriteToTheEndOfTheFile:
							file.open(fileName, std::ios::app);
							file << '\n';
							break;
						case SelectAnotherFile:
							break;
						default:
							std::cout << "������ ������ ��� � ����, ���������� ��� ���" << std::endl;
							break;
						}
					} while (saveMethod != RewriteFile && saveMethod != WriteToTheEndOfTheFile && saveMethod != SelectAnotherFile);

				}

				else if (Only_Read(fileName)) {
					std::cout << "������ ������� � �����. ���� �������� ������ ��� ������." << std::endl;
					break;
				}

				//���� ����� �� ����������, ������� �� �������� ����� while.
				if (saveMethod == RewriteFile || saveMethod == WriteToTheEndOfTheFile || !File_Exists(fileName)) {
					break;
				}

			}

			if (!File_Exists(fileName)) { //���� ����� �� ����������, ���������� ������� ��� ��� ���������� ��� ����������

				do {
					std::cout << "����� �� ������� ���� �� �������, ������ ������� ���?" << std::endl
						<< "1 - ������� ����." << std::endl << "2 - ���������� ��� ����������." << std::endl << "> ";
					fileMethod = Check_Int();
					switch (fileMethod) {
					case CreateFile:
						file.open(fileName);
						break;
					case ContunueWithoutCreatingFile:
						break;
					default:
						std::cout << "������ ������ ��� � ����, ���������� ��� ���" << std::endl;
						break;
					}
				} while (fileMethod != CreateFile && fileMethod != ContunueWithoutCreatingFile);

			}

			//��������� ����������� �� ��������� ������ ���������� (���������� ��� ����������) 
			// � ������� �� ����� ���������� � ���� ��� ����������� ��� ���������� 
			//����� ������� ������� � ����.
			if (saveMethod == RewriteFile || saveMethod == WriteToTheEndOfTheFile || fileMethod == CreateFile) {
				file << "�������� ������: " << '\n';

				for (int i = 0; i < vect.size(); i++) {
					file << vect[i] << ' ';
					if (i == vect.size() - 1) file << '\n';
				}

				file << '\n' << "������������� ������:" << '\n';

				for (int i = 0; i < vect2.size(); i++) {
					file << vect2[i] << ' ';
				}

			}

			file.close();
			break;
		case ContinueWithoutSaving:
			break;
		default:
			std::cout << "������ ������ ��� � ����, ���������� ��� ���" << std::endl;
			break;
		}

	} while (saveChoise != Save && saveChoise != ContinueWithoutSaving);
}
