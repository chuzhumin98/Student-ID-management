#include<iostream>
#include<fstream> 
#include<windows.h>
#include<cstring>
#include<cstdlib> 
#include<cstring>
#include<iomanip>
#include <shellapi.h>
#include "Time.h"
#include"Operate.h"
#include "enum.h"
#include "Store.h"
#include "Student.h"
#include "THUstudent.h"
#include "Achieve.h"
using namespace std;
//�����̵��ļ���ʼ������
Status ippp=finstore(); 
int main(){
	SetConsoleTitle("ѧ�������������");//���ñ���
	cout<<"System is loading for Student and Operate......"<<endl;
	fin_sunsrun();//�������ⳤ�����ֱ�׼ 
	//��ɶ�ѧ������ѧ�Ŵ�С����������� 
	sort_student(s,n);
	//���廪ѧ��˳�����ֵ 
	for(int i=0;i<n;i++){
		THUs[i]=putTHUstudent(s[i],0);
	}
	//�����ʼoperate���� 
	cout<<"���������У�"<<endl; 
	int iwww=finoperate();
	for(int i=0;i<iwww;i++){
		pre_TOTAL_DONE(otemp[i]);
	}
/*	cout<<"D-deposit	C-consume"<<endl;
	cout<<n<<endl;
	for(int i=0;i<n;i++){
		s[i].display_fout();
	} */
/*	Operate o1(2015,12,4,5,2,1,2015000002,40);
	Operate o2(2015,11,6,5,5,6,2015010210,-30);
	Operate o3(2015,10,8,7,5,2,2015010003,310);
	Operate o4(2015,12,9,5,7,10,2015010006,-530);
	Operate o5(2015,12,10,7,8,3,2015010008,570);
	pre_TOTAL_DONE(o1);
	pre_TOTAL_DONE(o2);
	pre_TOTAL_DONE(o3);
	pre_TOTAL_DONE(o4);
	pre_TOTAL_DONE(o5);*/
//	OC_cin();
//	OD_cin();
	//��ɶԲ�������ʱ��ǰ������ 
	sort_operate(operate,noperate);
	cout<<"Succeed load! "<<endl;
//	MYL_cin();
//	cout<<THUs[0].getgrade();
//	MYC_cin();
//	cout<<THUs[0].getgrade();
	operateTOTAL_cin();
//	QS_cin();
//	MSD_cin();
//	MSG_cin();
//	MDS_cin();
/*	for(int i=0;i<noperate;i++){
		operate[i].display_3();
	}*/
//	int p=bin_Search_Student(2015010210);
//	cout_singleoperate(2015010210);
//	cout_storeoperate(1); 
	sort_student(s,n);
	sort_operate(operate,noperate);
	displaystudentfout_total();
	displayoperatefout_total(operate,0,noperate);//��ʱ������
	displayoperatefout2_total(); //��ѧ��ѧ������ 
	displayoperatefout3_total(); //���̵�������  
	for(int i=0;i<n;i++){
		s[i].display_fout();
	} 

//	CW_cin();
//	CD_cin(); 
//	QT_cin();
//	for(int i=0;i<n;i++){
//		cout<<s[i].os[0].getstudentid()<<" ";
//	} 
//	operate_cin();
//	log_in(2015010012);
//	QU_cin();
//	QO_cin();
//	TT_cin();
//	TL_cin(); 
//	cout<<THUs[0].getstucard()<<endl;
//	password_fout();	//���������б� 
	fout1.close();
	fout2.close();
	fout3.close();
	fout4.close();
	fout5.close(); 
//	fout6.close();
	ShellExecute(NULL,"open","zip.exe"," -m result.zip studentfout.txt studentnew.txt Operatetotalfout.txt Operatetotalfout3.txt Operatetotalfout2.txt" ,NULL,SW_SHOWNORMAL);
	//�����ⲿ���� 
	delete []s;
	delete []THUs;
	delete []operate;
	delete []otemp;
	system("pause");
} 
