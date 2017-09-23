#ifndef STORE_H
#define STORE_H
#include<iostream>
#include<cstring>
#include<fstream>
#include"enum.h"
#include"Operate.h"
using namespace std;
//�����̵�Ļ�����Ϣ 
ifstream fin2("Store.txt");
//�̵���
class Store
{protected:
	short storenum;//�̵��� 
	string storename;//�̵�����
	bool isconsume;//�ж��̵��Ƿ�������
	bool isdeposit;//�ж��̵��Ƿ���Ȧ�� 
public:
	//�̵����Ĭ�Ϲ��캯�� 
	Store();
	//�̵���ĺ������Ĺ��캯��
	Store(short s,string name,bool isc,bool isd); 
	//��ȡ�̵��ź���
	int getstorenum(){return storenum;}
	//Store���л�����Ϣ��չʾ����
	void display(); 
	friend Store putStore(int ,string ,bool ,bool ); 
}; 

//�̵���Ĺ����빹�캯���ǳ����Ƶĸ�ֵ����
Store putStore(int s,string name,bool isc,bool isd);
//�����̵����14����������14�������̵� 
Store store[14];
//���ļ�������ɶ��̵�ĳ�ʼ������ 
Status finstore();
//�ж��Ƿ��������ṩ���̵����������ز���
Status ifoperateforstorenum(Operate &); 
//�ж��Ƿ��������ṩ���̵����������ز�������cout�ͣ������ڳ�ʼ���룩 
Status pre_ifoperateforstorenum(Operate &o);



	//�̵����Ĭ�Ϲ��캯��
	Store::Store(){
		storenum=0;
		storename="Unknown";
		isconsume=false;
		isdeposit=false;
	} 
	//�̵���Ĵ������Ĺ��캯��  
	Store::Store(short s,string name,bool isc,bool isd){
		storenum=s;
		storename=name;
		isconsume=isc;
		isdeposit=isd;
	}
	//�̵���Ļ�����Ϣչʾ����
	void Store::display(){
		cout<<"for store "<<storenum<<"..."<<endl;
		cout<<"Storename: "<<storename<<"	";
		cout<<"Consume: ";
		if(isconsume){
			cout<<"YES";
		}else{
			cout<<"NO";
		}
		cout<<"	";
		cout<<"Deposit: ";
		if(isdeposit){
			cout<<"YES";		
		}else{
			cout<<"NO";
		}
		cout<<endl;
	} 
//�̵���Ĺ����빹�캯���ǳ����Ƶĸ�ֵ����
Store putStore(int s,string name,bool isc,bool isd){
	Store tmp;
	tmp.storenum=s;
	tmp.storename=name;
	tmp.isconsume=isc;
	tmp.isdeposit=isd;
	return tmp;
} 
//���ļ�������ɶ��̵�ĳ�ʼ������ 
Status finstore(){
	string p;
	for(int i=0;i<4;i++){
		fin2>>p;
	} 
	int s;
	string name;
	bool isc,isd;
	for(int i=0;i<14;i++){
		fin2>>s;
		fin2>>name;
		fin2>>isc>>isd;
		store[i]=putStore(s,name,isc,isd);
	}
	return success;
}
//�ж��Ƿ��������ṩ���̵����������ز���
Status ifoperateforstorenum(Operate &o){
	float a=o.getmoney();
	short b=o.getstorenum();
	if(a>0){
		if(b==1 || b==2 || b==3 || b==4 || b==5 || b==6 || b==7 || b==13 || b==14){
			return success;
		}else{
			cout<<"ERROR FOR WRONG STORENUM "<<endl;
			return failure;
		}
	}
	if(a<0){
		if(b<=12 && b>=1){
			return success;
		}else{
			cout<<"ERROR FOR WRONG STORENUM "<<endl;
			return failure;
		}
	}
	if(a==0){
		if(b<=14 && b>=1){
			return success;
		}else{
			cout<<"ERROR FOR WRONG STORENUM "<<endl;
			return failure;
		}
	}
} 
//�ж��Ƿ��������ṩ���̵����������ز�������cout�ͣ������ڳ�ʼ���룩 
Status pre_ifoperateforstorenum(Operate &o){
	float a=o.getmoney();
	short b=o.getstorenum();
	if(a>0){
		if(b==1 || b==2 || b==3 || b==4 || b==5 || b==6 || b==7 || b==13 || b==14){
			return success;
		}else{
			return failure;
		}
	}
	if(a<0){
		if(b<=12 && b>=1){
			return success;
		}else{
			return failure;
		}
	}
	if(a==0){
		if(b<=14 && b>=1){
			return success;
		}else{
			return failure;
		}
	}
} 
#endif
