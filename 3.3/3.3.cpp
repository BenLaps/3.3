#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <Windows.h> 
using namespace std;

struct Student {
    string lastname;
    unsigned math;
    unsigned phsic;
    unsigned informatic;

};

void Create(Student* s, const int N);
void Print(Student* s, const int N);

Student* AddNewStudent(Student* s, const int N);
Student* DeletStudent(Student* s, const int N);
void EditStudent(Student* s, const int N);

void Sort(Student* s, const int N, const int swicher);

void SaveToFile(Student* s, const int N, const char* filename);
void LoadFromFile(Student*& s, int& N, const char* filename);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int N;
    cout << "Введіть к-сть студентів: "; cin >> N;
    Student* s = new Student[N];
    char filename[100];


    int menuItem;
    do {
        cout << endl;
        cout << "Виберіть дію:" << endl << endl;
        cout << " [1] - введення даних з клавіатури" << endl;
        cout << " [11] - добавити нового студента" << endl;
        cout << " [111] - вилучити студента" << endl;
        cout << " [1111] - редагувати дані студента" << endl;
        cout << " [2] - вивід списоку всіх студентів" << endl;
        cout << " [3] - сортувати студентів за певною категорією" << endl;
        cout << " [8] - запис даних у файл" << endl;
        cout << " [9] - зчитування даних із файлу" << endl;
        cout << " [0] - завершення роботи" << endl << endl;
        cout << "Введіть значення: "; cin >> menuItem;
        cout << endl;
        switch (menuItem)
        {
        case 1:
            Create(s, N);
            break;
        case 11:

            s = AddNewStudent(s, N);
            N++;

            break;
        case 12:
            s = DeletStudent(s, N);
            N--;
            break;
        case 13:
            EditStudent(s, N);
            break;
        case 2:
            Print(s, N);
            break;
        case 3:
            cout << endl;
            cout << " [1] - Сортувати за ПРІЗВИЩЕМ " << endl;
            cout << " [2] - Сортувати за ОЦІНКОЮ З МАТЕМАТИКИ" << endl;
            cout << " [3] - Сортувати за ОЦІНКОЮ З ФІЗИКИ" << endl;
            cout << " [4] - Сортувати за ОЦІНКОЮ З ІНФОРМАТИКИ" << endl;
            cout << " [5] - Сортувати за СЕРЕДНЬОЮ ОЦІНКОЮ" << endl << endl;
            cout << "Введіть значення: "; cin >> menuItem;
            Sort(s,N,menuItem);
            break;
        case 8:
            cin.get();
            cin.sync();

            cout << "Введіть ім'я файлу: "; cin.getline(filename, 99);
            SaveToFile(s, N, filename);
            break;
        case 9:
            cin.get();
            cin.sync();

            cout << "Введіть ім'я файлу: "; cin.getline(filename, 99);
            LoadFromFile(s, N, filename);
            break;
        case 0:
            break;
        default:
            cout << "Ви ввели помилкове значення! "
                "Слід ввести число - номер вибраного пункту меню" << endl;
        }
    } while (menuItem != 0);

    return 0;
}

void Create(Student* s, const int N)
{
    for (int i = 0; i < N; i++) {
        cout << "Студент № " << i + 1 << ":" << endl;
        cout << "Прізвище студента: "; cin >> s[i].lastname;
        cout << "Оцінки з: " << endl;
        cout << "математики : "; cin >> s[i].math;
        cout << "фізики : "; cin >> s[i].phsic;
        cout << "інформатика : "; cin >> s[i].informatic;
        cout << endl << endl;
    }
}

void Print(Student* s, const int N)
{
    cout << "==================================="
        << endl;
    cout << "| № | Прізвище | мат | фіз | інф |"
        << endl;
    cout << "==================================="
        << endl;

    for (int i = 0; i < N; i++)
    {
        if (s[i].lastname != "")
        {
            cout << "| " << setw(1) << right << i + 1
                << " | " << setw(8) << left << s[i].lastname
                << " | " << setw(3) << right << s[i].math
                << " | " << setw(3) << right << s[i].phsic
                << " | " << setw(3) << right << s[i].informatic << " |";
            cout << endl;
            cout << "------------------------------";
            cout << endl;
        }
    }
}

Student* AddNewStudent(Student* s, const int N)
{
    int temp = N;
    Student* newS = new Student[temp + 1];
    for (int i = 0; i < N; i++)
    {
        newS[i] = s[i];
    }
    cout << "Студент № " << temp + 1 << ":" << endl;
    cout << "Прізвище студента: "; cin >> newS[temp].lastname;
    cout << "Оцінки з: " << endl;
    cout << "математики : "; cin >> newS[temp].math;
    cout << "фізики : "; cin >> newS[temp].phsic;
    cout << "інформатика : "; cin >> newS[temp].informatic;
    cout << endl << endl;
    return newS;
}

Student* DeletStudent(Student* s, const int N)
{
    int temp = N;
    temp--;
    int num = 0;
    cout << "№ студента що хочете видалити : "; cin >> num;
    Student* newS = new Student[temp];
    for (int i = 0; i < temp; i++)
    {
        if (i < num)
            newS[i] = s[i];
        if (i > num)
        {
            newS[i] = s[i + 1];
        }
    }
    return newS;
}

void EditStudent(Student* s, const int N)
{
    int num = 0;
    cout << "Студент № що хочете редагувати ";
    cin >> num;
    num--;
    cout << endl << endl;

    int item;

    cout << endl;
    cout << "[1]Прізвище студента: " << endl;
    cout << "  Оцінки з: " << endl;
    cout << "[2]математики : " << endl;
    cout << "[3]фізики : " << endl;
    cout << "[4]інформатика : " << endl<< endl;
    cout << "Введіть значення: "; cin >> item;
    switch (item)
    {
    case 1:
        cout << "Прізвище студента: "; cin >> s[num].lastname;
        break;
    case 2:
         cout << "математики : "; cin >> s[num].math;
        break;
    case 3:
        cout << "фізики : "; cin >> s[num].phsic;       
        break;
    case 4:
        cout << "інформатика : "; cin >> s[num].informatic;
        break;
    default:
        cout << "Ви ввели помилкове значення! "
            "Слід ввести число - номер вибраного пункту меню" << endl;
    }
}

void Sort(Student* s, const int N, const int swicher)
{
    Student tmp ;
    double* tmpMass = new double[N];
    switch (swicher)
    {
    case 1:
        for (int i = 0; i < N - 1; i++)
            for (int j = 0; j < N - i - 1; j++)
                if (s[j].lastname > s[j + 1].lastname) {
                    tmp = s [j];
                    s[j] = s[j + 1];
                    s[j + 1] = tmp;
                }
        break;
    case 2:
        for (int i = 0; i < N - 1; i++)
            for (int j = 0; j < N - i - 1; j++)
                if (s[j].math > s[j + 1].math) {
                    tmp = s[j];
                    s[j] = s[j + 1];
                    s[j + 1] = tmp;
                }
        break;
    case 3:
        for (int i = 0; i < N - 1; i++)
            for (int j = 0; j < N - i - 1; j++)
                if (s[j].phsic > s[j + 1].phsic) {
                    tmp = s[j];
                    s[j] = s[j + 1];
                    s[j + 1] = tmp;
                }
        break;
    case 4:
        for (int i = 0; i < N - 1; i++)
            for (int j = 0; j < N - i - 1; j++)
                if (s[j].informatic > s[j + 1].informatic) {
                    tmp = s[j];
                    s[j] = s[j + 1];
                    s[j + 1] = tmp;
                }
        break;
    case 5:
        
        for (int i = 0; i < N - 1; i++)
        {
            tmpMass[i] = (double)((s[i].math+ s[i].informatic+s[i].phsic));
        }
        for (int i = 0; i < N - 1; i++)
            for (int j = 0; j < N - i - 1; j++)
                if (tmpMass[j] > tmpMass[j + 1]) {
                    tmp = s[j];
                    s[j] = s[j + 1];
                    s[j + 1] = tmp;
                }
        break;
    default:
        break;
        cout << "Ви ввели помилкове значення! "<< endl;
    }
}



void SaveToFile(Student* s, const int N, const char* filename)
{
    ofstream fout(filename, ios::binary); // відкрили бінарний файл запису
    fout.write((char*)&N, sizeof(N)); // записали кількість елементів
    for (int i = 0; i < N; i++)
        fout.write((char*)&s[i], sizeof(Student)); // записали елементи масиву
    fout.close();
}

void LoadFromFile(Student*& s, int& N, const char* filename)
{
    delete[] s; // знищили попередні дані
    ifstream fin(filename, ios::binary); // відкрили бінарний файл зчитування
    fin.read((char*)&N, sizeof(N)); // прочитали кількість елементів
    s = new Student[N]; // створили динамічний масив
    for (int i = 0; i < N; i++)
        fin.read((char*)&s[i], sizeof(Student)); // прочитали елементи масиву
    fin.close();
}