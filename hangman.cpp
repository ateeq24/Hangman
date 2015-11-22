//Group Mates: Muhammad Zain ul Abadeen && Hafiz Ateeq Ur Rehman
//Reg.No.8074 && 7003
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<map>
using namespace std;

class simple
{
public:
	string filereading(string fname);
	void guessing(string str);
	int run();
};
class evil{
public:
	vector<string> fileread(int n,string fname);
	int implemnt(int n,string fname);
	int run();
};
string simple::filereading(string fname)
{
	ifstream ptr;
	string str;
	int n;
	ptr.open(fname);
	if(!ptr)
	{
		cout<<"Unable to open the Dictionary File\n";
		str="asdfghj";
		system("pause");
		return str;
	}
	cout<<"Please enter number of alphabets for a word\n";
	cin>>n;
	while(getline(ptr,str))
	{
		if(str.length()==n)
			return str;
	}
	ptr.close();
	str="umerahmed";
	return str;
}
void simple::guessing(string str)
{
	int num;
	cout<<"\nHow many chances do you want? ";
	cin>>num;
	char ges;
	char* temp=new char [str.length()];
	for(int i=0;i<str.length();i++)
	{
		temp[i]='-';
		cout<<temp[i];
	}
		cout<<"\n";
	cout<<"Please Enter the Guess\n";
	while(num!=0)
	{
		int j=0;
		cout<<"Your Guess: ";
		cin>>ges;
		for(int i=0;i<str.length();i++)
		{
			if(ges==str[i]&&ges!=temp[i])
			{
				temp[i]=ges;
				j++;
			}
			cout<<temp[i];
		}
		cout<<"\n";
		if(j==0)
		{
			cout<<"Wrong Attempt\n";
			num--;
		}
		int l=0;
		cout<<"chances: "<<num<<"\n";
		for(int i=0;i<str.length();i++)
		{
			if(temp[i]==str[i])
				l++;
		}
		if(l==str.length()&&num==5)
		{
			cout<<"\nExcellent! You have Completed the word without losing any chance\n";
			return;
		}
		if(l==str.length()&&num!=5)
		{
		cout<<"\nCongratulations You have Completed the word with "<<num<<" chances left\n";
			return;
		}
		if(num==0)
		{
			cout<<"\nYou Lose\n";
			cout<<"The word is: "<<str<<"\n";
		}
	}
	return;
}
int simple::run()
{	
	string fname;
	cout<<"\nEnter File Name: ";
	cin>>fname;
	string str;
	str=filereading(fname);
	if(str=="asdfghj")
		return 0;
	if(str=="umerahmed")
		{
			cout<<"\nNo Word Found of your Input Length\n";
			system("pause");
			return 0;
		}
	guessing(str);
}
int main ()
{
	char opt;
	cout<<"Which Version do You Want to Play? (O) or (E)";
	cin>>opt;
	if(opt=='o'||opt=='O')
	{
		simple hangman;
		hangman.run();
	}
	else
	{
		evil evilhangman;
		evilhangman.run();
	}
	return 0;
}
vector<string> evil::fileread(int n,string fname)
{
	vector<string> strvec;
	ifstream ptr;
	string str;
	ptr.open(fname);
	if(!ptr)
	{	str="ASDFREWQ";
		strvec.push_back(str);
		return strvec;
	}
		while(!ptr.eof())
	{
		ptr>>str;
		if(str.length()==n)
			strvec.push_back(str);
	}
		ptr.close();
	return strvec;

}
int evil::implemnt(int n,string fname)
{

	vector<string> strvec=fileread(n,fname);
	if(strvec[0]=="ASDFREWQ")
		{
			cout<<"\nUnable to open Dictionary File\n";
			return 0;
		}
	int num;
	char ges;
	cout<<"\nHow many Chances you want: ";
	cin>>num;
	cout<<"\n";
	map<string,vector<string>> vecmap;
	string temp133="adg";
	string temp4(n,'-');
	char* temp2=new char[n];
	for(int i=0;i<n;i++)
	{
		temp2[i]='-';
	}		
	cout<<"\nTotal Number of Words: "<<strvec.size()<<"\n";
	if(num>=1)
	{
		while(num!=0)
		{
			cout<<"Enter your Guess: ";
			cin>> ges;
			vecmap.clear();
		for(int i=0;i<strvec.size();i++)
		{
			string temp=strvec[i];
			for(int j=0;j<n;j++)
			{
				if(ges==temp[j]&&temp2[j]=='-')
				{
					temp2[j]=ges;
				}
				if(temp[j]!=temp2[j])
				{
					temp2[j]='-';
				}
			}
			string temp3(temp2);
			for(int j=0;j<n;j++)
			{
				temp4[j]=temp3[j];
			}
			vecmap[temp4].push_back(temp);
		}
		strvec.clear();
		strvec.push_back("asd");
		for(map<string,vector<string>>::iterator it=vecmap.begin();it!=vecmap.end();it++)
		{
			if((it->second).size()>=strvec.size())
			{
				strvec=it->second;
				temp133=it->first;
			}
		}
		copy(temp133.begin(),temp133.end(),temp2);
		cout<<"Total Number of Words: "<<strvec.size();
		int count=0;
		cout<<"\n";
		for(int i=0;i<temp133.length();i++)
		{
			if(temp133[i]==ges)
				count++;
		}
		cout<<temp133<<"\n";
		if(count==0)
		{
			cout<<"\nWrong Attempt\n";
			num--;
			cout<<"Chances Remaining: "<<num<<"\n";
		}
		if(num==0)
		{
			cout<<"You lose!\nThe Word is: "<<strvec[0];
		}
		}
}
}
int evil::run()
{
	cout<<"\nEnter File Name: ";
	string fname;
	cin>>fname;
	int n,k;
	cout<<"Please enter number of alphabets for a word\n";
	cin>>n;
	k=implemnt(n,fname);
	if(k==0)
	{
		system("pause");
		return 0;
	}
	return 0;
}