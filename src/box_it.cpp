#include<iostream>

using namespace std;

class Box {
	private:
		int l;
		int b;
		int h;
	public:
		Box() {
			l = 0;
			b = 0;
			h = 0;
		}
		Box(int length, int breadth, int height) {
			l = length;
			b = breadth;
			h = height;
		}
		int getLength() {
			return l;
		}
		int getBreadth() {
			return b;
		}
		int getHeight() {
			return h;
		}
		long long CalculateVolume() {
			return (long long) l * b * h;
		}
		bool operator<(const Box& other) {
			if (l != other.l) return l < other.l;
			if (b != other.b) return b < other.b;
			return h < other.h;
		}
		friend ostream& operator <<(ostream& os, const Box& box) {
			os << box.l << " " << box.b << " " << box.h;
			return os;
		}
};

void check2()
{
	int n;
	cin >> n;
	Box temp;
	for (int i = 0;i < n;i++)
	{
		int type;
		cin >> type;
		if (type == 1)
		{
			cout << temp << endl;
		}
		if (type == 2)
		{
			int l, b, h;
			cin >> l >> b >> h;
			Box NewBox(l, b, h);
			temp = NewBox;
			cout << temp << endl;
		}
		if (type == 3)
		{
			int l, b, h;
			cin >> l >> b >> h;
			Box NewBox(l, b, h);
			if (NewBox < temp)
			{
				cout << "Lesser\n";
			}
			else
			{
				cout << "Greater\n";
			}
		}
		if (type == 4)
		{
			cout << temp.CalculateVolume() << endl;
		}
		if (type == 5)
		{
			Box NewBox(temp);
			cout << NewBox << endl;
		}

	}
}

int main()
{
	check2();
}