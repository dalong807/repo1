#include <iostream>
#include<string>
#include<iostream>
#include"workerManager.h"
#include "worker.h"
#include "employee.h"
#include "boss.h"
#include "manager.h"
using namespace std;

int main() {
//    Worker * worker=NULL;
//    worker=new Emplyee(1,"����",1);
//            worker->showInfo();
//    delete worker;
//    worker = new Manager(2,"����",2);
//            worker->showInfo();
//    delete worker;
//    worker = new Boss(3,"����",3);
//    worker->showInfo();
//    delete worker;
    WorkerManager wm;
    int choice;
    while (true)
    {
        wm.Show_Menu();
        cout<<"����������ѡ��"<<endl;
        cin>>choice;
        switch (choice) {
            case 0://�˳�ϵͳ
                wm.ExitSystem();
                break;
            case 1://����ְ��
            wm.Add_Emp();
                break;
            case 2://��ʾְ��
            wm.show_Emp();
                break;
            case 3://ɾ��ְ��
            wm.Del_Emp();
                break;
            case 4://�޸�ְ��
            wm.Mod_Emp();
                break;
            case 5://����ְ��
            wm.Find_Emp();
                break;
            case 6://����ְ��
            wm.Sort_Emp();
                break;
            case 7://���ְ��
            wm.Clean_File();
                break;
            default:
                system("cls");


        }
    }
    system("pause");
    return 0;
}
