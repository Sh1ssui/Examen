#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <vector>
using namespace std;

class TASK//Интрейфейс
{
public:
    virtual void Enter() = 0;
    virtual string getname() = 0;
    virtual string getdate() = 0;
    virtual string getag() = 0;
    virtual ~TASK() {};
};
class TASK1 : public TASK//Класс таск
{
public:
    string name;
    string date;
    string tag;
    void Enter() override
    {
        cout << "Введите название дела\n";
        getline(cin, name);
        cout << "Введите дату дела\n";
        getline(cin, date);
        cout << "Введите тег дела\n";
        getline(cin, tag);
    }
    string getname() override { return name; }
    string getdate() override { return date; }
    string getag() override { return tag; }

    virtual ~TASK1() {};
};
class AbstractTask//Интерфейс Фабрики
{
public:
    virtual TASK1* createTask() = 0;
    virtual ~AbstractTask() {};
};

class ABSTRACTTASK : public AbstractTask//Фабрика
{
public:
    TASK1* createTask() override
    {
        TASK1* temp = new TASK1();
        temp->Enter();
        return temp;
    }
};

class TASKS//  база данных и место где хрониться вся информация
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
            cout << "Название дела: " << t[i]->getname() << endl;
            cout << "Дата: " << t[i]->getdate() << endl;
            cout << "Тег: " << t[i]->getag() << endl;
            cout << "\n";
        }
    }
};
class SaveRead//сохранить загрузить
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
class Poisk//Поиск по имени, дате, тегу
{
public:
    void SearchName(TASKS* tmp)
    {
        cout << "Введите имя дела: " << endl;
        string s;
        getline(cin, s);
        int k = 0;
        for (int i = 0; i < tmp->t.size(); i++)
        {
            if (tmp->t[i]->getname() == s)
            {
                cout << "Название дела: " << tmp->t[i]->getname() << endl;
                cout << "Дата: " << tmp->t[i]->getdate() << endl;
                cout << "Тег: " << tmp->t[i]->getag() << endl;
                k = 1;
            }
        }
        if (k == 0)
        {
            cout << "Ничего не найдено" << endl;
        }
    }
    void SearchDate(TASKS* tmp)
    {
        cout << "Введите дату дела: " << endl;
        string s;
        getline(cin, s);
        int k = 0;
        for (int i = 0; i < tmp->t.size(); i++)
        {
            if (tmp->t[i]->getname() == s)
            {
                cout << "Название дела: " << tmp->t[i]->getname() << endl;
                cout << "Дата: " << tmp->t[i]->getdate() << endl;
                cout << "Тег: " << tmp->t[i]->getag() << endl;
                k = 1;
            }
        }
        if (k == 0)
        {
            cout << "Ничего не найдено" << endl;
        }
    }
    void SearchTage(TASKS* tmp)
    {
        cout << "Введите тег дела: " << endl;
        string s;
        getline(cin, s);
        int k = 0;
        for (int i = 0; i < tmp->t.size(); i++)
        {
            if (tmp->t[i]->getname() == s)
            {
                cout << "Название дела: " << tmp->t[i]->getname() << endl;
                cout << "Дата: " << tmp->t[i]->getdate() << endl;
                cout << "Тег: " << tmp->t[i]->getag() << endl;
                k = 1;
            }
        }
        if (k == 0)
        {
            cout << "Ничего не найдено" << endl;
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
        cout << "1 - Добавить дело" << endl;
        cout << "2 - показать все дела" << endl;
        cout << "3 - сохранить в файл" << endl;
        cout << "4 - загрузить из файла" << endl;
        cout << "5 - удалить дело" << endl;
        cout << "6 - изменить дело" << endl;
        cout << "7 - поиск" << endl;
        cout << "ESC - выход" << endl;
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
                cout << "У вас нет дел" << endl;

            }
            system("pause");
            break;
        case'3':
            sr.Save(tasks);
            cout << "Сохранено в файл" << endl;
            system("pause");
            break;
        case'4':
            sr.Read(tasks);
            cout << "Загружено из файла" << endl;
            system("pause");
            break;
        case '5':
            cout << "Введите номер елемента который хотите удалить: ";
            k;
            cin >> k;
            if (k < 0 || k > tasks->t.size())
            {
                cout << "Ошибка" << endl;
            }
            else
            {
                tasks->t.erase(tasks->t.begin() + k);
            }
            system("pause");
            break;
        case'6':
            cout << "Введите номер елемента который хотите удалить: ";
            k = 0;
            cin >> k;
            if (k < 0 || k > tasks->t.size())
            {
                cout << "Ошибка" << endl;
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
                cout << "1 - Поиск по имени" << endl;
                cout << "2 - Поиск по дате" << endl;
                cout << "3 - Поиск по тегу" << endl;
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
                cout << "У вас нет дел " << endl;
            }

            system("pause"); }
        break;
        }
    } while (ch != 27);

}