#pragma once
#include <iostream>
using namespace std;
#include <string>//
// Created by 1 on 2020/9/7.
//
class Worker{
public:
    //��ʾ������Ϣ
    virtual void showInfo()=0;
    virtual string getDeptName()=0;
    //��ȡ��λ����
    int m_Id;
    string m_Name;
    int m_DeptId;
};

#ifndef PROJECT_WORKER_H
#define PROJECT_WORKER_H

#endif //PROJECT_WORKER_H
