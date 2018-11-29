#include<iostream>
#include<string>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

bool compareLen(const string& a, const string& b)
{
	return (a.size() < b.size());
}
void sortStr(vector<string> str)
{
	int choice = 0;
	while (choice != 4)
	{

		cout << "Choose sort type:" << endl;
		cout << "1. Alphabetical order,\n2. Descending alphabetical order,\n3. Sort by length\n4. Exit\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			cout << "In alphabetical order: " << endl;
			sort(str.begin(), str.end());
			ostream_iterator<string> out(cout, "\n");
			copy(str.begin(), str.end(), out);
			cout << endl;
			break;
		}
		case 2:
		{
			cout << "In descending  order: " << endl;
			sort(str.begin(), str.end(), greater<string>());
			ostream_iterator<string> out1(cout, "\n");
			copy(str.begin(), str.end(), out1);
			cout << endl;
			break;
		}
		case 3:
		{
			cout << "Sort by length: " << endl;
			sort(str.begin(), str.end(), compareLen);
			ostream_iterator<string> out2(cout, "\n");
			copy(str.begin(), str.end(), out2);
			cout << endl;
			break;
		}
		case 4:
			break;
		default:
			cout << "Unknown number. Please enter from 1 to 4" << endl;
			break;
		}
	}
}
void main()
{
	setlocale(LC_ALL, "rus");
	int ch;
	cout << "Enter number of the task: ";
	cin >> ch;
	if (ch == 1)
	{
		cout << "Запросить у пользователя символ и количество символов, создать строку из заданного количества повторов указанного символа и вывести ее на экран." << endl;
		char s;
		int num;
		cout << "Enter symbol: ";
		cin >> s;
		cout << "Enter number of repetitions: ";
		cin >> num;
		string str = string(num, s);
		cout << "Result: " << str << endl;
	}
	else if (ch == 2)
	{
		cout << "Запросить у пользователя строку и количество символов, создать строку из заданного количества символов исходной строки и вывести ее на экран." << endl;

		string s1;
		int num;
		cout << "Enter string: ";
		cin.ignore();
		getline(cin, s1, '\n');
		cout << "Enter number of symbols: ";
		cin >> num;
		string s2 = string(s1, 0, num);
		cout << "Result: " << s2 << endl;

	}
	else if (ch == 3)
	{
		cout << "Написать пример, демонстрирующий возникновение и обработку исключения out_of_range при обращении к символу строки по недопустимому индексу." << endl;
		string str("Hello world");
		cout << "str.at(3) = " << str.at(3) << endl;
		try
		{
			cout << str.at(100) << endl;
		}
		catch (out_of_range e)
		{
			cout << "exception: " << e.what() << endl;
		}
	}
	else if (ch == 4)
	{
		cout << "Разработать функцию сортировки массива строк, предусмотреть возможность сортировки: в алфавитном порядке, в обратном алфавитном порядке, по длине стрк" << endl;

		vector<string> str = { "abc", "dbatt", "ccakk", "aach", "zfre" };
		sortStr(str);

	}	
	else
	{
		cout << "Unknown number task. Please enter from 1 to 4." << endl;
	}
	system("pause");
}
