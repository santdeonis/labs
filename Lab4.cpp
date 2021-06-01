#include <string>
#include <iostream>
using namespace std;
template <typename T>
class Vector
{
public:
	T * List;
	Vector(int A)
	{
		this->Size = A;
		List = new T[Size];
		for (int i = 0; i < Size; i++)
		{
			T B;
			cin >> B;
			List[i] = B;
		}
		cout << endl;
	};

	Vector(const Vector &other)
	{
		this->Size = other.Size;
		this->List = new T[Size];
		for (int i = 0; i < other.Size; i++)
		{
			this->List[i] = other.List[i];
		}
	}

	~Vector()
	{
		delete[] List;
	};

	void Print()
	{
		cout << "Vector Size is: " << Size << endl;
		for (int i = 0; i < Size; i++)
		{
			cout << List[i] << " ";
		}
		cout << endl;
	}

	void Add(T A)
	{
		T *temp = new T[Size];
		for (int i = 0; i < Size; i++)
		{
			temp[i] = List[i];
		}
		delete[] List;
		Size++;
		List = new T[Size];
		for (int i = 0; i < (Size-1); i++)
		{
			List[i] = temp[i];
		}
		List[(Size-1)] = A;
	}

	void Del()
	{
		T *temp = new T[Size];
		for (int i = 0; i < Size; i++)
		{
			temp[i] = List[i];
		}
		delete[] List;
		Size--;
		List = new T[Size];
		for (int i = 0; i < Size; i++)
		{
			List[i] = temp[i];
		}
	}

	Vector & operator = (const Vector &other)
	{
		if (this == &other)
			return *this;
		delete[] this->List;
		this->Size = other.Size;
		this->List = new T[other.Size];
		for (int i = 0; i < other.Size; i++)
		{
			this->List[i] = other.List[i];
		}
		return *this;
	}

private:
	int Size;
};

int main()
{
	Vector<string> AB(5);
	AB.Add("9");
	AB.Print();
	Vector<string> AC(AB);
	AC.Del();
	AC.Add("8");
	AC.Print();
	AB = AC;
	AB.Print();
	system("pause");
}