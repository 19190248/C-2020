#include <iostream>
#include <cmath>
using namespace std;
const double PI=3.1415926535;
class Point
{
private:
double x,y;
public:
Point()
{
x = 0; y = 0;
}
Point(double xv,double yv)
{
x = xv;y = yv;
}
Point(Point& pt)
{
	x=pt.x;
	y=pt.y;
}
//(1) //复制构造函数实现
double getx()
{
return x;
}
double gety()
{
return y;
}
double Area()
{
return 0;
}
void Show()
{
cout<<"x="<<x<<' '<<"y="<<y<<endl;
}
};
class Circle :public Point
{
	double radius;
//(2) //Circle 类数据成员的定义
public:
Circle()
{
radius = 0;
}
Circle(double xv,double yv,double vv):Point(xv,yv)
{
radius = vv;
}
Circle(Circle& cc):Point(cc)
{
	
	radius=cc.radius;
}
//(3) //复制构造函数实现
double Area()
{
return PI*radius*radius;
}

void Show() //注意怎样访问基类的数据成员
{
cout<<"x="<<getx()<<'\t'<<"y="<<gety()<<'\t'<<"radius="<<radius<<endl;
}
int position(Point &pt)
{
double distance = sqrt((getx()-pt.getx())*(getx()-pt.getx())
+(gety()-pt.gety())*(gety()-pt.gety()));
double s=distance-radius;
if(s==0) return 0; //在圆上
else if(s<0) return -1; //在圆内
else return 1; //在圆外
}
};
class Rectangle:public Point
{
double width,length;
public:
Rectangle()
{
width=0; length=0;
}
Rectangle(double xv,double yv,double wv,double lv):Point(xv,xv)
{
width = wv;
length= lv;
}
Rectangle(Rectangle& rr):Point(rr)//(4) //复制构造函数实现
{
	width=rr.width;
	length=rr.length;
}
double Area()
{
return width*length;
}
void Show()
{
cout<<"x="<<getx()<<'\t'<<"y="<<gety()<<'\t';
cout<<"width="<<width<<'\t'<<"length="<<length<<endl;
}
int position(Point &pt);
};

int Rectangle::position(Point &pt)
{
double s1,s2;
s1 = (pt.getx()-getx()); s2=(pt.gety()-gety());
if(((s1==0||s1==width)&&s2<=length)||((s2==0||s2==length)&&s1<=width)) return 0;
else if(s1<width&&s2<length) return -1; //0 在矩形上，-1 在矩形内
else return 1; //1 在矩形外
}
int main()
{
Circle cc1(3,4,5),cc2,cc3(cc1);
Rectangle rt1(0,0,6,8),rt2,rt3(rt1);
Point p1(0,0),p2(6,8),p3(3,3),p4(8,4),p5(8,8);
cc1.Show();
cc2.Show();
rt1.Show();
rt2.Show();
cout<<"点 p1:";
p1.Show();
cout<<"矩形 rt3:"<<'\t';
rt3.Show();
switch(rt3.position(p1))
{
case 0:cout<<"在矩形上"<<endl;break;
case -1:cout<<"在矩形内"<<endl;break;
case 1:cout<<"在矩形外"<<endl;break;
}
cout<<"圆 cc3:"<<'\t';
cc3.Show();
switch(cc3.position(p1)){
case 0:cout<<"在圆上"<<endl;break;
case -1:cout<<"在圆内"<<endl;break;
case 1:cout<<"在圆外"<<endl;break;
}
cout<<"点 p2:";
p2.Show();
cout<<"矩形 rt3:"<<'\t';
rt3.Show();
switch(rt3.position(p2))
{
case 0:cout<<"在矩形上"<<endl;break;
case -1:cout<<"在矩形内"<<endl;break;
case 1:cout<<"在矩形外"<<endl;break;
}
cout<<"圆 cc3:"<<'\t';
cc3.Show();
switch(cc3.position(p2))
{
case 0:cout<<"在圆上"<<endl;break;
case -1:cout<<"在圆内"<<endl;break;
case 1:cout<<"在圆外"<<endl;break;
}
cout<<"点 p3:";
p3.Show();
cout<<"矩形 rt3:"<<'\t';
rt3.Show();
switch(rt3.position(p3))
{
case 0:cout<<"在矩形上"<<endl;break;
case -1:cout<<"在矩形内"<<endl;break;
case 1:cout<<"在矩形外"<<endl;break;
}
cout<<"圆 cc3:"<<'\t';
cc3.Show();
switch(cc3.position(p3))
{
case 0:cout<<"在圆上"<<endl;break;
case -1:cout<<"在圆内"<<endl;break;
case 1:cout<<"在圆外"<<endl;break;
}
cout<<"点 p4:";
p4.Show();
cout<<"矩形 rt3:"<<'\t';
rt3.Show();
switch(rt3.position(p4))
{
case 0:cout<<"在矩形上"<<endl;break;
case -1:cout<<"在矩形内"<<endl;break;
case 1:cout<<"在矩形外"<<endl;break;
}
cout<<"圆 cc3:"<<'\t';
cc3.Show();
switch(cc3.position(p4))
{
case 0:cout<<"在圆上"<<endl;break;
case -1:cout<<"在圆内"<<endl;break;
case 1:cout<<"在圆外"<<endl;break;
}
cout<<"点 p5:";
p5.Show();
cout<<"矩形 rt3:"<<'\t';
rt3.Show();
switch(rt3.position(p5))
{
case 0:cout<<"在矩形上"<<endl;break;
case -1:cout<<"在矩形内"<<endl;break;
case 1:cout<<"在矩形外"<<endl;break;
}
cout<<"圆 cc3:"<<'\t';
cc3.Show();
switch(cc3.position(p5))
{
case 0:cout<<"在圆上"<<endl;break;
case -1:cout<<"在圆内"<<endl;break;
case 1:cout<<"在圆外"<<endl;break;
}
return 0;
}