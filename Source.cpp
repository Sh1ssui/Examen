#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <vector>
using namespace std;

class TASK//����������
{
public:
    virtual void Enter() = 0;
    virtual string getname() = 0;
    virtual string getdate() = 0;
    virtual string getag() = 0;
    virtual ~TASK() {};
};
class TASK1 : public TASK//����� ����
{
public:
    string name;
    string date;
    string tag;
    void Enter() override
    {
        cout << "������� �������� ����\n";
        getline(cin, name);
        cout << "������� ���� ����\n";
        getline(cin, date);
        cout << "������� ��� ����\n";
        getline(cin, tag);
    }
    string getname() override { return name; }
    string getdate() override { return date; }
    string getag() override { return tag; }

    virtual ~TASK1() {};
};
class AbstractTask//��������� �������
{
public:
    virtual TASK1* createTask() = 0;
    virtual ~AbstractTask() {};
};

class ABSTRACTTASK : public AbstractTask//�������
{
public:
    TASK1* createTask() override
    {
        TASK1* temp = new TASK1();
        temp->Enter();
        return temp;
    }
};

class TASKS//  ���� ������ � ����� ��� ��������� ��� ����������
{
public:
    vector<TASK1*> t;
    ~TASKS()
    {
        for (int i = 0; i < t.size(); i++) delete t[i];
    }
    void Print()
    {
        for (int i = 0; i < t.size(); i++)
        {
            cout << "�������� ����: " << t[i]->getname() << endl;
            cout << "����: " << t[i]->getdate() << endl;
            cout << "���: " << t[i]->getag() << endl;
            cout << "\n";
        }
    }
};
class SaveRead//��������� ���������
{
public:
    void Save(TASKS* tmp)
    {
        ofstream file("Tascs.txt", ios::app);
        if (!file.is_open())
            cout << "Error" << endl;
        else
        {
            for (int i = 0; i < tmp->t.size(); i++)
            {
                file << tmp->t[i]->getname() << endl;
                file << tmp->t[i]->getdate() << endl;
                file << tmp->t[i]->getag() << endl;
                file << "\n";
            }
        }
        file.close();
    }
    void Read(TASKS* tmp)
    {
        ifstream file("Tascs.txt");
        if (!file.is_open())
            cout << "Error";
        else
        {
            string str;
            int i = 0;
            TASK1* temp = new TASK1();
            while (getline(file, str))
            {
                if (!str.empty())
                {
                    file >> temp->name;
                    file >> temp->date;
                    file >> temp->tag;
                    tmp->t.push_back(temp);
                }
            }
        }
        file.close();
    }
};
class Poisk//����� �� �����, ����, ����
{
public:
    void SearchName(TASKS* tmp)
    {
        cout << "������� ��� ����: " << endl;
        string s;
        getline(cin, s);
        int k = 0;
        for (int i = 0; i < tmp->t.size(); i++)
        {
            if (tmp->t[i]->getname() == s)
            {
                cout << "�������� ����: " << tmp->t[i]->getname() << endl;
                cout << "����: " << tmp->t[i]->getdate() << endl;
                cout << "���: " << tmp->t[i]->getag() << endl;
                k = 1;
            }
        }
        if (k == 0)
        {
            cout << "������ �� �������" << endl;
        }
    }
    void SearchDate(TASKS* tmp)
    {
        cout << "������� ���� ����: " << endl;
        string s;
        getline(cin, s);
        int k = 0;
        for (int i = 0; i < tmp->t.size(); i++)
        {
            if (tmp->t[i]->getname() == s)
            {
                cout << "�������� ����: " << tmp->t[i]->getname() << endl;
                cout << "����: " << tmp->t[i]->getdate() << endl;
                cout << "���: " << tmp->t[i]->getag() << endl;
                k = 1;
            }
        }
        if (k == 0)
        {
            cout << "������ �� �������" << endl;
        }
    }
    void SearchTage(TASKS* tmp)
    {
        cout << "������� ��� ����: " << endl;
        string s;
        getline(cin, s);
        int k = 0;
        for (int i = 0; i < tmp->t.size(); i++)
        {
            if (tmp->t[i]->getname() == s)
            {
                cout << "�������� ����: " << tmp->t[i]->getname() << endl;
                cout << "����: " << tmp->t[i]->getdate() << endl;
                cout << "���: " << tmp->t[i]->getag() << endl;
                k = 1;
            }
        }
        if (k == 0)
        {
            cout << "������ �� �������" << endl;
        }
    }
};
int main()
{
    int k;
    Poisk p;
    ABSTRACTTASK A;
    SaveRead sr;
    setlocale(LC_ALL, "Russian");
    TASKS* tasks = new TASKS();
    char ch;
    do
    {
        system("cls");
        cout << "1 - �������� ����" << endl;
        cout << "2 - �������� ��� ����" << endl;
        cout << "3 - ��������� � ����" << endl;
        cout << "4 - ��������� �� �����" << endl;
        cout << "5 - ������� ����" << endl;
        cout << "6 - �������� ����" << endl;
        cout << "7 - �����" << endl;
        cout << "ESC - �����" << endl;
        ch = _getch();
        switch (ch)
        {
        case'1':
            system("cls");
            tasks->t.push_back(A.createTask());
            system("pause");
            break;
        case'2':
            if (tasks->t.size() != 0)
            {
                tasks->Print();
            }
            else
            {
                cout << "� ��� ��� ���" << endl;

            }
            system("pause");
            break;
        case'3':
            sr.Save(tasks);
            cout << "��������� � ����" << endl;
            system("pause");
            break;
        case'4':
            sr.Read(tasks);
            cout << "��������� �� �����" << endl;
            system("pause");
            break;
        case '5':
            cout << "������� ����� �������� ������� ������ �������: ";
            k;
            cin >> k;
            if (k < 0 || k > tasks->t.size())
            {
                cout << "������" << endl;
            }
            else
            {
                tasks->t.erase(tasks->t.begin() + k);
            }
            system("pause");
            break;
        case'6':
            cout << "������� ����� �������� ������� ������ �������: ";
            k = 0;
            cin >> k;
            if (k < 0 || k > tasks->t.size())
            {
                cout << "������" << endl;
            }
            else
            {
                cin.ignore();
                tasks->t[k]->Enter();
            }
            system("pause");
            break;
        case'7':
        {

            system("cls");
            if (tasks->t.size() != 0)
            {
                char ch2;
                cout << "1 - ����� �� �����" << endl;
                cout << "2 - ����� �� ����" << endl;
                cout << "3 - ����� �� ����" << endl;
                ch2 = _getch();
                switch (ch2)
                {
                case'1':
                    p.SearchName(tasks);
                    break;
                case'2':
                    p.SearchDate(tasks);
                    break;
                case'3':
                    p.SearchTage(tasks);
                    break;
                }
            }
            else
            {
                cout << "� ��� ��� ��� " << endl;
            }

            system("pause"); }
        break;
        }
    } while (ch != 27);

}