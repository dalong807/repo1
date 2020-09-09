#include"workerManager.h"//

WorkerManager::WorkerManager() {
    ifstream ifs;
    ifs.open(FILENAME,ios::in);
    if(!ifs.is_open()){
        cout<<"�ļ�������"<<endl;
        this->m_EmpNum=0;
        this->m_EmpArray=NULL;
        this->m_FileIsEmpty=true;
        ifs.close();
        return ;
    }
    char ch;
    ifs>>ch;
    if(ifs.eof())
    {
        cout<<"�ļ�Ϊ��"<<endl;
        this->m_EmpNum=0;
        this->m_EmpArray=NULL;
        this->m_FileIsEmpty=true;
        ifs.close();
        return ;
    }
int num=this->get_EmpNum();
    cout<<"ְ������Ϊ��"<<num<<endl;
    this->m_EmpNum=num;
    //���ٿռ�
    this->m_EmpArray=new Worker*[this->m_EmpNum];
    //���ļ��е����ݴ浽������
    this->init_Emp();
    for(int i=0;i<this->m_EmpNum;i++)
        cout<<this->m_EmpArray[i]->m_Id<<endl;

}
WorkerManager::~WorkerManager() {
if(this->m_EmpArray!=NULL)
{
    for(int i=0;i<this->m_EmpNum;i++){
        if(this->m_EmpArray[i]!=NULL){
            delete this->m_EmpArray[i];
        }
    }
    delete [] this->m_EmpArray;
    this->m_EmpArray=NULL;
}
}
void WorkerManager::Show_Menu(){
    cout<<"********************************************"<< endl;
    cout <<"*********��ӭʹ��ְ������ϵͳ!**********"<< endl;
    cout <<"*************0.�˳��������*************"<< endl;
    cout <<"*************1.����ְ����Ϣ*************"<<endl;
    cout<<"**************2.��ʾְ����Ϣ*************"<< endl;
    cout<<"*************3.ɾ����ְְ��*************"<< endl;
    cout <<"*************4.�޸�ְ����Ϣ*************"<< endl;
    cout <<"*************5.����ְ����Ϣ*************"<< endl;
    cout<<"*************6.���ձ������*************"<< endl;
    cout<<"*************7.��������ĵ�*************"<<endl;
    cout<<"********************************************"<<endl;
    cout << endl;

}
void WorkerManager::ExitSystem() {
    cout<<"��ӭ�´�ʹ��"<<endl;
    system("pause");
    exit(0);//�˳�����
}
void WorkerManager::Add_Emp() {
    cout<<"���������ְ������:"<<endl;
    int addNum=0;
    cin>>addNum;
    if(addNum>0)
    {
        int newSize=this->m_EmpNum+addNum;
        Worker ** newSpace=new Worker*[newSize];
        if(this->m_EmpArray!=NULL)
        {
            for(int i=0;i<this->m_EmpNum;i++)
            {
                newSpace[i]=this->m_EmpArray[i];
            }
        }
        for(int i=0;i<addNum;i++)
        {
            int id;
            string name;
            int dSelect;
            cout<<"�������"<<i+1<<"����ְ���ı��"<<endl;
            cin>>id;
            cout<<"�������"<<i+1<<"����ְ��������"<<endl;
            cin>>name;
            cout<<"��ѡ���ְ����λ"<<endl;
            cout<<"1��Ա��"<<endl;
            cout<<"2,����"<<endl;
            cout<<"3,�ϰ�"<<endl;
            cin>>dSelect;
            Worker * worker=NULL;
            switch (dSelect)
            {
                case 1:
                    worker=new Emplyee(id,name,1);
                    break;
                case 2:
                    worker=new Manager(id,name,2);
                    break;
                case 3:
                    worker=new Boss(id,name,3);
                    break;
                default:
                    break;
            }
            newSpace[this->m_EmpNum+i]=worker;

        }
        delete [] this->m_EmpArray;
        this->m_EmpArray=newSpace;
        this->m_EmpNum=newSize;
        this->m_FileIsEmpty= false;
        cout<<"�ɹ����"<<addNum<<"����ְ��"<<endl;
        this->save();
    } else{
        cout<<"��������"<<endl;
    }
    //������������ص��ϼ�Ŀ¼
    system("pause");
    system("cls");
}
void WorkerManager::save(){
    ofstream ofs;
    ofs.open(FILENAME,ios::out);//�������ʽ���ļ�
    //��ÿ��������д�뵽�ļ���
    for(int i=0;i<this->m_EmpNum;i++)
    {
        ofs<<this->m_EmpArray[i]->m_Id<<" "
                <<this->m_EmpArray[i]->m_Name<<" "
                <<this->m_EmpArray[i]->m_DeptId<<endl;
    }
    ofs.close();
}
int WorkerManager::get_EmpNum(){
    ifstream ifs;
    ifs.open(FILENAME,ios::in);
    int id;
    string name;
    int dId;
    int num=0;
    while(ifs>>id&&ifs>>name&&ifs>>dId){
        num++;
    }
    return num;
}
void WorkerManager::init_Emp(){
    ifstream ifs;
    ifs.open(FILENAME,ios::in);
    int id;
    string name;
    int dId;
    int index=0;
    while(ifs>>id&&ifs>>name&&ifs>>dId){
        Worker * worker=NULL;
        if(dId==1){
            worker=new Emplyee(id,name,dId);
        }
        else if(dId==2)
        {
            worker=new Manager(id,name,dId);
        } else{
            worker=new Boss(id,name,dId);
        }
        this->m_EmpArray[index]=worker;
        index++;
    }
    this->m_FileIsEmpty=false;
    ifs.close();
}
void WorkerManager::show_Emp() {
    //�ж��ļ��Ƿ�Ϊ��
    if (this->m_FileIsEmpty)
    {
        cout<<"�ļ������ڻ��¼Ϊ��"<<endl;
    } else{
        for(int i=0;i<m_EmpNum;i++)
        {
            this->m_EmpArray[i]->showInfo();
        }
    }
    system("pause");
    system("cls");
}
void WorkerManager::Del_Emp() {
    if(this->m_FileIsEmpty)
    {
        cout<<"�ļ������ڻ��¼Ϊ��"<<endl;
    }
    else{
        cout<<"��������Ҫɾ��ְ�����"<<endl;
        int id=0;
        cin>>id;
        int index=this->IsExit(id);
        if(index!=-1)
        {
            for(int i=index;i<this->m_EmpNum-1;i++)
            {
                this->m_EmpArray[i]=this->m_EmpArray[i+1];
            }
            this->m_EmpNum--;
            this->save();
            cout<<"ɾ���ɹ�"<<endl;
        } else{
            cout<<"ɾ��ʧ�ܣ�δ�ҵ���ְ��"<<endl;
        }
    }
    system("pause");
    system("cls");
}
int WorkerManager::IsExit(int id) {
int index=-1;
for(int i=0;i<this->m_EmpNum;i++)
{
    if(this->m_EmpArray[i]->m_Id==id)
    {index=i;
    break;}
}
return index;
}
void WorkerManager::Mod_Emp(){
    if(this->m_FileIsEmpty)
    {
        cout<<"�ļ�Ϊ�ջ򲻴���"<<endl;
    }
    else{
        cout<<"�����������޸ĵ�ְ�����"<<endl;
    }
    int id;
    cin>>id;
    int ret=this->IsExit(id);
    if(ret!=-1)
    {
        delete this->m_EmpArray[ret];
        int newId=0;
        string newName="";
        int dSelect=0;
        cout<<"�鵽:"<<id<<"��ְ������������ְ����"<<endl;
        cin>>newId;
        cout<<"������������"<<endl;
        cin>>newName;
        cout<<"�������λ:"<<endl;
        cout<<"1��Ա��"<<endl;
        cout<<"2,����"<<endl;
        cout<<"3���ϰ�"<<endl;
        cin>>dSelect;
        Worker * worker=NULL;
        switch (dSelect) {
            case 1:
                worker=new Emplyee(newId,newName,dSelect);
                break;
            case 2:worker=new Manager(newId,newName,dSelect);
                break;
            case 3:worker=new Boss(newId,newName,dSelect);
                break;
            default:
                break;
        }
        this->m_EmpArray[ret]=worker;
        cout<<"�޸ĳɹ�"<<endl;
        this->save();
    } else{
        cout<<"�޸�ʧ�ܣ����޴���"<<endl;
    }
    system("pause");
    system("cls");
}
void WorkerManager::Find_Emp(){
    if(this->m_FileIsEmpty)
    {
        cout<<"�ļ�Ϊ�ջ򲻴���"<<endl;
    }
    else{
        cout<<"��ѡ����ҷ�ʽ��"<<endl;
        cout<<"1����ְ����Ų���"<<endl;
        cout<<"2����ְ����������"<<endl;
        int select=0;
        cin>>select;
        if(select == 1){
            int id;
            cout<<"��������ҵ�ְ�����"<<endl;
            cin>>id;
            int ret=IsExit(id);
            if(ret!=-1){
                cout<<"���ҳɹ�����ְ����Ϣ���£�"<<endl;
                this->m_EmpArray[ret]->showInfo();
            }
            else{
                cout<<"����ʧ�ܣ����޴���"<<endl;
            }

        }
        else if(select==2){
            cout<<"��������ҵ�����"<<endl;
            string name;
            cin>>name;
            bool flag=false;
            //���ҵ��ı�־
            for(int i =0;i<m_EmpNum;i++){
                if(m_EmpArray[i]->m_Name==name){
                    cout<<"���ҳɹ���ְ�����Ϊ"<<m_EmpArray[i]->m_Id<<endl;
                    cout<<"��Ϣ����:"<<endl;
                    flag=true;
                    this->m_EmpArray[i]->showInfo();
                }
                }
            if(flag==false){
                cout<<"���޴���"<<endl;
            }
            }
        else{
            cout<<"����������"<<endl;
        }
    }



}
void WorkerManager::Sort_Emp() {
    if(this->m_FileIsEmpty){
        cout<<"�ļ�Ϊ��"<<endl;
    }
    else{
        cout<<"��ѡ������ʽ"<<endl;
        cout<<"1����ְ���Ž�������"<<endl;
        cout<<"2,��ְ���Ž��н���"<<endl;
        int select=0;
        cin>>select;
        for(int i=0;i<m_EmpNum;i++)
        {
            int minOrMax=i;
            for(int j=i+1;j<m_EmpNum;j++){
                if(select==1)//����
                {
                    if(m_EmpArray[minOrMax]->m_Id>m_EmpArray[j]->m_Id)
                    {
                        minOrMax=j;
                    }
                }
                else
                {
                    if(m_EmpArray[minOrMax]->m_Id<m_EmpArray[j]->m_Id)
                    {
                        minOrMax=j;
                    }
                }
            }
            if(i!=minOrMax){
                Worker * temp=m_EmpArray[i];
                m_EmpArray[i]=m_EmpArray[minOrMax];
                m_EmpArray[minOrMax]=temp;
            }
        }
        cout<<"����ɹ����������Ϊ"<<endl;
        this->save();
        this->show_Emp();
    }
}
void WorkerManager::Clean_File(){
    cout<<"ȷ�����?"<<endl;
    cout<<"1��ȷ��"<<endl;
    cout<<"2,����"<<endl;
    int select =0;
    cin>>select;
    if(select==1){
        ofstream  ofs(FILENAME,ios::trunc);
        ofs.close();
        if(this->m_EmpArray!=NULL){
            for(int i=0;i<this->m_EmpNum;i++)
            {
                if(this->m_EmpArray[i]!=NULL){
                    delete this->m_EmpArray[i];
                }
            }
            this->m_EmpNum=0;
            delete [] this->m_EmpArray;
        }
        cout<<"��ճɹ�!"<<endl;
    }
    system("pause");
    system("cls");
}

// Created by 1 on 2020/9/6.
//

