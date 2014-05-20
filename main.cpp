#include <iostream>
#include <fstream>

using namespace std;

int main(int argv, char** argc)
{
	setlocale(LC_ALL, "rus");
	ifstream inFile;
	ofstream outFile;
	int in_key;
	char key, menu, bufferChar;
	if(argv > 1)
		inFile.open(argc[1], ios_base::in);
	else
	{
		char nameFile[256];
		cout<<"Введите имя входного файла: ";
		cin>>nameFile;
		inFile.open(nameFile, ios_base::in);
	}	
	if(!inFile)
	{
		cout<<"\nНе удалось входной открыть файл.";
		return 1;
	}
	if(argv > 2)
		outFile.open(argc[2], ios_base::out);
	else
	{
		char nameFile[256];
		cout<<"\nВведите имя выходного файла: ";
		cin>>nameFile;
		outFile.open(nameFile, ios_base::out);
	}
	if(!outFile)
	{
		cout<<"\nНе удалось открыть выходной файл.";
		return 2;
	}
	if(argv > 3)
		key = argc[3][0];
	else
	{
		cout<<"\nВведите символ ключ: ";
		cin>>in_key;
		in_key%=255;
		key=in_key;

	}
	cout<<"\nВыберите соответствующий пункт меню:\n1-шифрование файла\n2-расшифровка файла\n";
	do 
	{
		cin>>menu;
	} while (menu != '1' && menu != '2');
	if(menu == '1')
	{
		inFile.get(bufferChar);
		while (!inFile.eof())
		{
			bufferChar += key;
			outFile<<bufferChar;
			inFile.get(bufferChar);
		}
	}
	else
	{
		inFile.get(bufferChar);
		while (!inFile.eof())
		{
			bufferChar -= key;
			outFile<<bufferChar;
			inFile.get(bufferChar);
		}

	}
	inFile.close();
	outFile.close();
	return 0;
}
