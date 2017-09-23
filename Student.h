#ifndef STUDENT_H
#define STUDENT_H
#include<iomanip>
#include<windows.h>
#include"enum.h"
#include"Time.h"
#include"Mcard.h"
#include"Operate.h"
#include "store.h"
//学生顺序表初始存储空间的大小 
#define LISTSTUDENT_MAX_SIZE 15000
//学生顺序表的存储空间增量
#define LISTSTUDENT_INCREMENT 10
//密钥1：模9余1、5、7
#define secret_key1 -28903287 
//密钥2：模9余0、2、3 
#define secret_key2 468374
//密钥3：模9余4、6、8
#define secret_key3 957928929
using namespace std;
//输入学生的原始基本信息 
ifstream fin1("Student.txt");
//输出学生的操作后基本信息（display模式） 
ofstream fout1("Studentfout.txt"); 
//输出学生操作后的基本信息（与输入形式相同） 
ofstream fout4("Studentnew.txt");
//学生类 
class Student
{protected:
	int password;//密码 
	int passby;//密码通过密钥运算所得的值 
	string Name;
	int stucard;//学生学号 
	Sex sex : 1;
	Level level : 3;
	unsigned syear : 12;//入学年份 
	float money;
	Mcard mcard;//银行卡 
public:
	//学生类的默认构造函数 
	Student(); 
	//学生类的带参数值的构造函数 
	Student(string na,int sc,Sex se,Level le,float mo,float m);
	float getmoney(){return money;}
	void putmoney(float m){money=m;}
	int getstucard(){return stucard;}
	int getpassby(){return passby;}
	int getsex(){return int(sex);}
	//学生类的信息展示函数 
	void display();
	//学生类的文件信息展示函数 
	void display_fout();
	//圈存函数，同时输出圈存是否成功 
	Status quancunmoney(float q);
	//圈存函数，同时输出圈存是否成功 (无cout型，适用于初始载入） 
	Status pre_quancunmoney(float q);
	friend Status changeforstudent(Operate &);
	friend Status pre_changeforstudent(Operate &);
	friend Status ifoperateforstudent(Operate &); 
	friend Student putStudent(string ,int ,Sex ,Level ,float ,float );
	friend void operatetostudent(Operate &);
	friend void operate_cin(); 
	friend void displaystudentfout_total();
	friend void CD_cin();
	friend void CW_cin();
	friend void password_fout(); 
	friend void MSG_cin(); 
};
//学生类的功能与构造函数非常类似的赋值函数 
Student putStudent(string na,int sc,Sex se,Level le,float mo,float m);
//对学生类的顺序表赋初始最大规模限额值 
int listsize=LISTSTUDENT_MAX_SIZE; 
//建立学生类的顺序表s 
Student *s=new Student [listsize]; 
//作为变换顺序表长度时的中转量 
Student *stmp;
//消费或圈存造成学生卡以及银行卡金额的改变(考虑学生不存在的情况） 
Status changeforstudent(Operate &);
//消费或圈存造成学生卡以及银行卡金额的改变(考虑学生不存在的情况）(无cout,适用于初始载入） 
Status pre_changeforstudent(Operate &);
//判断是否能对该学生进行操作（不改变相关值）
Status ifoperateforstudent(Operate &); 
//读取Student.txt中的初始文件信息，同时输出学生个数 
int finstudent();
//按照学号折半查找学生 
int bin_Search_Student(int);
//记载载入的学生总数，同时完成对学生基本信息的载入 
int n=finstudent();
//将一条操作记录记载到Operate类顺序表中 
void tooperate(Operate&); 
//【联合专用】将一条操作记录记载到Operate类顺序表中 (考虑：学号不存在；商店号有误；学生操作是否可行） 
void untooperate(Operate&);
//综合显示单次操作（学生情况+操作记录+学生类操作顺序表改变）
void display_totalforsingle(Operate &); 
//对于一个新加入的操作变量实现全方位的任务：学生类、三大操作顺序表以及显示功能 
void TOTAL_DONE(Operate &); 
//对于一个新加入的操作变量实现全方位的任务：学生类、操作顺序表以及显示功能(无cout型，适用于初始载入） 
void pre_TOTAL_DONE(Operate &);
//实现一个输入函数对操作类顺序表、学生类中操作顺序表的掌控 
void operate_cin(); 
//对学生按照学生学号从小到大进行排序（采用最快的归并排序） 
void sort_student(Student a[],int n);
//输出一个学生的操作项
void cout_singleoperate(int studentid);
//输出一个商店的操作项
void cout_storeoperate(int storenum); 
//输出一定时间内的操作项 
void cout_timelimit(Time t1,Time t2); 
//对于全部操作的打表式文件输出[按照学生顺序](包括front,不包括behind)
void displayoperatefout2_total(); 
//对于全部操作的打表式文件输出[按照商店顺序](包括front,不包括behind)
void displayoperatefout3_total();
//输出所有学生的基本信息（与输入形式相同）
void displaystudentfout_total(); 
//对学生进行密码鉴定
Status log_in(int l);



	//学生类的默认构造函数
	Student::Student(){
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
	}  
	//学生类的带参数值的构造函数 
	Student::Student(string na,int sc,Sex se,Level le,float mo,float m){
		Name=na;
		stucard=sc;
		sex=se;
		level=le;
		syear=sc/1000000;
		money=mo;
		mcard.putMoney(m);
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
	}
	//学生类的文件信息展示函数 
	void Student::display_fout(){
		fout1<<"For a student......"<<endl;
		fout1<<"Name: "<<Name<<endl;
		fout1<<"Student number: "<<stucard<<endl;
		fout1<<"Sex: ";
		if(sex){
			fout1<<"male"<<endl;
		}else{
			fout1<<"female"<<endl;
		}
		fout1<<"Level: ";
		switch(level){
			case one: fout1<<"one "; break;
			case two: fout1<<"two "; break;
			case three: fout1<<"three "; break;
			case four: fout1<<"four "; break;
			default: fout1<<"ERROR "; break;
		}
		fout1<<endl;
		fout1<<"Starting year: "<<syear<<endl;
		fout1<<"Money in student card: "<<money<<endl;
		fout1<<"Money in credit card: "<<mcard.getMoney()<<endl;
	}
	//学生类的信息展示函数 
	void Student::display(){
		cout<<"For a student......"<<endl;
		cout<<"Name: "<<Name<<endl;
		cout<<"Student number: "<<stucard<<endl;
		cout<<"Sex: ";
		if(sex){
			cout<<"male"<<endl;
		}else{
			cout<<"female"<<endl;
		}
		cout<<"Level: ";
		switch(level){
			case one: cout<<"one "; break;
			case two: cout<<"two "; break;
			case three: cout<<"three "; break;
			case four: cout<<"four "; break;
			default: cout<<"ERROR "; break;
		}
		cout<<endl;
		cout<<"Starting year: "<<syear<<endl;
		cout<<"Money in student card: "<<money<<endl;
		cout<<"Money in credit card: "<<mcard.getMoney()<<endl;
	}
//圈存函数，同时输出圈存是否成功 (无cout型，适用于初始载入） 
	Status Student::pre_quancunmoney(float q){
		float r=mcard.getMoney();
		Status p;
		if(q<10 || q>400){
			p=failure;
		}else{
			p=mcard.withdrawMoney(q);
			if(p){
				money+=q; 
			}
		}
		return p;
	}
	//圈存函数，同时输出圈存是否成功 
	Status Student::quancunmoney(float q){
		float r=mcard.getMoney();
		Status p;
		if(q<10 || q>400){
			cout<<"Fail for Quancun because of the sum is out of "
				<<"the range: 10~400 "<<endl;
			p=failure;
		}else{
			p=mcard.withdrawMoney(q);
			if(p){
				money+=q; 
				cout<<"Succeed for Quancun"<<endl;
			}else{
				cout<<"Fail for Quancun because of the lacking of money "
					<<"in credit card "<<endl;
			}
		}
		cout<<"The money left in studentcard: ";
		cout<<money<<endl;
		cout<<"The money left in credit card: ";
		cout<<mcard.getMoney()<<endl;
		return p;
	}
	
	//学生类的功能与构造函数非常类似的赋值函数 
Student putStudent(string na,int sc,Sex se,Level le,float mo,float m){
	Student p;
	p.Name=na;
	p.stucard=sc;
	p.sex=se;
	p.level=le;
	p.syear=sc/1000000;
	p.money=mo;
	p.mcard.putMoney(m);
	p.password=p.stucard;
	switch(p.stucard%9){
		case 1:
		case 5:
		case 7: p.passby=p.password^secret_key1; break;
		case 0:
		case 2:
		case 3: p.passby=p.password^secret_key2; break;
		case 4:
		case 6:
		case 8: p.passby=p.password^secret_key3; break;
		default: cout<<"ERROR"<<endl; break;
	} 
	return p;
}
//消费或圈存造成学生卡以及银行卡金额的改变(考虑学生不存在的情况） 
Status changeforstudent(Operate &o){
	Status a=ifoperateforstorenum(o);//判断商店方是否可行
	if(!a){
		return failure;
	}
	cout<<"Start to Operate......"<<endl;
	int p=o.getstudentid();
	int i=bin_Search_Student(p);
	if(i==-1){
		cout<<"Fail for not existing this student"<<endl;
		return failure;
	}
	float q=s[i].getmoney();
	float r=o.getmoney();
	if(r==0){
		cout<<"Do nothing "<<endl;
		return success;
	}
	if(r>0){
		return s[i].quancunmoney(r);
	} 
	if(q+r<0){
		cout<<"Fail for Comsume because of the lacking of money in "
			<<"studentcard "<<endl; 
		cout<<"The money left in the studentcard: ";
		cout<<q<<endl;
		return failure;
	}else{
		s[i].putmoney(q+r);
		cout<<"Succeed for consume "<<endl;
		cout<<"The money left in the studentcard: ";
		cout<<q+r<<endl;
		return success;
	}
}
//消费或圈存造成学生卡以及银行卡金额的改变(考虑学生不存在的情况）(无cout,适用于初始载入） 
Status pre_changeforstudent(Operate &o){
	Status a=pre_ifoperateforstorenum(o);//判断商店方是否可行
	if(!a){
		return failure;
	}
	int p=o.getstudentid();
	int i=bin_Search_Student(p);
	if(i==-1){
		return failure;
	}
	float q=s[i].getmoney();
	float r=o.getmoney();
	if(r==0){
		return success;
	}
	if(r>0){
		return s[i].pre_quancunmoney(r);
	} 
	if(q+r<0){
		return failure;
	}else{
		s[i].putmoney(q+r);
		return success;
	}
}
//按照学号折半查找学生在顺序表中的位置 
int bin_Search_Student(int p){
	int low=0,high=n-1,mid=(low+high)/2;
	while(low<=high){
		if(s[mid].getstucard()>p){
			high=mid-1;
			mid=(low+high)/2;
			continue;
		}	
		if(s[mid].getstucard()<p){
			low=mid+1;
			mid=(low+high)/2;
			continue;
		}
		if(s[mid].getstucard()==p){
			return mid;
		}
	}
	return -1;
}
//读取Student.txt中的初始文件信息，同时输出学生个数 
int finstudent(){
	string p;
	for(int i=1;i<=6;i++){
		fin1>>p;
	}
	int n=0;
	while(p!=""){
		string a1,a3,a4;
		Sex sex;
		Level level;
		int a2;
		float a5,a6;
		fin1>>a1>>a2>>a3>>a4>>a5>>a6;
		p=a1;
		if(p==""){
			break;
		}
		if(a3=="male"){
			sex=male;
		}else{
			sex=female;
		}
		if(a4=="one"){
			level=one;
		}
		if(a4=="two"){
			level=two;
		}
		if(a4=="three"){
			level=three;
		}
		if(a4=="four"){
			level=four;
		}
		if(n>=listsize){
			listsize+=LISTSTUDENT_INCREMENT;
			stmp=new Student[listsize];
			for(int i=0;i<n;i++){
				stmp[i]=s[i];
			} 
			delete []s;
			s=new Student [listsize];
			for(int i=0;i<n;i++){
				s[i]=stmp[i];
			}
			delete []stmp;
		}
		s[n]=putStudent(a1,a2,sex,level,a5,a6);
		n++; 
//		cout<<a1<<" "<<a2<<" "<<sex<<" "<<level<<" "<<a5<<" "<<a6<<endl; 
	}
	return n;
}
//判断是否能对该学生进行操作（不改变相关值）
Status ifoperateforstudent(Operate &o){
	int p=o.getstudentid();
	int i=bin_Search_Student(p);
	//检查是否有该学号的同学 
	if(i==-1){
		return failure;
	}
	float q=s[i].getmoney();
	float r=o.getmoney();
	if(r==0){
		return success;
	}
	if(r>0){
		float a=s[i].mcard.getMoney();
		//圈存金额是否满足从10~400 
		if(r<10 || r>400){
			return failure;
		}else{
			//银行卡中的钱是否能够满足圈存所需费用 
			if(a>=r){
				return success;
			}else{
				return failure;
			}
		}
	}
		//学生卡中的钱是否能够满足消费需求 
	if(q+r<0){
		return failure;
	}else{
		return success;
	} 
}
//将一条操作记录记载到Operate类顺序表中 (考虑：学号不存在；商店号有误；学生操作是否可行） 
void tooperate(Operate&o){
	Status a=ifoperateforstorenum(o);//判断商店方是否可行
	Status b=ifoperateforstudent(o); //判断学生方是否可行 
	//实现对于操作类顺序表大小的扩充 
	if(noperate>=listsizeoperate){
		listsizeoperate+=LISTOPERATE_INCREMENT;
		otmp=new Operate [listsizeoperate];
		for(int i=0;i<noperate;i++){
			otmp[i]=operate[i];
		}
		delete []operate;
		operate=new Operate [listsizeoperate];
		for(int i=0;i<noperate;i++){
			operate[i]=otmp[i];
		}
		delete []otmp;
	}
	int p=o.getstudentid();//获取学生学号 
	int t=bin_Search_Student(p);//通过折半查找找到这个学生在顺序表中的位置 
	if(t!=-1 && a && b){
		operate[noperate]=o;
		operate[noperate].much=twice;
		noperate++;
	}
}
//【联合专用】将一条操作记录记载到Operate类顺序表中 (考虑：学号不存在；商店号有误；学生操作是否可行） 
void untooperate(Operate&o){
	//实现对于操作类顺序表大小的扩充 
	if(noperate>=listsizeoperate){
		listsizeoperate+=LISTOPERATE_INCREMENT;
		otmp=new Operate [listsizeoperate];
		for(int i=0;i<noperate;i++){
			otmp[i]=operate[i];
		}
		delete []operate;
		operate=new Operate [listsizeoperate];
		for(int i=0;i<noperate;i++){
			operate[i]=otmp[i];
		}
		delete []otmp;
	}
	int p=o.getstudentid();//获取学生学号 
	int t=bin_Search_Student(p);//通过折半查找找到这个学生在顺序表中的位置 
	if(t!=-1){
		operate[noperate].storenum=o.storenum;
		operate[noperate].studentid=o.studentid;
		operate[noperate].time=o.time;
		operate[noperate].money=o.money;
		operate[noperate].much=twice;
		noperate++;
	}
}
//综合显示单次操作（学生情况+操作记录+学生类操作顺序表改变）  
void display_totalforsingle(Operate &o){
	Status p=changeforstudent(o);
	Status a=ifoperateforstorenum(o);//判断商店方是否可行
	if(p && a){
		o.display_1();
	}
}
//对于一个新加入的操作变量实现全方位的任务：学生类、操作顺序表以及显示功能 
void TOTAL_DONE(Operate &o){
	Status p=changeforstudent(o);//完成改变 
	Status a=ifoperateforstorenum(o);//判断商店方是否可行
	if(a && p){
		untooperate(o);
	}
} 
//对于一个新加入的操作变量实现全方位的任务：学生类、操作顺序表以及显示功能(无cout型，适用于初始载入） 
void pre_TOTAL_DONE(Operate &o){
	Status p=pre_changeforstudent(o);//完成改变 
	Status a=pre_ifoperateforstorenum(o);//判断商店方是否可行
	if(a && p){
		untooperate(o);
	}
} 
//实现一个输入函数对操作类顺序表、学生类中操作顺序表的掌控 
void operate_cin(){
	char type;
	int id;
	short num;
	float money;
	unsigned year,month,day,hour,minute;
	cout<<"format: C/D storenum studentid time(year month day hour minute) money(all positive)"<<endl;
	cin>>type>>num>>id>>year>>month>>day>>hour>>minute>>money;
	if(type=='D'){
		Operate tmp(year,month,day,hour,minute,num,id,money);
		tooperate(tmp);
		display_totalforsingle(tmp);
	}
	if(type=='C'){
		Operate tmp(year,month,day,hour,minute,num,id,-money);
		tooperate(tmp);
		display_totalforsingle(tmp);
	}
} 
//对学生按照学生学号进行排序 
void sort_student(Student a[],int n)   //这是从小到大排序 
{
	int middle=0;
	if(n<=1)
		return;
	middle=n/2;
	sort_student(a,middle);
	sort_student(a+middle,n-middle);
	Student *tmp=new Student [n];
	int i=0,j=middle,k=0;
	while(i<middle && j<n){
		if(a[i].getstucard()<a[j].getstucard()){
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
//输出一个商店的操作项
void cout_storeoperate(int storenum){
	if(storenum<=0 || storenum>=15){
		cout<<"Wrong store number "<<endl;
		return;
	}
	int sum=0;
	for(int i=0;i<noperate;i++){
		if(operate[i].storenum==storenum){
			if(sum==0){
				cout<<"_________________________________________________________"<<endl;
				cout<<"|time		 |idnum     |store		|money	|"<<endl;
				cout<<"|________________|__________|___________________|_______|"<<endl;
			}
			cout<<"|";
			operate[i].time.display();
			cout<<"|";
			cout<<operate[i].studentid<<"|";
			switch(operate[i].storenum){
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
			cout<<fixed<<setprecision(2)<<operate[i].money;//控制输出保留两位小数 
			cout<<"	|"<<endl;
			cout<<"|________________|__________|___________________|_______|"<<endl;
			sum++;
		}
	}
	if(sum==0){
		cout<<"Sorry, there is no operate for this store "<<endl;
	}
}
//输出一个学生的操作项
void cout_singleoperate(int studentid){
	int p=bin_Search_Student(studentid);
	if(p==-1){
		cout<<"Sorry, there not exists this student! "<<endl;
		return;
	}
	int sum=0;
	for(int i=0;i<noperate;i++){
		if(operate[i].getstudentid()==studentid){
			if(sum==0){
				cout<<"_________________________________________________________"<<endl;
				cout<<"|time		 |idnum     |store		|money	|"<<endl;
				cout<<"|________________|__________|___________________|_______|"<<endl;
			}
			cout<<"|";
			operate[i].time.display();
			cout<<"|";
			cout<<operate[i].studentid<<"|";
			switch(operate[i].storenum){
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
			cout<<fixed<<setprecision(2)<<operate[i].money;//控制输出保留两位小数 
			cout<<"	|"<<endl;
			cout<<"|________________|__________|___________________|_______|"<<endl;
			sum++;
		}
	}
	if(sum==0){
		cout<<"Sorry, there is no operate for this student "<<endl;
	}	
}
//输出一定时间内的操作项 
void cout_timelimit(Time t1,Time t2){
	if(!comparetime(t1,t2)){
		cout<<"Sorry, wrong input of time limits "<<endl;
		return;
	}
	int sum=0;
	for(int i=0;i<noperate;i++){
		if(comparetime(t1,operate[i].time)){
			if((int)comparetime(operate[i].time,t2)){
				if(sum==0){
				cout<<"_________________________________________________________"<<endl;
				cout<<"|time		 |idnum     |store		|money	|"<<endl;
				cout<<"|________________|__________|___________________|_______|"<<endl;
				}
				cout<<"|";
				operate[i].time.display();
				cout<<"|";
				cout<<operate[i].studentid<<"|";
				switch(operate[i].storenum){
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
				cout<<fixed<<setprecision(2)<<operate[i].money;//控制输出保留两位小数 
				cout<<"	|"<<endl;
				cout<<"|________________|__________|___________________|_______|"<<endl;
				sum++;
			}else{
				break;
			}
		}
	}
	if(!sum){
		cout<<"Sorry, non-existing operates during this time "<<endl; 
	}
} 
//对于全部操作的打表式文件输出[按照学生顺序](包括front,不包括behind)
void displayoperatefout2_total(){
	fout3<<"_________________________________________________________"<<endl;
	fout3<<"|time		 |idnum     |store		|money	|"<<endl;
	fout3<<"|________________|__________|___________________|_______|"<<endl;
	int sum=0;
	for(int i=0;i<n;i++){
		sum++;
		if(sum%752==0){
			int i=sum/752;
			system("cls");
			cout<<"正在保存数据中："<<endl; 
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
		for(int j=0;j<noperate;j++){
			if(operate[j].getstudentid()==s[i].getstucard()){
				fout3<<"|";
				operate[j].time.display_fout3();
				fout3<<"|";
				fout3<<operate[j].studentid<<"|";
				switch(operate[j].storenum){
					case 1: fout3<<"Zijing Yuan "; break;
					case 2: fout3<<"Taoli Yuan "; break;
					case 3: fout3<<"Dingxiang Yuan "; break;
					case 4: fout3<<"Tingtao Yuan "; break;
					case 5: fout3<<"Qingfen Yuan "; break;
					case 6: fout3<<"Guanchou Yuan "; break;
					case 7: fout3<<"He Yuan 	"; break;
					case 8: fout3<<"Lan Yuan 	"; break;
					case 9: fout3<<"Zhilan Yuan "; break;
					case 10: fout3<<"Yushu Yuan	 "; break;
					case 11: fout3<<"UG of C Lou "; break; 
					case 12: fout3<<"UG of GC Yuan"; break;
					case 13: fout3<<"North of C Lou"; break;
					case 14: fout3<<"Zhu Lou 	"; break;
					default:  fout3<<"ERROR FOR WRONG STORENUM "; break; 
				}
				fout3<<"	|";
				fout3<<fixed<<setprecision(2)<<operate[j].money;//控制输出保留两位小数 
				fout3<<"	|"<<endl;
				fout3<<"|________________|__________|___________________|_______|"<<endl;
			}
		}
	}
}
//对于全部操作的打表式文件输出[按照商店顺序](包括front,不包括behind)
void displayoperatefout3_total(){
	fout5<<"_________________________________________________________"<<endl;
	fout5<<"|time		 |idnum     |store		|money	|"<<endl;
	fout5<<"|________________|__________|___________________|_______|"<<endl;
	for(int i=0;i<14;i++){
		for(int j=0;j<noperate;j++){
			if(operate[j].getstorenum()==i+1){
				fout5<<"|";
				operate[j].time.display_fout5();
				fout5<<"|";
				fout5<<operate[j].studentid<<"|";
				switch(operate[j].storenum){
					case 1: fout5<<"Zijing Yuan "; break;
					case 2: fout5<<"Taoli Yuan "; break;
					case 3: fout5<<"Dingxiang Yuan "; break;
					case 4: fout5<<"Tingtao Yuan "; break;
					case 5: fout5<<"Qingfen Yuan "; break;
					case 6: fout5<<"Guanchou Yuan "; break;
					case 7: fout5<<"He Yuan 	"; break;
					case 8: fout5<<"Lan Yuan 	"; break;
					case 9: fout5<<"Zhilan Yuan "; break;
					case 10: fout5<<"Yushu Yuan	 "; break;
					case 11: fout5<<"UG of C Lou "; break; 
					case 12: fout5<<"UG of GC Yuan"; break;
					case 13: fout5<<"North of C Lou"; break;
					case 14: fout5<<"Zhu Lou 	"; break;
					default:  fout5<<"ERROR FOR WRONG STORENUM "; break; 
				}
				fout5<<"	|";
				fout5<<fixed<<setprecision(2)<<operate[j].money;//控制输出保留两位小数 
				fout5<<"	|"<<endl;
				fout5<<"|________________|__________|___________________|_______|"<<endl;
			}
		}
	}
} 
//输出所有学生的基本信息（与输入形式相同）
void displaystudentfout_total(){
	fout4<<"Name			Studentid	Sex	Level	Money_stu	Money_credit"<<endl;
	for(int i=0;i<n;i++){
		fout4<<s[i].Name;
		int ji=s[i].Name.length();
		if(ji<=7){
			fout4<<"			";
		}
		if(ji>=8 && ji<=15){
			fout4<<"		";
		}
		if(ji>=16){
			fout4<<"	";
		} 
		fout4<<s[i].stucard<<"	";
		if(!s[i].sex){
			fout4<<"female	";
		}else{
			fout4<<"male	";
		}
		int ji2=(int)s[i].level;
		switch(ji2){
			case 1: fout4<<"one	"; break;
			case 2: fout4<<"two	"; break;
			case 3: fout4<<"three	"; break;
			case 4: fout4<<"four	"; break;
			default: fout4<<"zero	"; break;
		}
		//输出时控制保留两位小数 
		fout4<<fixed<<setprecision(2)<<s[i].money<<"		";
		fout4<<fixed<<setprecision(2)<<s[i].mcard.getMoney()<<endl;
	} 
}
//对学生进行密码鉴定
Status log_in(int l){
	int t=bin_Search_Student(l);
	if(t==-1){
		cout<<"Wrong id number! "<<endl;
		return failure;
	}
	cout<<"input your password: ";
	int p;
	cin>>p;
	if(s[t].getpassby()==p){
		cout<<"Succeed log in! "<<endl;
		return success;
	}else{
		cout<<"Wrong password! "<<endl;
		return failure;
	}
} 

#endif
