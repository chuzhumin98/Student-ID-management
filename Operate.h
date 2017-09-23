#ifndef OPERATE_H
#define OPERATE_H 
#include "enum.h"
#include "Time.h"
#include<iostream>
#include<fstream>
#include<iomanip>
#include<windows.h>
//操作类顺序表的初始储存空间的大小 
#define LISTOPERATE_MAX_SIZE 20000
//操作类顺序表的存储空间增量
#define LISTOPERATE_INCREMENT 20 
using namespace std;
//输入操作的基本信息 
ifstream fin3("Operate.txt");
int listsizeoperate=LISTOPERATE_MAX_SIZE;
//操作类 
class Operate
{protected:
	short storenum;//商店编号 
	int studentid;//学生学号 
	Time time;
	float money;
	MUCH much : 2;//记录次数 
public:
	//操作类的默认构造函数 
	Operate(); 
	//Operate(年，月，日，时，分，商店编号，学生号，金额)
	Operate(unsigned y,unsigned mon,unsigned d,unsigned h,unsigned min,
			short stor,int studid,float mey);
	//针对单次操作的显示 
	void display_1(); 
	//针对某一个人的表示
	void display_2();
	//针对某一商店显示 
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
//操作类的功能与构造函数非常类似的赋值函数
Operate putOperate(unsigned y,unsigned mon,unsigned d,unsigned h,unsigned min,
					short stor,int studid,float mey);

//Operate类的顺序表 
Operate* operate=new Operate [listsizeoperate];
//记载Operate类顺序表中所存储的操作记录的条数 
int noperate=0;
//作为顺序表变换大小时的中转存储空间
Operate* otmp; 
//文件中载入的操作的暂存空间
Operate* otemp=new Operate[LISTOPERATE_MAX_SIZE];
//记载otemp顺序表中所存储的操作记录的条数
int notemp=0; 
//对操作按照时间先后顺序进行排序（采用最快的归并排序） 
void sort_operate(Operate a[],int n);
//对于全部操作的打表式输出(包括front,不包括behind) 
void displayoperate_total(Operate*o,int front,int behind); 
//对于全部操作的打表式文件输出[按照时间顺序](包括front,不包括behind) 
void displayoperatefout_total(Operate*o,int front,int behind); 
//读取Operate.txt中的初始文件信息，并将其中对象进行排序甄别，完成对于学生的操作 
int finoperate();






	//操作类的默认构造函数 
	Operate::Operate(){
		storenum=1;
		studentid=2015000000;
		money=0;
		much=twice;
	}
	//Operate(年，月，日，时，分，商店编号，学生号，金额)
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
	//操作类针对单次操作显示
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
	//操作类针对某一个人显示
	void Operate::display_2(){
		cout<<" "; 
		float b=money;
		time.display();
		cout<<"	|	";//这个地方注意安排一个打表 
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
	//操作类针对某一商店显示
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
//操作类的功能与构造函数非常类似的赋值函数
Operate putOperate(unsigned y,unsigned mon,unsigned d,unsigned h,unsigned min,
					short stor,int studid,float mey){
	Operate oppu(y,mon,d,h,min,stor,studid,mey);
	return oppu;	
} 
//对操作按照时间先后顺序进行排序（采用最快的归并排序） 
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
//对于全部操作的打表式文件输出[按照时间顺序](包括front,不包括behind) 
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
		fout2<<fixed<<setprecision(2)<<o[i].money;//控制输出保留两位小数 
		fout2<<"	|"<<endl;
		fout2<<"|________________|__________|___________________|_______|"<<endl;
	}	
}
//对于全部操作的打表式输出(包括front,不包括behind) 
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
		cout<<fixed<<setprecision(2)<<o[i].money;//控制输出保留两位小数 
		cout<<"	|"<<endl;
		cout<<"|________________|__________|___________________|_______|"<<endl;
	}	
}
//读取Operate.txt中的初始文件信息，并将其中对象进行排序甄别，完成对于学生的操作 
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
			cout<<"正在载入数据中："<<endl; 
        	cout<<"╔═════════════════════╗"<<endl;
        	 cout<<"║";
    	//    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);//加了些颜色
         	for(int j=0;j<i;j++)
       		{
           	 if(j==20)                
                 cout<<"█║";
             else
                 cout<<"█";            
        	}
        	for(int j=i;j<20;j++){
        		cout<<"  ";
        	} 
        	cout<<"      "<<5*i<<"%"<<endl;
            cout<<endl;       
         	cout<<"╚═════════════════════╝"<<endl;
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
	cout<<"正在载入数据中："<<endl; 
    cout<<"╔═════════════════════╗"<<endl;
    cout<<"║";
//  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);//加了些颜色
   	for(int j=0;j<i;j++){
    	if(j==20)                
        	cout<<"█║";
        else
            cout<<"█";            
	}
    cout<<"      "<<5*i<<"%"<<endl;
    cout<<endl;       
    cout<<"╚═════════════════════╝"<<endl;
	return notemp;
}


#endif
