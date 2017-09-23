#ifndef TIME_H
#define TIME_H
#include<iostream>
#include<fstream>
#include "enum.h"

using namespace std;
ofstream fout2("Operatetotalfout.txt");
//����ɹ������Ļ�����Ϣ�����ʽ��վ���ϵ��ӽǣ�����ѧ�����У���
ofstream fout3("Operatetotalfout2.txt");
//����ɹ������Ļ�����Ϣ�����ʽ��վ���ϵ��ӽǣ������̵����У���
ofstream fout5("Operatetotalfout3.txt");
//ʱ���� 
class Time
{protected:
	//����λ���Լ�ڴ�ռ䣬���������ֻ����4���ֽڣ� 
	unsigned Year : 12;
	unsigned Month : 4;
	unsigned Day : 5;
	unsigned Hour : 5;
	unsigned Minute : 6;
public:
	//ʱ�����Ĭ�Ϲ��캯�� 
	Time(); 
	//ʱ����Ĵ������Ĺ��캯�� 
	Time(unsigned y,unsigned mon,unsigned d,unsigned h,unsigned min);
	//ʱ�����չʾ 
	void display(); 
	//ʱ������ļ�fout2չʾ 
	void display_fout2();
	//ʱ������ļ�fout3չʾ 
	void display_fout3();
	//ʱ������ļ�fout5չʾ 
	void display_fout5();
	//ʵ���ꡢ�¡��ա�Сʱ�����ӵĶ�ȡ���޸� 
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
//��Time��ʵ�����������������" << " 
ostream& operator << (ostream &out,Time &t1);
//��¼��һ��ɾ������ʱ��ڵ㣨�����ظ������� 
Time deletetime(2015,1,1,0,0);
//ʵ������һ��ʱ�䣬��ת��ΪTime��ı���
Time time_cin(); 
//�Ƚ�����ʱ�䣬���ǰ�ߴ������largecc,������ߴ������smallcc,�����������equal 
Comparecc comparetime(Time &,Time &);


//ʱ�����Ĭ�Ϲ��캯�� 
	Time::Time(){
		Year=2015;
		Month=1;
		Day=1;
		Hour=0;
		Minute=0;
	}

	//ʱ�����չʾ 
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
	//ʱ������ļ�fout5չʾ 
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
	//ʱ������ļ�fout3չʾ 
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
	//ʱ������ļ�fout2չʾ 
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
	//ʱ����Ĵ������Ĺ��캯�� 
	Time::Time(unsigned y,unsigned mon,unsigned d,unsigned h,unsigned min){
		Year=y;
		Month=mon;
		Day=d;
		Hour=h;
		Minute=min;
	}
//��Time��ʵ�����������������" << " 
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
//ʵ������һ��ʱ�䣬�����ΪTime��ı���
Time time_cin(){
	unsigned y,m,d,h,mi;
	cin>>y>>m>>d>>h>>mi;
	Time t1(y,m,d,h,mi);
	return t1;
}
//�Ƚ�����ʱ�䣬���ǰ�ߴ������largecc,������ߴ������smallcc,�����������equal  
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
