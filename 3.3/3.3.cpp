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
    cout << "������ �-��� ��������: "; cin >> N;
    Student* s = new Student[N];
    char filename[100];


    int menuItem;
    do {
        cout << endl;
        cout << "������� ��:" << endl << endl;
        cout << " [1] - �������� ����� � ���������" << endl;
        cout << " [11] - �������� ������ ��������" << endl;
        cout << " [111] - �������� ��������" << endl;
        cout << " [1111] - ���������� ��� ��������" << endl;
        cout << " [2] - ���� ������� ��� ��������" << endl;
        cout << " [3] - ��������� �������� �� ������ ��������" << endl;
        cout << " [8] - ����� ����� � ����" << endl;
        cout << " [9] - ���������� ����� �� �����" << endl;
        cout << " [0] - ���������� ������" << endl << endl;
        cout << "������ ��������: "; cin >> menuItem;
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
            cout << " [1] - ��������� �� �в������ " << endl;
            cout << " [2] - ��������� �� �ֲ���� � ����������" << endl;
            cout << " [3] - ��������� �� �ֲ���� � Բ����" << endl;
            cout << " [4] - ��������� �� �ֲ���� � �����������" << endl;
            cout << " [5] - ��������� �� ��������� �ֲ����" << endl << endl;
            cout << "������ ��������: "; cin >> menuItem;
            Sort(s,N,menuItem);
            break;
        case 8:
            cin.get();
            cin.sync();

            cout << "������ ��'� �����: "; cin.getline(filename, 99);
            SaveToFile(s, N, filename);
            break;
        case 9:
            cin.get();
            cin.sync();

            cout << "������ ��'� �����: "; cin.getline(filename, 99);
            LoadFromFile(s, N, filename);
            break;
        case 0:
            break;
        default:
            cout << "�� ����� ��������� ��������! "
                "��� ������ ����� - ����� ��������� ������ ����" << endl;
        }
    } while (menuItem != 0);

    return 0;
}

void Create(Student* s, const int N)
{
    for (int i = 0; i < N; i++) {
        cout << "������� � " << i + 1 << ":" << endl;
        cout << "������� ��������: "; cin >> s[i].lastname;
        cout << "������ �: " << endl;
        cout << "���������� : "; cin >> s[i].math;
        cout << "������ : "; cin >> s[i].phsic;
        cout << "����������� : "; cin >> s[i].informatic;
        cout << endl << endl;
    }
}

void Print(Student* s, const int N)
{
    cout << "==================================="
        << endl;
    cout << "| � | ������� | ��� | ��� | ��� |"
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
    cout << "������� � " << temp + 1 << ":" << endl;
    cout << "������� ��������: "; cin >> newS[temp].lastname;
    cout << "������ �: " << endl;
    cout << "���������� : "; cin >> newS[temp].math;
    cout << "������ : "; cin >> newS[temp].phsic;
    cout << "����������� : "; cin >> newS[temp].informatic;
    cout << endl << endl;
    return newS;
}

Student* DeletStudent(Student* s, const int N)
{
    int temp = N;
    temp--;
    int num = 0;
    cout << "� �������� �� ������ �������� : "; cin >> num;
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
    cout << "������� � �� ������ ���������� ";
    cin >> num;
    num--;
    cout << endl << endl;

    int item;

    cout << endl;
    cout << "[1]������� ��������: " << endl;
    cout << "  ������ �: " << endl;
    cout << "[2]���������� : " << endl;
    cout << "[3]������ : " << endl;
    cout << "[4]����������� : " << endl<< endl;
    cout << "������ ��������: "; cin >> item;
    switch (item)
    {
    case 1:
        cout << "������� ��������: "; cin >> s[num].lastname;
        break;
    case 2:
         cout << "���������� : "; cin >> s[num].math;
        break;
    case 3:
        cout << "������ : "; cin >> s[num].phsic;       
        break;
    case 4:
        cout << "����������� : "; cin >> s[num].informatic;
        break;
    default:
        cout << "�� ����� ��������� ��������! "
            "��� ������ ����� - ����� ��������� ������ ����" << endl;
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
        cout << "�� ����� ��������� ��������! "<< endl;
    }
}



void SaveToFile(Student* s, const int N, const char* filename)
{
    ofstream fout(filename, ios::binary); // ������� ������� ���� ������
    fout.write((char*)&N, sizeof(N)); // �������� ������� ��������
    for (int i = 0; i < N; i++)
        fout.write((char*)&s[i], sizeof(Student)); // �������� �������� ������
    fout.close();
}

void LoadFromFile(Student*& s, int& N, const char* filename)
{
    delete[] s; // ������� �������� ���
    ifstream fin(filename, ios::binary); // ������� ������� ���� ����������
    fin.read((char*)&N, sizeof(N)); // ��������� ������� ��������
    s = new Student[N]; // �������� ��������� �����
    for (int i = 0; i < N; i++)
        fin.read((char*)&s[i], sizeof(Student)); // ��������� �������� ������
    fin.close();
}