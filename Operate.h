#ifndef OPERATE_H
#define OPERATE_H 
#include "enum.h"
#include "Time.h"
#include<iostream>
#include<fstream>
#include<iomanip>
#include<windows.h>
//������˳���ĳ�ʼ����ռ�Ĵ�С 
#define LISTOPERATE_MAX_SIZE 20000
//������˳���Ĵ洢�ռ�����
#define LISTOPERATE_INCREMENT 20 
using namespace std;
//��������Ļ�����Ϣ 
ifstream fin3("Operate.txt");
int listsizeoperate=LISTOPERATE_MAX_SIZE;
//������ 
class Operate
{protected:
	short storenum;//�̵��� 
	int studentid;//ѧ��ѧ�� 
	Time time;
	float money;
	MUCH much : 2;//��¼���� 
public:
	//�������Ĭ�Ϲ��캯�� 
	Operate(); 
	//Operate(�꣬�£��գ�ʱ���֣��̵��ţ�ѧ���ţ����)
	Operate(unsigned y,unsigned mon,unsigned d,unsigned h,unsigned min,
			short stor,int studid,float mey);
	//��Ե��β�������ʾ 
	void display_1(); 
	//���ĳһ���˵ı�ʾ
	void display_2();
	//���ĳһ�̵���ʾ 
	void display_3();
	Time gettime(){return time;}
	short getstorenum(){return storenum;}
	float getmoney(){return money;}
	int getstudentid(){return studentid;}
	MUCH getmuch(){return much;}
	void putmuch(MUCH m){much=m;}
	friend Status ifoperateforstudent(Operate &); 
	friend Status changeforstudent(Operate &);
	friend Status pre_changeforstudent(Operate &);
	friend void operatetostudent(Operate &);
	friend void tooperate(Operate&);
	friend void untooperate(Operate&); 
	friend void operate_cin(); 
	friend void sort_operate(Operate a[],int n);
	friend void displayoperate_total(Operate*o,int front,int behind); 
	friend void displayoperatefout_total(Operate*o,int front,int behind); 
	friend void displayoperatefout2_total(); 
	friend void cout_singleoperate(int studentid);
	friend void cout_storeoperate(int storenum);
	friend void displayoperatefout3_total(); 
	friend void cout_timelimit(Time t1,Time t2);
	friend void TL_cin();
	friend void MDS_cin();
};
//������Ĺ����빹�캯���ǳ����Ƶĸ�ֵ����
Operate putOperate(unsigned y,unsigned mon,unsigned d,unsigned h,unsigned min,
					short stor,int studid,float mey);

//Operate���˳��� 
Operate* operate=new Operate [listsizeoperate];
//����Operate��˳��������洢�Ĳ�����¼������ 
int noperate=0;
//��Ϊ˳���任��Сʱ����ת�洢�ռ�
Operate* otmp; 
//�ļ�������Ĳ������ݴ�ռ�
Operate* otemp=new Operate[LISTOPERATE_MAX_SIZE];
//����otemp˳��������洢�Ĳ�����¼������
int notemp=0; 
//�Բ�������ʱ���Ⱥ�˳��������򣨲������Ĺ鲢���� 
void sort_operate(Operate a[],int n);
//����ȫ�������Ĵ��ʽ���(����front,������behind) 
void displayoperate_total(Operate*o,int front,int behind); 
//����ȫ�������Ĵ��ʽ�ļ����[����ʱ��˳��](����front,������behind) 
void displayoperatefout_total(Operate*o,int front,int behind); 
//��ȡOperate.txt�еĳ�ʼ�ļ���Ϣ���������ж���������������ɶ���ѧ���Ĳ��� 
int finoperate();






	//�������Ĭ�Ϲ��캯�� 
	Operate::Operate(){
		storenum=1;
		studentid=2015000000;
		money=0;
		much=twice;
	}
	//Operate(�꣬�£��գ�ʱ���֣��̵��ţ�ѧ���ţ����)
	Operate::Operate(unsigned y,unsigned mon,unsigned d,unsigned h,unsigned min,
			short stor,int studid,float mey){
				time.putYear(y);
				time.putMonth(mon);
				time.putDay(d);
				time.putHour(h);
				time.putMinute(min);
				storenum=stor;
				studentid=studid;
				money=mey;
				much=twice;
			}
	//��������Ե��β�����ʾ
		void Operate::display_1(){
		cout<<"# ";
		float b=money;
		time.display();
		cout<<"	";
		cout<<studentid<<" ";
		if(money==0){
			cout<<"does nothing in ";
			goto A;
		}
		if(money>0){
			cout<<"deposits ";
		}else{
			b=-money;
			cout<<"consumes ";
		}
		cout<<b<<" yuan in ";
		A: switch(storenum){
			case 1: cout<<"Zijing Yuan "; break;
			case 2: cout<<"Taoli Yuan "; break;
			case 3: cout<<"Dingxiang Yuan "; break;
			case 4: cout<<"Tingtao Yuan "; break;
			case 5: cout<<"Qingfen Yuan "; break;
			case 6: cout<<"Guanchou Yuan "; break;
			case 7: cout<<"He Yuan "; break;
			case 8: cout<<"Lan Yuan "; break;
			case 9: cout<<"Zhilan Yuan "; break;
			case 10: cout<<"Yushu Yuan "; break;
			case 11: cout<<"Underground of C Lou "; break; 
			case 12: cout<<"Underground of Guanchou Yuan "; break;
			case 13: cout<<"North of C Lou "; break;
			case 14: cout<<"Zhu Lou "; break;
			default:  cout<<"ERROR FOR WRONG STORENUM "; break; 
		}
		cout<<endl;
	} 
	//���������ĳһ������ʾ
	void Operate::display_2(){
		cout<<" "; 
		float b=money;
		time.display();
		cout<<"	|	";//����ط�ע�ⰲ��һ����� 
		if(money==0){
			cout<<"Do nothing in ";
			goto A;
		}
		if(money>0){
			cout<<"Deposit ";
		}else{
			b=-money;
			cout<<"Consume ";
		}
		cout<<b<<" yuan in ";
		A: switch(storenum){
			case 1: cout<<"Zijing Yuan "; break;
			case 2: cout<<"Taoli Yuan "; break;
			case 3: cout<<"Dingxiang Yuan "; break;
			case 4: cout<<"Tingtao Yuan "; break;
			case 5: cout<<"Qingfen Yuan "; break;
			case 6: cout<<"Guanchou Yuan "; break;
			case 7: cout<<"He Yuan "; break;
			case 8: cout<<"Lan Yuan "; break;
			case 9: cout<<"Zhilan Yuan "; break;
			case 10: cout<<"Yushu Yuan "; break;
			case 11: cout<<"Underground of C Lou "; break; 
			case 12: cout<<"Underground of Guanchou Yuan "; break;
			case 13: cout<<"North of C Lou "; break;
			case 14: cout<<"Zhu Lou "; break;
			default:  cout<<"ERROR "; break; 
		}
		cout<<endl;
	} 
	//���������ĳһ�̵���ʾ
	void Operate::display_3(){
		cout<<" ";
		float b=money;
		time.display();
		cout<<"	|	";
		cout<<studentid<<"	|	";
		if(money==0){
			cout<<"0"<<endl;
		}else{
			cout<<money<<endl;
		}
	}  
//������Ĺ����빹�캯���ǳ����Ƶĸ�ֵ����
Operate putOperate(unsigned y,unsigned mon,unsigned d,unsigned h,unsigned min,
					short stor,int studid,float mey){
	Operate oppu(y,mon,d,h,min,stor,studid,mey);
	return oppu;	
} 
//�Բ�������ʱ���Ⱥ�˳��������򣨲������Ĺ鲢���� 
void sort_operate(Operate a[],int n)
{
	int middle=0;
	if(n<=1)
		return;
	middle=n/2;
	sort_operate(a,middle);
	sort_operate(a+middle,n-middle);
	Operate *tmp=new Operate [n];
	int i=0,j=middle,k=0;
	while(i<middle && j<n){
		if(comparetime(a[i].time,a[j].time)>=1){
			tmp[k]=a[i];
			k++;
			i++;
		}else{
			tmp[k]=a[j];
			k++;
			j++;
		}
	}
	for(;i<middle;i++){
		tmp[k]=a[i];
		k++;
	}
	for(;j<n;j++){
		tmp[k]=a[j];
		k++;
	}
	for(int l=0;l<n;l++){
		a[l]=tmp[l];
	}
	delete[] tmp;
} 
//����ȫ�������Ĵ��ʽ�ļ����[����ʱ��˳��](����front,������behind) 
void displayoperatefout_total(Operate*o,int front,int behind){
	if(behind<=front){
		return;
	}
	fout2<<"_________________________________________________________"<<endl;
	fout2<<"|time		 |idnum     |store		|money	|"<<endl;
	fout2<<"|________________|__________|___________________|_______|"<<endl;
	for(int i=front;i<behind;i++){
		fout2<<"|";
		o[i].time.display_fout2();
		fout2<<"|";
		fout2<<o[i].studentid<<"|";
		switch(o[i].storenum){
			case 1: fout2<<"Zijing Yuan "; break;
			case 2: fout2<<"Taoli Yuan "; break;
			case 3: fout2<<"Dingxiang Yuan "; break;
			case 4: fout2<<"Tingtao Yuan "; break;
			case 5: fout2<<"Qingfen Yuan "; break;
			case 6: fout2<<"Guanchou Yuan "; break;
			case 7: fout2<<"He Yuan 	"; break;
			case 8: fout2<<"Lan Yuan 	"; break;
			case 9: fout2<<"Zhilan Yuan "; break;
			case 10: fout2<<"Yushu Yuan	 "; break;
			case 11: fout2<<"UG of C Lou "; break; 
			case 12: fout2<<"UG of GC Yuan"; break;
			case 13: fout2<<"North of C Lou "; break;
			case 14: fout2<<"Zhu Lou 	"; break;
			default:  fout2<<"ERROR FOR WRONG STORENUM "; break; 
		}
		fout2<<"	|";
		fout2<<fixed<<setprecision(2)<<o[i].money;//�������������λС�� 
		fout2<<"	|"<<endl;
		fout2<<"|________________|__________|___________________|_______|"<<endl;
	}	
}
//����ȫ�������Ĵ��ʽ���(����front,������behind) 
void displayoperate_total(Operate*o,int front,int behind){
	if(behind<=front){
		return;
	}
	cout<<"_________________________________________________________"<<endl;
	cout<<"|time		 |idnum     |store		|money	|"<<endl;
	cout<<"|________________|__________|___________________|_______|"<<endl;
	for(int i=front;i<behind;i++){
		cout<<"|";
		o[i].time.display();
		cout<<"|";
		cout<<o[i].studentid<<"|";
		switch(o[i].storenum){
			case 1: cout<<"Zijing Yuan "; break;
			case 2: cout<<"Taoli Yuan "; break;
			case 3: cout<<"Dingxiang Yuan "; break;
			case 4: cout<<"Tingtao Yuan "; break;
			case 5: cout<<"Qingfen Yuan "; break;
			case 6: cout<<"Guanchou Yuan "; break;
			case 7: cout<<"He Yuan 	"; break;
			case 8: cout<<"Lan Yuan 	"; break;
			case 9: cout<<"Zhilan Yuan "; break;
			case 10: cout<<"Yushu Yuan	 "; break;
			case 11: cout<<"UG of C Lou "; break; 
			case 12: cout<<"UG of GC Yuan"; break;
			case 13: cout<<"North of C Lou"; break;
			case 14: cout<<"Zhu Lou 	"; break;
			default:  cout<<"ERROR FOR WRONG STORENUM "; break; 
		}
		cout<<"	|";
		cout<<fixed<<setprecision(2)<<o[i].money;//�������������λС�� 
		cout<<"	|"<<endl;
		cout<<"|________________|__________|___________________|_______|"<<endl;
	}	
}
//��ȡOperate.txt�еĳ�ʼ�ļ���Ϣ���������ж���������������ɶ���ѧ���Ĳ��� 
int finoperate(){
	unsigned year,month,day,hour,minute;
	short storenum;
	int studentid;
	float money;
	string p;
	for(int i=1;i<=8;i++){
		fin3>>p;
	}
	int sum=0;
	while(!fin3.eof()){
		if(sum%1000==0){
			int i=sum/968;
			system("cls");
			cout<<"�������������У�"<<endl; 
        	cout<<"�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�["<<endl;
        	 cout<<"�U";
    	//    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);//����Щ��ɫ
         	for(int j=0;j<i;j++)
       		{
           	 if(j==20)                
                 cout<<"���U";
             else
                 cout<<"��";            
        	}
        	for(int j=i;j<20;j++){
        		cout<<"  ";
        	} 
        	cout<<"      "<<5*i<<"%"<<endl;
            cout<<endl;       
         	cout<<"�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a"<<endl;
		}
		fin3>>storenum;
		fin3>>studentid;
		fin3>>year>>month>>day>>hour>>minute;
		fin3>>money;
		otemp[notemp]=putOperate(year,month,day,hour,minute,storenum,studentid,money);
		notemp++;
		sum++;
	}
	sort_operate(otemp,notemp);
//	for(int i=0;i<notemp;i++){
//		TOTAL_DONE(otemp[i]);
//	}
	int i=20;
	system("cls");
	cout<<"�������������У�"<<endl; 
    cout<<"�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�["<<endl;
    cout<<"�U";
//  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);//����Щ��ɫ
   	for(int j=0;j<i;j++){
    	if(j==20)                
        	cout<<"���U";
        else
            cout<<"��";            
	}
    cout<<"      "<<5*i<<"%"<<endl;
    cout<<endl;       
    cout<<"�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a"<<endl;
	return notemp;
}


#endif
