// Create Timings.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

class String
{
	char* data;
	int lenght; // Без учёта "\0"
public:
	String() {
		data = new char;
		*data = '\0';
		lenght = 0;
		printf("\nmade empty\n");
	}
	String(char* copy) {
		int i;
		lenght = 0;
		while (*(copy + lenght) != '\0') {
			lenght = lenght + 1;
		}
		data = new char[lenght + 1];
		for (i = 0; i < lenght + 1; i++) {
			data[i] = copy[i];
		}
		printf("\nmade char*\n");
	}
	String(String& copy)
	{
		int i;
		lenght = copy.lenght;
		data = new char[lenght + 1];
		for (i = 0; i < lenght + 1; i++) {
			data[i] = copy.data[i];
		}
		printf("\ncopy\n");
	}
	~String()
	{
		delete data;
		printf("\ndelete\n");
	}
	String& operator=(String& orig)
	{
		int i;
		lenght = orig.lenght;
		data = new char[lenght + 1];
		for (i = 0; i < lenght + 1; i++) {
			data[i] = orig.data[i];
		}
		printf("\n=\n");
		return *this;
	}
	operator const char* () const {
		printf("\nconst char *\n");
		return (const char*)data;
	}
	String& operator+=(String& orig)
	{
		printf("\n+=\n");
		if (orig.lenght > 0) {
			char* word;
			int i;
			word = data;
			data = new char[lenght + orig.lenght + 1];
			for (i = 0; i < lenght; i++) {
				data[i] = word[i];
			}
			for (i = lenght; i <= (lenght + orig.lenght); i++) {
				data[i] = orig.data[i - lenght];
			}
			lenght = lenght + orig.lenght;
			delete word;
		}
		return *this;
	}
	String& operator+(String& second) const
	{
		printf("\n+\n");
		String* result;
		result = new String;
		result->lenght = lenght + second.lenght;
		result->data = new char[result->lenght + 1];
		int i;
		if (lenght > 0) {
			for (i = 0; i < lenght; i++) {
				result->data[i] = data[i];
			}
		}
		if (second.lenght > 0) {
			for (i = lenght; i < result->lenght; i++) {
				result->data[i] = second.data[i - lenght];
			}
		}
		result->data[result->lenght] = '\0';
		return *result;
		delete result;
	}
	char operator[](const int index) const
	{
		printf("\noperator[] const\n");
		if (index >= 0 && index < lenght) {
			return data[index];
		}
		else throw "incorrect index";
	}
	char& operator[](const int index)
	{
		printf("\noperator[]\n");
		if (index >= 0 && index < lenght) {
			return data[index];
		}
		else throw "incorrect index";
	}

	void change_data(char* copy) {
		int i;
		lenght = 0;
		while (*(copy + lenght) != '\0') {
			lenght = lenght + 1;
		}
		delete data;
		data = new char[lenght + 1];
		for (i = 0; i < lenght + 1; i++) {
			data[i] = copy[i];
		}
		printf("\nmade char*\n");
	}
	void scanf_console()
	{
		char symbols[100]; // КОСТЫЛЬ!!!!!
		int in_lenght = 0;

		scanf("%c", &symbols[0]);
		while (symbols[0] == '\n')
		{ 
			scanf("%c", &symbols[0]); 
		}
		while (symbols[in_lenght] != '\n')
		{
			in_lenght++;
			scanf("%c", &symbols[in_lenght]);
		}
		symbols[in_lenght] = '\0';
		change_data(symbols);
	}
	void printf_string()
	{
		for (int i = 1; i <= lenght; i++)
		{
			printf("%c", data[i - 1]);
		}
	}
	char* get_data()
	{
		return data;
	}
	bool have_inside_In_string(char* In_string)
	{
		bool same = 1;
		//char last_symbol_of_in_string = in_string[];
	/*	while (same && ())
		{

		}*/
		return same;
	}
};

class Counter
{
	int count;
	String name;
public:
	Counter(char* in_name)
	{
		count = 0;
		name.change_data(in_name);
	}
	void change_count(int in_count)
	{
		count = in_count;
	}
	char* get_name()
	{
		return name.get_data();
	}
	~Counter()
	{
		delete name;
	}
	bool have_counter(char* comment, int excess_symbols) 
	{

	}
};

bool is_number(char symbol)
{
	if (('0' <= symbol) && (symbol <= '9'))
	{
		return true;
	}
	else
	{
		return false;
	}
}


int main()
{
    setlocale(LC_ALL, "Russian");
	int hours = 0, minutes = 0, seconds = 0, excess_symbols = 0;
	String name_of_file, comment;

	char counter_1[7] = { 'с', 'м', 'е', 'р', 'т', 'ь', '\0'}, counter_2[10] = {'А' , 'р', 'е', 'с', 'т', 'о', 'в', 'а', 'н', '\0'};
	Counter counter_first(counter_1), counter_second(counter_2);
	delete counter_1;
	delete counter_2;
	//String("") counter_1;


	printf("Введите имя txt файла без расширения\n");
	name_of_file.scanf_console();
    //scanf("%s", &name_of_file);
    printf("Введите время в формате: \"чч мм сс\" или \"мм сс\" и через пробел комментарий, либо название счётчика, например:\n1 12 5 Кукож\n");
	scanf("%d %d", &minutes, &seconds);
	//printf("Введите \n");
	comment.scanf_console();
	if (is_number(comment[1]))
	{
		hours = minutes;
		minutes = seconds;
		if (is_number(comment[2]))
		{
			seconds = (comment[1] - '0') * 10 + comment[2];
			excess_symbols = 4;
		}
		else
		{
			seconds = comment[1] - '0';
			excess_symbols = 3;
		}
	}
	else
	{
		excess_symbols = 1;
	}
	

	char test_0 = '0', test_9 = '9';
	printf("0:%d 9:%d", test_0, test_9);


    system("pause");
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
