#include <iostream>
#include<Windows.h>
#include<string>
using  namespace std;
void Menu()
{
	cout << "-----Список дел-----" << endl
		<< "1.Добавить дело" << endl
		<< "2.Удалить дело" << endl
		<< "3.Редактировать дело" << endl
		<< "4.Поиск дел" << endl
		<< "5.Отображение дел" << endl
		<< "6.Сортировка дел" << endl
	    << "7.Выход" << endl;

}

struct Todolist
{
	string Title;
	int Priority;
	string Description;
	int day;
	int month;
	int year;
	int hour;
	int minutc;
};
//Добавление
void AddingСase(Todolist*& List, int& NumberСases, const Todolist& NewCases)
{
	Todolist* Newlist = new Todolist[NumberСases + 1];
	for (int i = 0; i < NumberСases; i++)
		Newlist[i] = List[i];
	Newlist[NumberСases] = NewCases;
	delete[]List;
	List = Newlist;
	NumberСases++;
}
//Удаление
void DeleteCase(string Title, int& NumberCases, Todolist*& List)
{
	int index = -1;
	cout << "Введите названия дела которого, хотите удалить:";
	cin >> Title;
	cout << endl;
	for (int i = 0; i < NumberCases; i++)
		if (List[i].Title == Title)
			index = i;
	if (index != 1)
		for (int i = 0; i < NumberCases - 1; i++)
			List[i] = List[i + 1];
	NumberCases--;
}
//Редактирование 
int FindIndex(Todolist*& List, int NumberCases, string Title)
{
	cout << "Введите название дела, которого надо редактировать:";
	cin >> Title;
	for (int i = 0; i < NumberCases; i++) {
		if (List[i].Title == Title) 
			return i;
	}
	return -1;
};

void  EditCase( Todolist*& List,int& NumberCases)
{
	int index = FindIndex(List, NumberCases, List->Title);
	Todolist list;
	if (index != -1)
	{
		Todolist& list = List[index];
		cin.ignore();
		cout << "Введите новое название дела: ";
		getline(cin, List[index].Title);
		cout << "Введите новый приоритет: ";
		cin >> List[index].Priority;
		cin.ignore(); 
		cout << "Введите новое описание: ";
		getline(cin, List[index].Description);
		cout << "Введите новую дату (ДД ММ ГГГГ): ";
		cin>> List[index].day>>List[index].month>>List[index].year;
		cout << "Введите новое время(ЧЧ ММ): ";
		cin>> List[index].hour>>List[index].minutc;

		cout << "Дело успешно отредактировано!\n";
		cout << endl;
	}
	else
		cout << "Дело с таким названием не найдено.\n";
}
//Поиск
void MenuSearch()
{
	cout<<"-----Поиск дел-----"<<endl
		<< "1.По названию" << endl
		<< "2.По приоритету" << endl
		<< "3.По описанию" << endl
		<< "4.По дате" << endl
		<< "5.По времени исполнения" << endl;
	cout << endl;
}
//Названию 
void SearchTitle(Todolist*& List, int& NumberCases)
{
	int index = FindIndex(List, NumberCases, List->Title);
	Todolist list;
	if (index != -1) {
		Todolist& list = List[index];
		cout << "Название дела: " << List[index].Title << endl
			<< "Приоритет: " << List[index].Priority << endl
			<< "Описание: " << List[index].Description << endl
			<< "Дата(ДД.ММ.ГГГГ): " << List[index].day << "." << List[index].month << "." << List[index].year << endl
			<< "Время(ЧЧ.ММ): " << List[index].hour << "." << List[index].minutc << endl;
		cout << endl;
	}
	else
		cout << "Дело с таким названием не найдено." << endl;
}
//Приоритету
int IndexPriority(Todolist*& List, int NumberCases, int Priority)
{
	cout << "Введите приоритет дела, которого надо найти:";
	cin >> Priority;
	for (int i = 0; i < NumberCases; i++) {
		if (List[i].Priority == Priority)
			return i;
	}
	return -1;
};
void SearchPriority(Todolist*& List, int& NumberCases)
{
	int index = IndexPriority(List, NumberCases, List->Priority);
	Todolist list;
	if (index != -1) {
		Todolist& list = List[index];
		cout << "Название дела: " << List[index].Title << endl
			<< "Приоритет: " << List[index].Priority << endl
			<< "Описание: " << List[index].Description << endl
			<< "Дата(ДД.ММ.ГГГГ): " << List[index].day << "." << List[index].month << "." << List[index].year << endl
			<< "Время(ЧЧ.ММ): " << List[index].hour << "." << List[index].minutc << endl;
		cout << endl;
	}
	else
		cout << "Дело с таким названием не найдено." << endl;
}
//Описанию
int IndexDescription(Todolist*& List, int NumberCases, string Description)
{
	cout << "Введите опиcание дела, которого надо найти:";
	cin >> Description;
	for (int i = 0; i < NumberCases; i++) {
		if (List[i].Description == Description) 
			return i;
	}
	return -1;
};
void SearchDescription(Todolist*& List, int& NumberCases)
{
	int index = IndexDescription(List, NumberCases, List->Description);
	Todolist list;
	if (index != -1) {
		Todolist& list = List[index];
		cout << "Название дела: " << List[index].Title << endl
			<< "Приоритет: " << List[index].Priority << endl
			<< "Описание: " << List[index].Description << endl
			<< "Дата(ДД.ММ.ГГГГ): " << List[index].day << "." << List[index].month << "." << List[index].year << endl
			<< "Время(ЧЧ.ММ): " << List[index].hour << "." << List[index].minutc << endl;
		cout << endl;
	}
	else
		cout << "Дело с таким названием не найдено." << endl;
}
//Дата
int IndexDate(Todolist*& List, int NumberCases, int day, int month,int year)
{
	cout << "Введите дату дела, которого надо найти  :";
	cin >> day>>month>>year;
	if (day > 0 && day < 32 && month >0 && month < 13) {
		for (int i = 0; i < NumberCases; i++) {
			if (List[i].day == day && List[i].month == month && List[i].year == year)
				return i;
		}
	}
	else
		cout << "Ошибка!!!" << endl;
	return -1;
};
void SearchDate(Todolist*& List, int& NumberCases)
{
	int index = IndexDate(List, NumberCases, List->day, List->month, List->year);
	Todolist list;
	if (index != -1) {
		Todolist& list = List[index];
		cout << "Название дела: " << List[index].Title << endl
			<< "Приоритет: " << List[index].Priority << endl
			<< "Описание: " << List[index].Description << endl
			<< "Дата(ДД.ММ.ГГГГ): " << List[index].day << "." << List[index].month << "." << List[index].year << endl
			<< "Время(ЧЧ.ММ): " << List[index].hour << "." << List[index].minutc << endl;
		cout << endl;
	}
	else
		cout << "Дело с таким названием не найдено." << endl;
}
//Время
int IndexTime(Todolist*& List, int NumberCases, int hour,int minutc)
{
	cout << "Введите время исполнения дела, которого надо найти:";
	cin >> hour>>minutc;
	if (0 < hour < 24 && 0 < minutc <= 60)
		for (int i = 0; i < NumberCases; i++) {
			if (List[i].hour == hour && List[i].minutc == minutc) {
				return i;
			}
		}
	else
		cout << "Ошибка!!!"<<endl;
	return -1;
};
void SearchTime(Todolist*& List, int& NumberCases)
{
	int index = IndexTime(List, NumberCases, List->hour, List->minutc);
	Todolist list;
	if (index != -1) {
		Todolist& list = List[index];
		cout << "Название дела: " << List[index].Title << endl
			<< "Приоритет: " << List[index].Priority << endl
			<< "Описание: " << List[index].Description << endl
			<< "Дата(ДД.ММ.ГГГГ): " << List[index].day << "." << List[index].month << "." << List[index].year << endl
			<< "Время(ЧЧ.ММ): " << List[index].hour << "." << List[index].minutc << endl;
		cout << endl;
	}
	else
		cout << "Дело с таким названием не найдено." << endl;
}

//Отображение
void MenuDisplays()
{
	cout << "-----Отображение-----" << endl
		<< "1.Отображение списка дел на день." << endl
		<< "2.Отображение списка дел на неделю." << endl
		<< "3.Отображение списка дел на месяц." << endl
		<< "4.Отображение всего списка." << endl;
	cout << endl;
}

void ShowDisplays(Todolist List[], int NumberCases)
{
	int number = 1;
	for (int i = 0; i < NumberCases; i++)
	{
		//int number = 1;
		cout << "№" << number << endl;
		cout << "Название дела: " << List[i].Title << endl
			<< "Приоритет: " << List[i].Priority << endl
			<< "Описание: " << List[i].Description << endl
			<< "Дата(ДД.ММ.ГГГГ): " << List[i].day << "." << List[i].month << "." << List[i].year << endl
			<< "Время(ЧЧ.ММ): " << List[i].hour << "." << List[i].minutc << endl;
		number++;
		cout << endl;
	}
}

bool IsearlierDate(const Todolist& date1, const Todolist& date2) {
	if (date1.year != date2.year)
		return date1.year < date2.year;
	if (date1.month != date2.month)
		return date1.month < date2.month;
	return date1.day < date2.day;
};

void ShowingCasesDay(Todolist List[], int NumberCases, int day) {
	int NecessaryDay, NecessaryMonth, NecessaryYear;
	cout << "Введите дату который надо отобразить:";
	cin >> NecessaryDay >> NecessaryMonth >> NecessaryYear;
	if (NecessaryDay > 0 && NecessaryDay < 32 && NecessaryMonth >0 && NecessaryMonth < 13)
		for (int i = 0; i < NumberCases; i++)
		{
			if (List[i].day == NecessaryDay && List[i].month == NecessaryMonth && List[i].year == NecessaryYear)
				cout << "Название дела: " << List[i].Title << endl
				<< "Приоритет: " << List[i].Priority << endl
				<< "Описание: " << List[i].Description << endl
				<< "Дата(ДД.ММ.ГГГГ): " << List[i].day << "." << List[i].month << "." << List[i].year << endl
				<< "Время(ЧЧ.ММ): " << List[i].hour << "." << List[i].minutc << endl;
		}
	else
		cout << "Ошибка!!!" << endl;
}

bool isWithinWeek(const Todolist& date, const Todolist& startOfWeek, const Todolist& endOfWeek) {
	return !IsearlierDate(date, startOfWeek) && IsearlierDate(date, endOfWeek);
};

void ShowingCasesWeek(Todolist* List, int NumberCases, const Todolist& startOfWeek, const Todolist& endOfWeek) {
	for (int i = 0; i < NumberCases; ++i) {
		if (isWithinWeek(List[i], startOfWeek, endOfWeek)) {
			cout << "Название дела: " << List[i].Title << endl
				<< "Приоритет: " << List[i].Priority << endl
				<< "Описание: " << List[i].Description << endl
				<< "Дата(ДД.ММ.ГГГГ): " << List[i].day << "." << List[i].month << "." << List[i].year << endl
				<< "Время(ЧЧ.ММ): " << List[i].hour << "." << List[i].minutc << endl;
			cout << endl;
		}
	}
}

void ShowingCasesMonth(Todolist List[], int NumberCases, int month, int year) {
	int NecessaryMonth, NecessaryYear;
	cout << "Введите месяц и год, на который хотите узнать дела:";
	cin >> NecessaryMonth >> NecessaryYear;
	cout << "-----Дела на месяц----- " << endl;
	if (NecessaryMonth > 0 && NecessaryMonth < 13)
		for (int i = 0; i < NumberCases; i++)
		{
			if (List[i].month == NecessaryMonth && List[i].year == NecessaryYear)
				cout << "Название дела: " << List[i].Title << endl
				<< "Приоритет: " << List[i].Priority << endl
				<< "Описание: " << List[i].Description << endl
				<< "Дата(ДД.ММ.ГГГГ): " << List[i].day << "." << List[i].month << "." << List[i].year << endl
				<< "Время(ЧЧ.ММ): " << List[i].hour << "." << List[i].minutc << endl;
			cout << endl;
		}
	else
		cout << "Ошибка!!!";
	cout << endl;
}
//Сортировка
void MenuSorting()
{
	cout << "-----Сортировка-----" << endl
		<< "1.По приоритету" << endl
		<< "2.По дате" << endl
		<< "3.По времени исполнения" << endl;
}

void SortingPriority(Todolist*& List, int NumberCases)
{
	Todolist list;
	for (int i = 0; i < NumberCases - 1; ++i) {
		for (int j = 0; j < NumberCases - i - 1; ++j) {
			if (List[j].Priority > List[j + 1].Priority) {
				Todolist list = List[j];
				List[j] = List[j + 1];
				List[j + 1] = list;
			}
		}
	}
}

void ShowPriority(Todolist*& List, int NumberCases)
{
	for (int i = 0; i < NumberCases; i++)
	{
		cout << "Название дела: " << List[i].Title << endl
			<< "Приоритет: " << List[i].Priority << endl
			<< "Описание: " << List[i].Description << endl
			<< "Дата(ДД.ММ.ГГГГ): " << List[i].day << "." << List[i].month << "." << List[i].year << endl
			<< "Время(ЧЧ.ММ): " << List[i].hour << "." << List[i].minutc << endl;
		cout << endl;
	}
}

void SortingDate(Todolist*& List, int NumberCases)
{
	for (int i = 0; i < NumberCases - 1; i++) {
		for (int j = 0; j < NumberCases - i - 1; j++)
		{
			if (!IsearlierDate(List[j], List[j + 1]))
			{
				Todolist list = List[j];
				List[j] = List[j + 1];
				List[j + 1] = list;
			}
		}
	}
	cout << endl;
}

void ShowDate(Todolist*& List, int NumberCases)
{
	for (int i = 0; i < NumberCases; i++)
	{
		cout << "Название дела: " << List[i].Title << endl
			<< "Приоритет: " << List[i].Priority << endl
			<< "Описание: " << List[i].Description << endl
			<< "Дата(ДД.ММ.ГГГГ): " << List[i].day << "." << List[i].month << "." << List[i].year << endl
			<< "Время(ЧЧ.ММ): " << List[i].hour << "." << List[i].minutc << endl;
		cout << endl;
	}
}

bool IsearlierTime(const Todolist& time1, const Todolist& time2) {
	if (time1.minutc != time2.minutc)
		return time1.minutc < time2.minutc;
	if (time1.hour != time2.hour)
		return time1.hour < time2.hour;
};

void SortingTime(Todolist*& List, int NumberCases)
{
	for (int i = 0; i < NumberCases - 1; i++) {
		for (int j = 0; j < NumberCases - i - 1; j++) {
			if (!IsearlierTime(List[j], List[j + 1]))
			{
				Todolist list = List[j];
				List[j] = List[j + 1];
				List[j + 1] = list;
			}
		}
	}
}

void ShowTime(Todolist*& List, int NumberCases)
{
	for (int i = 0; i < NumberCases; i++)
	{
		cout << "Название дела: " << List[i].Title << endl
			<< "Приоритет: " << List[i].Priority << endl
			<< "Описание: " << List[i].Description << endl
			<< "Дата(ДД.ММ.ГГГГ): " << List[i].day << "." << List[i].month << "." << List[i].year << endl
			<< "Время(ЧЧ.ММ): " << List[i].hour << "." << List[i].minutc << endl;
		cout << endl;
	}
};


int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int Displays,menu,Search,Sorting,NumberCases=0;
	Todolist* List = nullptr;
	Todolist NewCases;
	Todolist StartWeek;
	Todolist EndWeek;
	do
	{
		Menu();
		cout << "Введите действие с списком дел:";
		cin >> menu;
		cout << endl;
		switch (menu)
		{
		case 1:
			system("cls");
			cout << "-----Добавление дела-----" << endl;
				cout << "Введите название дела: ";
				cin.ignore();
				getline(cin, NewCases.Title);
				cout << "Введите приоритет: ";
				cin >> NewCases.Priority;
				cin.ignore(); 
				cout << "Введите описание: ";
				getline(cin, NewCases.Description);
				cout << "Введите дату(ДД.ММ.ГГГГ): ";
				cin >> NewCases.day>>NewCases.month>>NewCases.year;
				if (NewCases.day > 0 && NewCases.day < 32 && NewCases.month >0 && NewCases.month < 13) {
					cout << "Введите время(ЧЧ.ММ): ";
					cin >> NewCases.hour >> NewCases.minutc;
					if (NewCases.hour >= 0 && NewCases.hour <= 24 && NewCases.minutc >=0 && NewCases.minutc <= 60)
						AddingСase(List, NumberCases, NewCases);
					else
						cout<<"Ошибка!!!";
				}
				else
					cout << "Ошибка!!!";
				cout << endl;
			break;
		case 2:
			system("cls");
			cout << "-----Удаление дела-----" << endl;
			DeleteCase (List->Title, NumberCases, List);
			break;
		case 3:
			system("cls");
			cout << "-----Редактирование дела-----" << endl;
			EditCase( List,NumberCases);
			break;
		case 4:
			system("cls");
			MenuSearch();
			cout << "Ввидите по какому, критерию будет идти поиск:";
			cin >> Search;
			cout << endl;
			switch (Search)
			{
			case 1:
				SearchTitle(List,NumberCases);
				    break;
			case 2:
				SearchPriority(List, NumberCases);
					break;
			case 3:
				SearchDescription(List,NumberCases);
					break;
			case 4:
				SearchDate(List, NumberCases);
					break;
			case 5:
				SearchTime(List, NumberCases);
					break;
			default:
				cout << "Ошибка!!!";
				break;
			}
			break;
		case 5:
			system("cls");
			MenuDisplays();
			cout << "Введите вариант отображение:";
			cin >> Displays;
			switch (Displays)
			{
			case 1:
				ShowingCasesDay(List, NumberCases, List->day);
				break;
			case 2:
				cin >> StartWeek.day >> StartWeek.month >> StartWeek.year >> EndWeek.day >> EndWeek.month >> EndWeek.year;
				ShowingCasesWeek(List, NumberCases, StartWeek, EndWeek);
				break;
			case 3:
				ShowingCasesMonth(List, NumberCases, List->month, List->year);
				break;
			case 4:
				ShowDisplays(List, NumberCases);
				break;
			default:
				cout << "Ошибка!!!" << endl;
				break;
			}
			break;
		case 6:
			system("cls");
			MenuSorting();
			cout << "Выберите сортировку:";
			cin >> Sorting;
			cout << endl;
			switch (Sorting)
			{
			case 1:
				SortingPriority(List,NumberCases);
				ShowPriority(List, NumberCases);
				break;
			case 2:
				SortingDate(List,NumberCases);
				ShowDate(List, NumberCases);
				break;
			case 3:
			    SortingTime(List, NumberCases);
				ShowTime(List, NumberCases);
				break;
			default:
				cout << "Ошибка!!!!";
				break;
			}
			break;
		case 7:
			system("cls");
			cout << "Чтобы дойти до цели, человеку нужно одно идти!!! Пока!" << endl;
			break;
		default:
			cout << "Ошибка!!!Действия не существует, попробуйте еще" << endl;
			cout << endl;
			break;
		}
		cout << endl;
	} while (menu != 7);
	delete[]List;
	return 0;
}