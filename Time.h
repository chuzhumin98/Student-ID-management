#ifndef TIME_H
#define TIME_H
#include<iostream>
#include<fstream>
#include "enum.h"

using namespace std;
ofstream fout2("Operatetotalfout.txt");
//输出成功操作的基本信息（表格式、站在上帝视角（按照学生排列））
ofstream fout3("Operatetotalfout2.txt");
//输出成功操作的基本信息（表格式、站在上帝视角（按照商店排列））
ofstream fout5("Operatetotalfout3.txt");
//时间类 
class Time
{protected:
	//运用位域节约内存空间，这五个变量只用了4个字节； 
	unsigned Year : 12;
	unsigned Month : 4;
	unsigned Day : 5;
	unsigned Hour : 5;
	unsigned Minute : 6;
public:
	//时间类的默认构造函数 
	Time(); 
	//时间类的带参数的构造函数 
	Time(unsigned y,unsigned mon,unsigned d,unsigned h,unsigned min);
	//时间类的展示 
	void display(); 
	//时间类的文件fout2展示 
	void display_fout2();
	//时间类的文件fout3展示 
	void display_fout3();
	//时间类的文件fout5展示 
	void display_fout5();
	//实现年、月、日、小时、分钟的读取和修改 
	unsigned getYear(){return Year;}
    void putYear(unsigned y){Year=y;} 
	unsigned getMonth(){return Month;}
    void putMonth(unsigned y){Month=y;} 
	unsigned getDay(){return Day;}
    void putDay(unsigned y){Day=y;} 
	unsigned getHour(){return Hour;}
    void putHour(unsigned y){Hour=y;} 
	unsigned getMinute(){return Minute;}
    void putMinute(unsigned y){Minute=y;} 
//	friend ostream& operator << (ostream &,Time &);
	friend void cout_singleoperate(int studentid);
}; 
//对Time类实现重载流插入运算符" << " 
ostream& operator << (ostream &out,Time &t1);
//记录上一次删除到的时间节点（避免重复操作） 
Time deletetime(2015,1,1,0,0);
//实现输入一个时间，并转化为Time类的变量
Time time_cin(); 
//比较两个时间，如果前者大则输出largecc,如果后者大则输出smallcc,如果相等则输出equal 
Comparecc comparetime(Time &,Time &);


//时间类的默认构造函数 
	Time::Time(){
		Year=2015;
		Month=1;
		Day=1;
		Hour=0;
		Minute=0;
	}

	//时间类的展示 
	void Time::display(){
		cout<<Year<<"/";
		if(Month<10)
			cout<<"0";
		cout<<Month<<"/";
		if(Day<10)
			cout<<"0";
		cout<<Day<<" ";
		if(Hour<10)
			cout<<"0";
		cout<<Hour<<":";
		if(Minute<10)
			cout<<"0";
		cout<<Minute;
	}
	//时间类的文件fout5展示 
	void Time::display_fout5(){
		fout5<<Year<<"/";
		if(Month<10)
			fout5<<"0";
		fout5<<Month<<"/";
		if(Day<10)
			fout5<<"0";
		fout5<<Day<<" ";
		if(Hour<10)
			fout5<<"0";
		fout5<<Hour<<":";
		if(Minute<10)
			fout5<<"0";
		fout5<<Minute;
	}
	//时间类的文件fout3展示 
	void Time::display_fout3(){
		fout3<<Year<<"/";
		if(Month<10)
			fout3<<"0";
		fout3<<Month<<"/";
		if(Day<10)
			fout3<<"0";
		fout3<<Day<<" ";
		if(Hour<10)
			fout3<<"0";
		fout3<<Hour<<":";
		if(Minute<10)
			fout3<<"0";
		fout3<<Minute;
	}
	//时间类的文件fout2展示 
	void Time::display_fout2(){
		fout2<<Year<<"/";
		if(Month<10)
			fout2<<"0";
		fout2<<Month<<"/";
		if(Day<10)
			fout2<<"0";
		fout2<<Day<<" ";
		if(Hour<10)
			fout2<<"0";
		fout2<<Hour<<":";
		if(Minute<10)
			fout2<<"0";
		fout2<<Minute;
	}
	//时间类的带参数的构造函数 
	Time::Time(unsigned y,unsigned mon,unsigned d,unsigned h,unsigned min){
		Year=y;
		Month=mon;
		Day=d;
		Hour=h;
		Minute=min;
	}
//对Time类实现重载流插入运算符" << " 
ostream& operator << (ostream &out,Time &t1){
	out<<t1.getYear()<<"/";
	if(t1.getMonth()<10)
		out<<"0";
	out<<t1.getMonth()<<"/";
	if(t1.getDay()<10)
		out<<"0";
	out<<t1.getDay()<<" ";
	if(t1.getHour()<10)
		out<<"0";
	out<<t1.getHour()<<":";
	if(t1.getMinute()<10)
		out<<"0";
	out<<t1.getMinute();
	return out;
}
//实现输入一个时间，并输出为Time类的变量
Time time_cin(){
	unsigned y,m,d,h,mi;
	cin>>y>>m>>d>>h>>mi;
	Time t1(y,m,d,h,mi);
	return t1;
}
//比较两个时间，如果前者大则输出largecc,如果后者大则输出smallcc,如果相等则输出equal  
Comparecc comparetime(Time &t1,Time &t2){
	unsigned a1=t1.getYear();
	unsigned a2=t2.getYear();
	if(a1>a2){
		return largecc;
	}
	if(a1<a2){
		return smallcc;
	}
	unsigned b1=t1.getMonth();
	unsigned b2=t2.getMonth();
	if(b1>b2){
		return largecc;
	}
	if(b1<b2){
		return smallcc;
	}
	unsigned c1=t1.getDay();
	unsigned c2=t2.getDay();
	if(c1>c2){
		return largecc;
	}
	if(c1<c2){
		return smallcc;
	}
	unsigned d1=t1.getHour();
	unsigned d2=t2.getHour();
	if(d1>d2){
		return largecc;
	}
	if(d1<d2){
		return smallcc;
	}
	unsigned e1=t1.getMinute();
	unsigned e2=t2.getMinute();
	if(e1>e2){
		return largecc;
	}
	if(e1<e2){
		return smallcc;
	} 
	return equalcc;
} 

#endif
