#ifndef _MCARD_H
#define _MACRD_H
#include<iostream>
#include "enum.h"
//银行卡类 
class Mcard
{protected:
	float Money;
public:
	//默认构造函数 
	Mcard(){Money=0;}
	Mcard(float m){Money=m;} 
	float getMoney(){return Money;}
	void putMoney(float m){Money=m;}
	void depositMoney(float d){Money+=d;} 
	//从银行卡中取钱 
	Status withdrawMoney(float w);
}; 
	//从银行卡中取钱 
	Status Mcard::withdrawMoney(float w){
		if(w>Money){
			return failure;
		}else{
			Money-=w;
			return success;
		}
	}
#endif
