#ifndef ACHIEVE_H
#define ACHIEVE_H
#include "Student.h"
#include "THUstudent.h"
//���ʱ����в�ѯ+cin�� 
void QT_cin();
//���ѧ�����в�ѯ(��������֤�� 
void QU_cin();
//����̵���в�ѯ+cin��
void QO_cin(); 
//������ⳤ�ܴ����ͷ����Ĳ�ѯ
void QS_cin(); 
//������п����+cin�� 
void CD_cin();
//������п�ȡ��+cin��
void CW_cin(); 
//���ĳһѧ�������ѡ�Ȧ��������ѯ
void TT_cin(); 
//���ĳһѧ�������ѡ�Ȧ��������ѯ������ʱ��Σ�
void TL_cin(); 
//���Ѳ���+cin��
void OC_cin(); 
//Ȧ�����+cin��
void OD_cin();
//������ѧ+cin��
void MSD_cin();
//ѧ����ҵ����ѧ+cin�� 
void MSG_cin();
//�̵�������Ϣ��ʱ��� 
void MDS_cin();
//����ѧ����Ч���ⳤ�ܵĴ��� 
void MYL_cin();
//�޸����ⳤ�����ֱ�׼
void MYC_cin(); 
//������ȫ������� 
void operateTOTAL_cin();


//�޸����ⳤ�����ֱ�׼(ͬʱ�޸�ͬѧ�÷֣� 
void MYC_cin(){
	int op;
	cout<<"input the times to get each grade: (-1 for back one step)"<<endl;
	for(int i=1;i<=10;i++){
		cout<<i<<": ";
		cin>>op;
		if(op==-1){
			i-=2;
			continue;
		}
		sunsrun[i]=op;
	}
	cout<<"succeed correct! "<<endl;
	for(int i=0;i<n;i++){
		THUs[i].putgrade();
	}
}
//����ѧ����Ч���ⳤ�ܵĴ��� 
void MYL_cin(){
	cout<<"student number: ";
	int p;
	cin>>p;
	int t=bin_Search_Student(p);
	if(t==-1){
		cout<<"Wrong Id number! "<<endl;
	}else{
		cout<<"sunsrun times: ";
		int n;
		cin>>n;
		if(n<0){
			cout<<"Wrong input! "<<endl; 
		}else{
			THUs[t].puttimes(n);
			THUs[t].putgrade();
			cout<<"succeed load in! "<<endl;
		}
	}
}

//������ȫ������� 
void operateTOTAL_cin(){
	char tu='0',ti='0';
	bool op=true;
	while(tu!='E'){
		cout<<"O-����(ѧ������,C-���������п�����Q-��ѯ��T-ѧ���������M-����E-�˳�"<<endl;
		cin>>tu;
		if(tu!='O' && tu!='C' && tu!='Q' && tu!='T' && tu!='M' && tu!='E'){
			cout<<"Wrong input! "<<endl;
		} 
		if(tu=='O'){
			AAAA: cout<<"C-���ѣ�D-Ȧ��,E-�˳�"<<endl;
			cin>>ti;
			op=true;
			if(ti=='C'){
				OC_cin();
				op=false;
			} 
			if(ti=='D'){
				OD_cin();
				op=false;
			}
			if(ti=='E'){
				continue;
				op=false;
			}
			if(op){
				cout<<"Wrong input! "<<endl;
				goto AAAA;
			}			
		}
		if(tu=='C'){
			AAAB: cout<<"D-��W-ȡ�E-�˳�"<<endl;
			cin>>ti;
			op=true;
			if(ti=='D'){
				CD_cin();
				op=false;
			}
			if(ti=='W'){
				CW_cin();
				op=false;
			}
			if(ti=='E'){
				continue;
				op=false;
			}
			if(op){
				cout<<"Wrong input! "<<endl;
				goto AAAB;
			}
		}
		if(tu=='Q'){
			AAAC: cout<<"U-��ѧ����O-���̵꣬T-�޶�ʱ�䣬S-���ⳤ�ܣ�E-�˳�"<<endl;
			cin>>ti;
			op=true;
			if(ti=='U'){
				QU_cin();
				op=false;
			}
			if(ti=='O'){
				QO_cin();
				op=false;
			}
			if(ti=='T'){
				QT_cin();
				op=false;
			}
			if(ti=='S'){
				QS_cin();
				op=false;
			}
			if(ti=='E'){
				continue;
				op=false;
			}
			if(op){
				cout<<"Wrong input! "<<endl;
				goto AAAC;
			}
		}
		if(tu=='T'){
			AAAD: cout<<"T-���У�L-�޶�,E-�˳�"<<endl;
			cin>>ti;
			op=true;
			if(ti=='T'){
				TT_cin();
				op=false;
			} 
			if(ti=='L'){
				TL_cin();
				op=false;
			}
			if(ti=='E'){
				continue;
				op=false;
			}
			if(op){
				cout<<"Wrong input!  "<<endl;
				goto AAAD;
			}
		}
		if(tu=='M'){
			cout<<"password: ";
			int po;
			cin>>po;
			if(po==2015012177){
				cout<<"Succeed log in! "<<endl;
			} else{
				cout<<"Wrong! You have 2 chances remained"<<endl;
				cout<<"password: ";
				cin>>po;
				if(po==2015012177){
					cout<<"succeed log in! "<<endl;
				}else{
					cout<<"Wrong! You have 1 chance remained"<<endl;
					cout<<"password: ";
					cin>>po;
					if(po==2015012177){
						cout<<"succeed log in! "<<endl;
					}else{
						cout<<"sorry! automatically exit! "<<endl;
						break;
					}
				}
			}
			AAAE: cout<<"S-ѧ����D-�̵������Y-���ⳤ�ܣ�E-�˳�"<<endl;
			cin>>ti;
			po=true;
			if(ti=='S'){
				po=false;
				char tv='0';
				AABA: cout<<"D-������ѧ��G-��ҵ/��ѧ��E-�˳�"<<endl;
				cin>>tv;
				bool pi=true;
				if(tv=='D'){
					pi=false;
					MSD_cin();
				}
				if(tv=='G'){
					pi=false;
					MSG_cin();
				}
				if(tv=='E'){
					pi=false;
					goto AAAE;
				}
				if(pi){
					cout<<"Wrong input! "<<endl;
					goto AABA;
				}
			}
			if(ti=='Y'){
				po=false;
				char tv='0';
				AABB: cout<<"L-����ѧ��������C-�޸����ֹ���E-�˳�"<<endl; 
				cin>>tv;
				bool pi=true;
				if(tv=='L'){
					MYL_cin();
					pi=false;
				}
				if(tv=='C'){
					MYC_cin();
					pi=false;
				}
				if(tv=='E'){
					pi=false;
					goto AAAE;
				}
				if(pi){
					cout<<"Wrong input! "<<endl;
					goto AABB;
				}
			} 
			if(ti=='D'){
				MDS_cin();
				po=false;
			}
			if(ti=='E'){
				po=false;
				continue;
			}
			if(po){
				cout<<"Wrong input! "<<endl;
				goto AAAE;
			}
		}
		
		if(tu=='E'){
			cout<<"Thank you for using! "<<endl;
		} 
	}
}
//�̵�������Ϣ��ʱ��� 
void MDS_cin(){
	cout<<"delete time limit: (year,month,day,hour,minute)"<<endl;
	unsigned year,month,day,hour,minute;
	cin>>year>>month>>day>>hour>>minute;
	Time t1(year,month,day,hour,minute);
	int i=0,sum=0;//sum������¼�ܳ���ɾ����¼���� 
	for(;i<noperate;i++){
		Comparecc itoe=comparetime(operate[i].time,t1);
		Comparecc itof=comparetime(operate[i].time,deletetime);
		if(itoe && !itof){
			operate[i].much=MUCH(operate[i].much-1); 
			if(!operate[i].much){
				for(int j=i+1;j<noperate;j++){
					operate[j-1]=operate[j];
				}
				noperate--;
				i--;
				sum++; 
			}
		}else{
			break;
		}
	}
	cout<<"Succeed completely delete "<<sum<<" piece";
	if(sum>=2){
		cout<<"s";
	}	
	cout<<" of record";
	if(sum>=2){
		cout<<"s";
	}
	cout<<"! "<<endl;
	deletetime=t1;
} 
//ѧ����ҵ����ѧ+cin�� 
void MSG_cin(){
	cout<<"idcard number: ";
	int p;
	cin>>p;
	int t=bin_Search_Student(p);
	if(t==-1){
		cout<<"Wrong Id number! "<<endl;
	}else{
		int oi=s[t].getsex();
		cout<<"Please check ";
		if(oi){
			cout<<"his";
		}else{
			cout<<"her";
		}
		cout<<" basic information: "<<endl;
		s[t].display();
		cout<<"actually delete ";
		if(oi){
			cout<<"him";
		}else{
			cout<<"her";
		}
		cout<<" ?"<<" (input 'Y' for yes,'N' for no)"<<endl;
		char iu;
		cin>>iu;
		if(iu=='Y'){
			int wee=s[t].getstucard();
			double lu=s[t].getmoney();
			s[t].mcard.depositMoney(lu);//����ѧ�������Ǯ��ص������п��� 
			for(int i=0;i<noperate;i++){
				if(wee==operate[i].getstudentid()){
					MUCH opei=operate[i].getmuch();
					operate[i].putmuch(MUCH(opei-1));
					if(!operate[i].getmuch()){
						for(int k=i+1;k<noperate;k++){
							operate[k-1]=operate[k];
						}
						noperate--;
						i--;
					}
				}
			}
			for(int j=t+1;j<n;j++){
				s[j-1]=s[j];
				THUs[j-1]=THUs[j]; 
			}
		}
		n--;
		cout<<"Succeed delete! "<<endl; 
	}
} 
//������ѧ+cin��
void MSD_cin(){
	cout<<"format: name,studentid,sex,money(in credit)"<<endl;
	string name;
	int studentid;
	string sex1;
	Sex sex;
	float money;
	cin>>name;
	cin>>studentid;
	cin>>sex1;
	cin>>money;
	if(sex1=="female"){
		sex=female;
	}else{
		if(sex1=="male"){
			sex=male;
		}else{
			cout<<"Wrong sex input! "<<endl;
			return;
		}
	}
	Level level=one;
	Student s1(name,studentid,sex,level,0,money);
	THUstudent THUs1(s1,0);
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
		THUstmp=new THUstudent[listsize];
		for(int i=0;i<n;i++){
			THUstmp[i]=THUs[i];
		} 
		delete []THUs;
		THUs=new THUstudent [listsize];
		for(int i=0;i<n;i++){
			THUs[i]=THUstmp[i];
		}
		delete []THUstmp;
	}
	bool in=false;
	for(int i=0;i<n;i++){
		if(s[i].getstucard()>studentid){
			for(int j=n-1;j>=i;j--){
				s[j+1]=s[j];
				THUs[j+1]=THUs[j];
			}
			s[i]=s1;
			THUs[i]=THUs1;
			in=true;
			break;
		}
		if(s[i].getstucard()==studentid){
			cout<<"Already existed! "<<endl;
			return;
		}
	}
	if(!in){
		s[n]=s1;
		THUs[n]=THUs1;
	}
	cout<<"Succeed adding! "<<endl;
	n++; 
}
//Ȧ�����+cin��
void OD_cin(){
	cout<<"input id number: ";
	int p;
	cin>>p;
	Status u=log_in(p);
	if(u){
		short num;
		float money;
		unsigned year,month,day,hour,minute;
		cout<<"format: storenum time(year month day hour minute) money(positive)"<<endl;
		cin>>num>>year>>month>>day>>hour>>minute>>money;
		Operate tmp(year,month,day,hour,minute,num,p,money);
		TOTAL_DONE(tmp);
	}
}
//���Ѳ���+cin��
void OC_cin(){
	cout<<"input id number: ";
	int p;
	cin>>p;
	Status u=log_in(p);
	if(u){
		short num;
		float money;
		unsigned year,month,day,hour,minute;
		cout<<"format: storenum time(year month day hour minute) money(positive)"<<endl;
		cin>>num>>year>>month>>day>>hour>>minute>>money;
		Operate tmp(year,month,day,hour,minute,num,p,-money);
		TOTAL_DONE(tmp);
	}
}
//���ĳһѧ�������ѡ�Ȧ��������ѯ������ʱ��Σ�
void TL_cin(){
	cout<<"input id number: ";
	int p;
	cin>>p;
	Status u=log_in(p);
	if(u){
		cout<<"format: begin time(year,month,day,hour,minute),end time(year,month,day,hour,minute)"<<endl;
		unsigned a1,a2,a3,a4,a5;
		unsigned b1,b2,b3,b4,b5;
		cin>>a1>>a2>>a3>>a4>>a5;
		Time t1(a1,a2,a3,a4,a5);
		cin>>b1>>b2>>b3>>b4>>b5;
		Time t2(b1,b2,b3,b4,b5);
		if(!comparetime(t1,t2)){
			cout<<"Sorry, wrong input of time limits "<<endl;
			return;
		}
		double c=0,d=0;
		for(int i=0;i<noperate;i++){
			if(comparetime(t1,operate[i].time)){
				if(comparetime(operate[i].time,t2)){
					if(operate[i].studentid==p){
						if(operate[i].money>0){
							d+=operate[i].money;
						}
						if(operate[i].money<0){
							c-=operate[i].money;
						}
					}
				}else{
					break;
				}
			}
		}
		int t=bin_Search_Student(p);
		if(s[t].getsex()){
			cout<<"He ";
		}else{
			cout<<"She ";
		}
		cout<<"has consumed "<<fixed<<setprecision(2)<<c<<" yuan, ";
		cout<<"has deposited "<<fixed<<setprecision(2)<<d<<" yuan. ";
		cout<<endl;
	}
}
//���ĳһѧ�������ѡ�Ȧ��������ѯ
void TT_cin(){
	cout<<"input id number: ";
	int p;
	cin>>p;
	Status u=log_in(p);
	if(u){
		double c=0,d=0;
		for(int i=0;i<noperate;i++){
			if(operate[i].getstudentid()==p){
				if(operate[i].getmoney()>0){
					d+=operate[i].getmoney();
				}
				if(operate[i].getmoney()<0){
					c-=operate[i].getmoney();
				}
			}
		}
		int t=bin_Search_Student(p);
		if(s[t].getsex()){
			cout<<"He ";
		}else{
			cout<<"She ";
		}
		cout<<"has consumed "<<fixed<<setprecision(2)<<c<<" yuan, ";
		cout<<"has deposited "<<fixed<<setprecision(2)<<d<<" yuan. ";
		cout<<endl;
	}
}
//������п�ȡ��+cin��
void CW_cin(){
	cout<<"input id number: ";
	int p;
	cin>>p;
	Status u=log_in(p);
	int t=bin_Search_Student(p);
	if(u){
		cout<<"withdraw money: ";
		double r;
		cin>>r;
		Status q=s[t].mcard.withdrawMoney(r);
		if(q){
			cout<<"Succeed withdraw "<<r<<" yuan! "<<endl;
		}else{
			cout<<"Lacking of money in your credit card! "<<endl;
			cout<<"input 'Q' to Query your money left, 'E' to exit "<<endl;
			char ww;
			cin>>ww;
			if(ww=='Q'){
				cout<<"the money in your credit card: "<<s[t].mcard.getMoney()<<endl;
			}
		}
	}
}
//������п����+cin�� 
void CD_cin(){
	cout<<"input id number: ";
	int p;
	cin>>p;
	Status u=log_in(p);
	int t=bin_Search_Student(p);
	if(u){
		cout<<"deposit money: ";
		double r;
		cin>>r;
		s[t].mcard.depositMoney(r);
		cout<<"succeed deposit "<<r<<" yuan! "<<endl; 
	}
} 
//������ⳤ�ܴ����ͷ����Ĳ�ѯ
void QS_cin(){
	cout<<"input the idcard: ";
	int p;
	cin>>p;
	Status u=log_in(p);
	int t=bin_Search_Student(p);
	if(u){
		cout<<"sunsrun times: ";
		cout<<THUs[t].gettimes()<<endl;
		cout<<"sunsrun grade: ";
		cout<<THUs[t].getgrade()<<endl;
	}
}
//����̵���в�ѯ+cin��
void QO_cin(){
	cout<<"input the store number: ";
	int p;
	cin>>p;
	cout_storeoperate(p);
}
//���ѧ�����в�ѯ
void QU_cin(){
	cout<<"input the idcard: ";
	int p;
	cin>>p;
	Status u=log_in(p);
	if(u){
		cout_singleoperate(p);
	}
}
//���ʱ����в�ѯ+cin�� 
void QT_cin(){
	cout<<"format: begin_time(year,month,day,hour,minute),end_time(year,month,day,hour,minute)"<<endl;
	Time t1=time_cin(),t2=time_cin();
	cout_timelimit(t1,t2); 
}

#endif
