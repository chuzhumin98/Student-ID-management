#ifndef THUSTUDENT_H
#define THUSTUDENT_H
#include<iostream>
#include<fstream>
#include "Student.h"
using namespace std;
//载入阳光长跑评分标准 
ifstream fin4("sunsrun.txt"); 
//Student类的派生类清华学生，增设阳光长跑项目 
class THUstudent: public Student{
protected:
	bool ifsunsrun;
	int times;
	int grade;
public:
	THUstudent();
	THUstudent(string na,int sc,Sex se,Level le,float mo,float m,int times);
	THUstudent(Student s,int tim);
	int gettimes(){return times;}
	void puttimes(int t){times=t;} 
	int getgrade(){return grade;}
	void putgrade();
	bool getifsunsrun(){return ifsunsrun;} 
}; 
//作为变换顺序表长度时的中转量
THUstudent *THUstmp;

//记录阳光长跑评分标准的数组(即得到对应分数所需跑得次数） 
int sunsrun[11];
//载入阳光长跑评分标准 
void fin_sunsrun();
THUstudent* THUs=new THUstudent [listsize];//载入清华学生类的顺序表 



//清华学生类的默认构造函数 
THUstudent::THUstudent(){
	Name="Zhang San";
	stucard=2015000000;
	sex=male;
	level=one;
	syear=2015;
	money=0;
	password=stucard;
	switch(stucard%9){
		case 1:
		case 5:
		case 7: passby=password^secret_key1; break;
		case 0:
		case 2:
		case 3: passby=password^secret_key2; break;
		case 4:
		case 6:
		case 8: passby=password^secret_key3; break;
		default: cout<<"ERROR"<<endl; break;
	}
	ifsunsrun=true;
	times=0;
	grade=0; 
}
//清华学生类的带参数的构造函数
THUstudent::THUstudent(string na,int sc,Sex se,Level le,float mo,float m,int tim)
						:Student(na,sc,se,le,mo,m){
	times=tim;
	if(le<=two){
		ifsunsrun=true;
	}else{
		ifsunsrun=false;
	}
	int i=0;
	for(;i<10;i++){
		if(times>=sunsrun[i] && times<sunsrun[i+1]){
			grade=i;
			break;
		}
	}
	if(i==10){
		grade=10;
	}
} 
//清华学生类的另一种带参数的构造函数 
THUstudent::THUstudent(Student s,int tim):Student(s){
	times=tim;
	if(level<=two){
		ifsunsrun=true;
	}else{
		ifsunsrun=false;
	}
	int i=0;
	for(;i<10;i++){
		if(times>=sunsrun[i] && times<sunsrun[i+1]){
			grade=i;
			break;
		}
	}
	if(i==10){
		grade=10;
	}
}
void THUstudent::putgrade(){
	for(int i=0;i<10;i++){
		if(times>=sunsrun[i] && times<sunsrun[i+1]){
			grade=i;
			return;
		}
	}
	grade=10;
}
//清华学生类的功能与构造函数非常类似的赋值函数  
THUstudent putTHUstudent(Student s,int tim){
	THUstudent s1(s,tim);
	return s1;
}
//载入阳光长跑评分标准 
void fin_sunsrun(){
	int m,n;
	for(int i=0;i<10;i++){
		fin4>>m>>n;
		sunsrun[n]=m;
	}
}
#endif 
