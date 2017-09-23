#ifndef STUDENT_H
#define STUDENT_H
#include<iomanip>
#include<windows.h>
#include"enum.h"
#include"Time.h"
#include"Mcard.h"
#include"Operate.h"
#include "store.h"
//ѧ��˳����ʼ�洢�ռ�Ĵ�С 
#define LISTSTUDENT_MAX_SIZE 15000
//ѧ��˳���Ĵ洢�ռ�����
#define LISTSTUDENT_INCREMENT 10
//��Կ1��ģ9��1��5��7
#define secret_key1 -28903287 
//��Կ2��ģ9��0��2��3 
#define secret_key2 468374
//��Կ3��ģ9��4��6��8
#define secret_key3 957928929
using namespace std;
//����ѧ����ԭʼ������Ϣ 
ifstream fin1("Student.txt");
//���ѧ���Ĳ����������Ϣ��displayģʽ�� 
ofstream fout1("Studentfout.txt"); 
//���ѧ��������Ļ�����Ϣ����������ʽ��ͬ�� 
ofstream fout4("Studentnew.txt");
//ѧ���� 
class Student
{protected:
	int password;//���� 
	int passby;//����ͨ����Կ�������õ�ֵ 
	string Name;
	int stucard;//ѧ��ѧ�� 
	Sex sex : 1;
	Level level : 3;
	unsigned syear : 12;//��ѧ��� 
	float money;
	Mcard mcard;//���п� 
public:
	//ѧ�����Ĭ�Ϲ��캯�� 
	Student(); 
	//ѧ����Ĵ�����ֵ�Ĺ��캯�� 
	Student(string na,int sc,Sex se,Level le,float mo,float m);
	float getmoney(){return money;}
	void putmoney(float m){money=m;}
	int getstucard(){return stucard;}
	int getpassby(){return passby;}
	int getsex(){return int(sex);}
	//ѧ�������Ϣչʾ���� 
	void display();
	//ѧ������ļ���Ϣչʾ���� 
	void display_fout();
	//Ȧ�溯����ͬʱ���Ȧ���Ƿ�ɹ� 
	Status quancunmoney(float q);
	//Ȧ�溯����ͬʱ���Ȧ���Ƿ�ɹ� (��cout�ͣ������ڳ�ʼ���룩 
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
//ѧ����Ĺ����빹�캯���ǳ����Ƶĸ�ֵ���� 
Student putStudent(string na,int sc,Sex se,Level le,float mo,float m);
//��ѧ�����˳�����ʼ����ģ�޶�ֵ 
int listsize=LISTSTUDENT_MAX_SIZE; 
//����ѧ�����˳���s 
Student *s=new Student [listsize]; 
//��Ϊ�任˳�����ʱ����ת�� 
Student *stmp;
//���ѻ�Ȧ�����ѧ�����Լ����п����ĸı�(����ѧ�������ڵ������ 
Status changeforstudent(Operate &);
//���ѻ�Ȧ�����ѧ�����Լ����п����ĸı�(����ѧ�������ڵ������(��cout,�����ڳ�ʼ���룩 
Status pre_changeforstudent(Operate &);
//�ж��Ƿ��ܶԸ�ѧ�����в��������ı����ֵ��
Status ifoperateforstudent(Operate &); 
//��ȡStudent.txt�еĳ�ʼ�ļ���Ϣ��ͬʱ���ѧ������ 
int finstudent();
//����ѧ���۰����ѧ�� 
int bin_Search_Student(int);
//���������ѧ��������ͬʱ��ɶ�ѧ��������Ϣ������ 
int n=finstudent();
//��һ��������¼���ص�Operate��˳����� 
void tooperate(Operate&); 
//������ר�á���һ��������¼���ص�Operate��˳����� (���ǣ�ѧ�Ų����ڣ��̵������ѧ�������Ƿ���У� 
void untooperate(Operate&);
//�ۺ���ʾ���β�����ѧ�����+������¼+ѧ�������˳���ı䣩
void display_totalforsingle(Operate &); 
//����һ���¼���Ĳ�������ʵ��ȫ��λ������ѧ���ࡢ�������˳����Լ���ʾ���� 
void TOTAL_DONE(Operate &); 
//����һ���¼���Ĳ�������ʵ��ȫ��λ������ѧ���ࡢ����˳����Լ���ʾ����(��cout�ͣ������ڳ�ʼ���룩 
void pre_TOTAL_DONE(Operate &);
//ʵ��һ�����뺯���Բ�����˳���ѧ�����в���˳�����ƿ� 
void operate_cin(); 
//��ѧ������ѧ��ѧ�Ŵ�С����������򣨲������Ĺ鲢���� 
void sort_student(Student a[],int n);
//���һ��ѧ���Ĳ�����
void cout_singleoperate(int studentid);
//���һ���̵�Ĳ�����
void cout_storeoperate(int storenum); 
//���һ��ʱ���ڵĲ����� 
void cout_timelimit(Time t1,Time t2); 
//����ȫ�������Ĵ��ʽ�ļ����[����ѧ��˳��](����front,������behind)
void displayoperatefout2_total(); 
//����ȫ�������Ĵ��ʽ�ļ����[�����̵�˳��](����front,������behind)
void displayoperatefout3_total();
//�������ѧ���Ļ�����Ϣ����������ʽ��ͬ��
void displaystudentfout_total(); 
//��ѧ�������������
Status log_in(int l);



	//ѧ�����Ĭ�Ϲ��캯��
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
	//ѧ����Ĵ�����ֵ�Ĺ��캯�� 
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
	//ѧ������ļ���Ϣչʾ���� 
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
	//ѧ�������Ϣչʾ���� 
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
//Ȧ�溯����ͬʱ���Ȧ���Ƿ�ɹ� (��cout�ͣ������ڳ�ʼ���룩 
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
	//Ȧ�溯����ͬʱ���Ȧ���Ƿ�ɹ� 
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
	
	//ѧ����Ĺ����빹�캯���ǳ����Ƶĸ�ֵ���� 
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
//���ѻ�Ȧ�����ѧ�����Լ����п����ĸı�(����ѧ�������ڵ������ 
Status changeforstudent(Operate &o){
	Status a=ifoperateforstorenum(o);//�ж��̵귽�Ƿ����
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
//���ѻ�Ȧ�����ѧ�����Լ����п����ĸı�(����ѧ�������ڵ������(��cout,�����ڳ�ʼ���룩 
Status pre_changeforstudent(Operate &o){
	Status a=pre_ifoperateforstorenum(o);//�ж��̵귽�Ƿ����
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
//����ѧ���۰����ѧ����˳����е�λ�� 
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
//��ȡStudent.txt�еĳ�ʼ�ļ���Ϣ��ͬʱ���ѧ������ 
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
//�ж��Ƿ��ܶԸ�ѧ�����в��������ı����ֵ��
Status ifoperateforstudent(Operate &o){
	int p=o.getstudentid();
	int i=bin_Search_Student(p);
	//����Ƿ��и�ѧ�ŵ�ͬѧ 
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
		//Ȧ�����Ƿ������10~400 
		if(r<10 || r>400){
			return failure;
		}else{
			//���п��е�Ǯ�Ƿ��ܹ�����Ȧ��������� 
			if(a>=r){
				return success;
			}else{
				return failure;
			}
		}
	}
		//ѧ�����е�Ǯ�Ƿ��ܹ������������� 
	if(q+r<0){
		return failure;
	}else{
		return success;
	} 
}
//��һ��������¼���ص�Operate��˳����� (���ǣ�ѧ�Ų����ڣ��̵������ѧ�������Ƿ���У� 
void tooperate(Operate&o){
	Status a=ifoperateforstorenum(o);//�ж��̵귽�Ƿ����
	Status b=ifoperateforstudent(o); //�ж�ѧ�����Ƿ���� 
	//ʵ�ֶ��ڲ�����˳����С������ 
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
	int p=o.getstudentid();//��ȡѧ��ѧ�� 
	int t=bin_Search_Student(p);//ͨ���۰�����ҵ����ѧ����˳����е�λ�� 
	if(t!=-1 && a && b){
		operate[noperate]=o;
		operate[noperate].much=twice;
		noperate++;
	}
}
//������ר�á���һ��������¼���ص�Operate��˳����� (���ǣ�ѧ�Ų����ڣ��̵������ѧ�������Ƿ���У� 
void untooperate(Operate&o){
	//ʵ�ֶ��ڲ�����˳����С������ 
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
	int p=o.getstudentid();//��ȡѧ��ѧ�� 
	int t=bin_Search_Student(p);//ͨ���۰�����ҵ����ѧ����˳����е�λ�� 
	if(t!=-1){
		operate[noperate].storenum=o.storenum;
		operate[noperate].studentid=o.studentid;
		operate[noperate].time=o.time;
		operate[noperate].money=o.money;
		operate[noperate].much=twice;
		noperate++;
	}
}
//�ۺ���ʾ���β�����ѧ�����+������¼+ѧ�������˳���ı䣩  
void display_totalforsingle(Operate &o){
	Status p=changeforstudent(o);
	Status a=ifoperateforstorenum(o);//�ж��̵귽�Ƿ����
	if(p && a){
		o.display_1();
	}
}
//����һ���¼���Ĳ�������ʵ��ȫ��λ������ѧ���ࡢ����˳����Լ���ʾ���� 
void TOTAL_DONE(Operate &o){
	Status p=changeforstudent(o);//��ɸı� 
	Status a=ifoperateforstorenum(o);//�ж��̵귽�Ƿ����
	if(a && p){
		untooperate(o);
	}
} 
//����һ���¼���Ĳ�������ʵ��ȫ��λ������ѧ���ࡢ����˳����Լ���ʾ����(��cout�ͣ������ڳ�ʼ���룩 
void pre_TOTAL_DONE(Operate &o){
	Status p=pre_changeforstudent(o);//��ɸı� 
	Status a=pre_ifoperateforstorenum(o);//�ж��̵귽�Ƿ����
	if(a && p){
		untooperate(o);
	}
} 
//ʵ��һ�����뺯���Բ�����˳���ѧ�����в���˳�����ƿ� 
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
//��ѧ������ѧ��ѧ�Ž������� 
void sort_student(Student a[],int n)   //���Ǵ�С�������� 
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
//���һ���̵�Ĳ�����
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
			cout<<fixed<<setprecision(2)<<operate[i].money;//�������������λС�� 
			cout<<"	|"<<endl;
			cout<<"|________________|__________|___________________|_______|"<<endl;
			sum++;
		}
	}
	if(sum==0){
		cout<<"Sorry, there is no operate for this store "<<endl;
	}
}
//���һ��ѧ���Ĳ�����
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
			cout<<fixed<<setprecision(2)<<operate[i].money;//�������������λС�� 
			cout<<"	|"<<endl;
			cout<<"|________________|__________|___________________|_______|"<<endl;
			sum++;
		}
	}
	if(sum==0){
		cout<<"Sorry, there is no operate for this student "<<endl;
	}	
}
//���һ��ʱ���ڵĲ����� 
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
				cout<<fixed<<setprecision(2)<<operate[i].money;//�������������λС�� 
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
//����ȫ�������Ĵ��ʽ�ļ����[����ѧ��˳��](����front,������behind)
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
			cout<<"���ڱ��������У�"<<endl; 
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
				fout3<<fixed<<setprecision(2)<<operate[j].money;//�������������λС�� 
				fout3<<"	|"<<endl;
				fout3<<"|________________|__________|___________________|_______|"<<endl;
			}
		}
	}
}
//����ȫ�������Ĵ��ʽ�ļ����[�����̵�˳��](����front,������behind)
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
				fout5<<fixed<<setprecision(2)<<operate[j].money;//�������������λС�� 
				fout5<<"	|"<<endl;
				fout5<<"|________________|__________|___________________|_______|"<<endl;
			}
		}
	}
} 
//�������ѧ���Ļ�����Ϣ����������ʽ��ͬ��
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
		//���ʱ���Ʊ�����λС�� 
		fout4<<fixed<<setprecision(2)<<s[i].money<<"		";
		fout4<<fixed<<setprecision(2)<<s[i].mcard.getMoney()<<endl;
	} 
}
//��ѧ�������������
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
