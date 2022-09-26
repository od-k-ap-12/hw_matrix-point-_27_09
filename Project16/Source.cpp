#include"Matrix.h"

class Point
{
	int x;
	int y;
public:
	Point();
	Point(int _x, int _y);
	Point operator+(int a);
	int GetX()const;
	int GetY()const;
	void SetX(int _x);
	void SetY(int _y);
	bool operator>(const Point obj);
	template <typename T>
	Point& operator=(const T a);
	template <typename T>
	Point& operator+=(const T a);
};
Point::Point()
{
	x = 0;
	y = 0;
}
Point::Point(int _x, int _y)
{
	x = _x;
	y = _y;
}
bool Point::operator>(const Point obj) {
	if ((x + y) > (obj.x + obj.y)) {
		return true;
	}
	else {
		return false;
	}
}
Point Point::operator+(int a)
{
	Point rez(*this);
	rez.x += a;
	rez.y += y;
	return rez;
}
Point operator+(int a, Point& obj) {
	Point rez(obj.GetX(),obj.GetY());
	rez.SetX(rez.GetX()+a);
	rez.SetY(rez.GetY() + a);
	return rez;
}
template<typename T>
Point& Point:: operator+=(const T a) {
	x += (int)a;
	y += (int)a;
	return *this;
}
int Point::GetX()const
{
	return x;
}
int Point::GetY()const
{
	return y;
}
void Point::SetX(int _x)
{
	x = _x;
}
void Point::SetY(int _y)
{
	y = _y;
}
template <typename T>
Point& Point::operator=(const T a) {
	x = a;
	y = a;
	return *this;
}
ostream& operator<<(ostream& os, const Point& obj) {
	os << obj.GetX() << " " << obj.GetY() << " ";
	return os;
}
int main()
{
	//Matrix<int> obj1(3, 5);
	//obj1.Random();
	//obj1.Print();
	//cout << "\n---------------------------------------\n";
	//Matrix<int> b;
	//b = obj1;
	//b.Print();

	/// 

	Matrix<Point> a(5, 5);
	a.Random();
	a.Print();
	cout << "-------------------------------------------------------"<<endl;
	cout << a;
	cout << "-------------------------------------------------------"<<endl;
	Matrix<Point> sum = a + 3;
	cout << "-------------------------------------------------------"<<endl;
	Matrix<Point> sum2 = 3 + a;

	if (sum > sum2)
	{
		cout << "sum > sum2\n";
	}
	
}
