#include <string>
#include <iostream>
#include <vector>
using namespace std;

class StringList
{
public:
	int ListSize;
	StringList() {}
	StringList(int N)
	{
		this->ListSize = N;
		string buffer;
		for (int i = 0; i < ListSize; i++)
		{
			cin >> buffer;
			List.push_back(buffer);
		}
		/*for (int i = 0; i < ListSize; i++)
		{
		cout << List[i] << endl;
		}
		this->List = List;*/
	}
	StringList(const StringList &other)
	{
		this->ListSize = other.ListSize;
		for (int i = 0; i < other.ListSize; i++)
		{
			this->List.push_back(other.List[i]);
		}
	}
	~StringList()
	{
		//delete[] List;
	}
	void Funk(int A)
	{
		int Max = 0;
		string I;
		for (int i = 0; i < ListSize; i++)
		{
			int max = 0;
			int J = List[i].size();
			for (int j = 0; j < J; j++)
			{
				if (List[i][j] == A)
				{
					max++;
				}
			}
			if (max > Max)
			{
				Max = max;
				I = List[i];
			}
		}
		cout << I;
	}
	void Print()
	{
		cout << "Number of string: " << ListSize << endl;
		for (int i = 0; i < ListSize; i++)
		{
			cout << List[i] << endl;
		}

	}
	StringList operator = (const StringList &other) 
	{
		if (this == &other)
			return *this;
		this->List.clear();
		for (int i = 0; i < other.ListSize; i++)
		{
			this->List.push_back(other.List[i]);
		}
		return 0;
	}
	StringList operator +(const StringList & other)const 
	{
		StringList temp;
		//temp.ListSize = this->ListSize + other.ListSize;
		for (int i = 0; i < this->ListSize; i++)
		{
			temp.List.push_back(this->List[i]);
		}
		for (int i = 0; i < other.ListSize; i++)
		{
			temp.List.push_back(other.List[i]);
		}
		temp.ListSize = temp.List.size();
		return temp;
	}
protected:
	vector<string> List;
};

class EmpList : public StringList
{
public: 
	EmpList() : StringList() {}
	EmpList(int Ns) : StringList(Ns) {}
	EmpList(const EmpList &other) : StringList(other) {}
	string CompName = "None";
	~EmpList() {}
	
	EmpList operator = (const EmpList &other)
	{
		if (this == &other)
			return *this;
		this->CompName = other.CompName;
		StringList::operator=(other);
	}

	void ChangeName()
	{
		string NewName;
		cout << "Enter company title" << endl;
		cin >> NewName;
		CompName = NewName;
	}
	void Print() 
	{
		cout << "Company title is: " << this->CompName << endl; 
		StringList::Print(); 
	}
	friend bool Search(EmpList& B, string S);
};

bool Search(EmpList& B, string S) 
{
	for (int i = 0; i < B.ListSize; i++)
	{
		if (B.List[i] == S)
		{
			cout << "true";
			return true;
		}
	}
	cout << "false";
	return false;		
}
int main()
{
	/*StringList str0 = StringList(3);
	StringList str1 = StringList(str0);
	StringList str2 = StringList(2);
	StringList str = str1 + str2;
	char A;
	cin >> A;
	str.Funk(A);
	str.Print();*/
	EmpList comp = EmpList(6);
	comp.ChangeName();
	EmpList comp1 = comp;
	comp1.Print();
	string S;
	cin >> S;
	bool f = Search(comp, S);
	cout << f;
	system("pause");
	return 0;



}