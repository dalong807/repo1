#pragma once//��ֹͷ�ļ��ظ�����
#include<iostream>//��������������ļ�
#include "worker.h"
#include"employee.h"
#include "boss.h"
#include "manager.h"
#include <fstream>
#define FILENAME "C:/Users/1/Desktop/fire/project/test.txt"
using namespace  std;//ʹ�ñ�׼�����ռ�
// Created by 1 on 2020/9/6.
//
class WorkerManager
{
public:
    //���캯��
    WorkerManager();
    //��������
    ~WorkerManager();
    void Show_Menu();
    //�˳�ϵͳ
    void ExitSystem();
    void Add_Emp();
    void save();
    int m_EmpNum;
    Worker ** m_EmpArray;
    bool m_FileIsEmpty;
    int get_EmpNum();
    void init_Emp();
    void show_Emp();
    void Del_Emp();
    int IsExit(int id);
    void Mod_Emp();
    void Find_Emp();
    void Sort_Emp();
    void Clean_File();

};
#ifndef PROJECT_WORKERMANAGER_H
#define PROJECT_WORKERMANAGER_H

#endif //PROJECT_WORKERMANAGER_H
