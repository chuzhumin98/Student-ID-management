#ifndef STORE_H
#define STORE_H
#include<iostream>
#include<cstring>
#include<fstream>
#include"enum.h"
#include"Operate.h"
using namespace std;
//输入商店的基本信息 
ifstream fin2("Store.txt");
//商店类
class Store
{protected:
	short storenum;//商店编号 
	string storename;//商店名字
	bool isconsume;//判断商店是否能消费
	bool isdeposit;//判断商店是否能圈存 
public:
	//商店类的默认构造函数 
	Store();
	//商店类的含参数的构造函数
	Store(short s,string name,bool isc,bool isd); 
	//获取商店编号函数
	int getstorenum(){return storenum;}
	//Store类中基本信息的展示函数
	void display(); 
	friend Store putStore(int ,string ,bool ,bool ); 
}; 

//商店类的功能与构造函数非常类似的赋值函数
Store putStore(int s,string name,bool isc,bool isd);
//定义商店类的14个变量，即14个可用商店 
Store store[14];
//用文件载入完成对商店的初始化函数 
Status finstore();
//判断是否能在所提供的商店编号中完成相关操作
Status ifoperateforstorenum(Operate &); 
//判断是否能在所提供的商店编号中完成相关操作（无cout型，适用于初始载入） 
Status pre_ifoperateforstorenum(Operate &o);



	//商店类的默认构造函数
	Store::Store(){
		storenum=0;
		storename="Unknown";
		isconsume=false;
		isdeposit=false;
	} 
	//商店类的带参数的构造函数  
	Store::Store(short s,string name,bool isc,bool isd){
		storenum=s;
		storename=name;
		isconsume=isc;
		isdeposit=isd;
	}
	//商店类的基本信息展示函数
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
//商店类的功能与构造函数非常类似的赋值函数
Store putStore(int s,string name,bool isc,bool isd){
	Store tmp;
	tmp.storenum=s;
	tmp.storename=name;
	tmp.isconsume=isc;
	tmp.isdeposit=isd;
	return tmp;
} 
//用文件载入完成对商店的初始化函数 
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
//判断是否能在所提供的商店编号中完成相关操作
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
//判断是否能在所提供的商店编号中完成相关操作（无cout型，适用于初始载入） 
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
