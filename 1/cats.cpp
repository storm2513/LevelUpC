#include <iostream>

using namespace std;

struct Cat{
	string name;
	string color;
	bool isCostrated;
	bool isHungry;
	int age;
	string mood;
};

void addCat(Cat &cat, string name, string color, bool isCostrated, bool isHungry, int age, string mood){
	cat.name = name;
	cat.color = color;
	cat.isCostrated = isCostrated;
	cat.isHungry = isHungry;
	cat.age = age;
	cat.mood = mood;
}

void getCostrated(bool isCostrated){
	isCostrated ? cout << "Кастрирован\n" : cout << "Не кастрирован\n";
}

void getHungry(bool isHungry){
	isHungry ? cout << "Голоден\n" : cout << "Не голоден\n";
}

string getYears(int age){
	string years;
	switch(age){
		case 1:
			years = " годик";
			break;
		case 2:
		case 3:
		case 4:
			years = " годика";
			break;
		default:
			years = " годиков";
			break;
	}
	return years;
}

void getCatInfo(Cat cat){
	cout << "--------------------------------------" << endl;
	cout << "Имя котика - " << cat.name << endl <<
	"Цвет котика - " << cat.color << endl;
	getCostrated(cat.isCostrated);
	getHungry(cat.isHungry);
	cout << "Возраст котика - " << cat.age  << getYears(cat.age) << endl <<
	"Настроение котика - " << cat.mood << endl;
	cout << "--------------------------------------" << endl;
}

string getName(){
	string name;
	cout << "Введи имя котика: ";
	cin >> name;
	return name;
}

string getColor(){
	string color;
	cout << "Введи цвет котика: ";
	cin >> color;
	return color;
}

int getAge(){
	int age;
	cout << "Введи возраст котика (в годах): ";
	cin >> age;
	while (age < 1 || age > 40){
		cout << "Некорректный возраст. Повтори ввод: ";
		cin >> age;
	}
	return age;
}

string getMood(){
	string mood;
	cout << "Введи, какое у котика настроение: ";
	cin >> mood;
	return mood;
}

bool costrated(){
	bool isCostrated;
	cout << "Котик кастрирован? \n";
	cout << "1. Кастрирован\n2. Не кастрирован\n";
	int n;
	cin >> n;
	while (n != 1 && n != 2){
		cout << "Некорректный ввод.\nКотик кастрирован? \n";
		cout << "1. Кастрирован\n2. Не кастрирован\n";
		cin >> n;
	}
	switch(n){
		case 1:
			isCostrated = true;
			break;
		case 2:
			isCostrated = false;
			break;
	}
	return isCostrated;
}

bool hungry(){
	bool isHungry;
	cout << "Котик голоден? \n";
	cout << "1. Голоден\n2. Не голоден\n";
	int n;
	cin >> n;
	while (n != 1 && n != 2){
		cout << "Некорректный ввод.\nКотик голоден? \n";
		cout << "1. Голоден\n2. Не голоден\n";
		cin >> n;
	}
	switch(n){
		case 1:
			isHungry = true;
			break;
		case 2:
			isHungry = false;
			break;
	}
	return isHungry;
}

int showMenu(){
	cout << "1. Добавить котика\n2. Удалить котика\n3. Отредактировать котика\n4. Показать полную информацию о котике\n5. Показать всех котиков\n6. Выход\n";
	int status;
	cin >> status;
	while (status < 1 || status > 6){
		cout << "Такого пункта в меню нет :(\nПопробуй ещё раз\n";
		cout << "1. Добавить котика\n2. Удалить котика\n3. Отредактировать котика\n4. Показать полную информацию о котике\n5. Показать всех котиков\n6. Выход\n";
		cin >> status;
	}
	return status;
}

void enterCat(Cat* &catArray, int i){
	string name, color, mood;
	bool isCostrated, isHungry;
	int age, status;
	cout << "Ввод котика номер " << i + 1 << endl;
	name = getName();
	color = getColor();
	isCostrated = costrated();
	isHungry = hungry();
	age = getAge();
	mood = getMood();
	addCat(catArray[i], name, color, isCostrated, isHungry, age, mood);
}

Cat* addCat(Cat catArray[], int count){
	Cat* temp = new Cat[count + 1];
	for (int i = 0; i < count; i++){
		temp[i] = catArray[i];
	}
	delete [] catArray;
	return temp;
}

Cat* deleteCat(Cat catArray[], int count){
	int index;
	cout << "Введи номер котика, которого ты хочешь удалить: ";
	cin >> index;
	index -= 1;
	Cat* temp = new Cat[count - 1];
	int j = -1;
	for (int i = 0; i < count - 1; i++){
	  	j++;
	  	if(j == index)
	    	j++;
	  	temp[i] = catArray[j];
	}
	delete [] catArray;
	return temp;
}

void showCats(Cat* catArray, int count){
	cout << "--------------------------------------" << endl;
	for (int i = 0; i < count; i++){
		cout << i + 1 << ". " << catArray[i].name << endl;
	}
	cout << "--------------------------------------" << endl;
}

void editCat(Cat* catArray){
	int index, n;
	cout << "Введи номер редактируемого котика: ";
	cin >> index;
	index -= 1;
	cout << "Введи параметр, который нужно отредактировать:\n1. Имя\n2. Цвет\n3. Возможность продолжения рода\n4. Возраст\n5. Настроение\n6. Желание покушать\n";
	cin >> n;
	switch(n){
		case 1:
			cout << "Введи новое имя для котика: ";
			cin >> catArray[index].name;
			break;
		case 2:
			cout << "Введи новый цвет котика: ";
			cin >> catArray[index].color;
			break;
		case 3:
			catArray[index].isCostrated = costrated();
			break;
		case 4:
			cout << "Введи новый возраст котика (в годах): ";
			cin >> catArray[index].age;
			while (catArray[index].age < 1 || catArray[index].age > 40){
				cout << "Некорректный возраст.\nВведи новый возраст котика (в годах): ";
				cin >> catArray[index].age;
			}
			break;
		case 5:
			cout << "Введи новое настроение котика: ";
			cin >> catArray[index].mood;
			break;
		case 6:
			catArray[index].isHungry = hungry();
			break;
	}
}

void getCatById(Cat catArray[], int count){
	int index;
	cout << "Укажи номер котика: ";
	cin >> index;
	while (index < 1 || index > count){
		cout << "Котика с таким номером нет :(\n Укажи номер котика ещё раз: ";
		cin >> index;
	}
	index -= 1;
	cout << "Это котик " << catArray[index].name << endl;
	getCatInfo(catArray[index]);
}

int main(){
	int count, status;
	cout << "Введи сколько котиков ты хочешь добавить: ";
	cin >> count;
	Cat* catArray = new Cat[count];
	for (int i = 0; i < count; i++){
		enterCat(catArray, i);
		getCatInfo(catArray[i]);
	}
	while (true){
		status = showMenu();
		switch(status){
			case 1:
				catArray = addCat(catArray, count);
				enterCat(catArray, count);
				getCatInfo(catArray[count]);
				count++;
				break;
			case 2:
				if(count == 0){
					cout << "Котики отсутствуют :(\n";
					break;
				}
				catArray = deleteCat(catArray, count);
				count--;
				break;
			case 3:
				editCat(catArray);
				break;
			case 4:
				getCatById(catArray, count);
				break;
			case 5:
				if(count == 0){
				    	cout << "Котики отсутствуют :(\n";
				    	break;
				    }
				showCats(catArray, count);
				break;
			case 6:
				exit(0);
				break;
		}
	}
return 0;
}
