#ifndef _MCARD_H
#define _MACRD_H
#include<iostream>
#include "enum.h"
//���п��� 
class Mcard
{protected:
	float Money;
public:
	//Ĭ�Ϲ��캯�� 
	Mcard(){Money=0;}
	Mcard(float m){Money=m;} 
	float getMoney(){return Money;}
	void putMoney(float m){Money=m;}
	void depositMoney(float d){Money+=d;} 
	//�����п���ȡǮ 
	Status withdrawMoney(float w);
}; 
	//�����п���ȡǮ 
	Status Mcard::withdrawMoney(float w){
		if(w>Money){
			return failure;
		}else{
			Money-=w;
			return success;
		}
	}
#endif
