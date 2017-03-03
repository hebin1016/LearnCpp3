//
//  main.cpp
//  LearnCpp3
//
//  Created by hebin on 2017/2/10.
//  Copyright © 2017年 hebin. All rights reserved.
//

#include <iostream>
using namespace std;

/*
//继承
//代码的重用
class Car{
public:
    void run(){
        cout<<"行驶"<<endl;
    }
protected:
    char* card;
    char* color;
};

//
class Truck:public Car{
private:
    int speed;
public:
    void cargo(){
        cout<<"拉货"<<endl;
    }
};

void drive(Car& c){
    c.run();
}

int main(int argc, const char * argv[]) {
   
    Truck truck;
    drive(truck);
    
    //父类类型的引用或指针
    Car* car=&truck;
    car->run();
    
    Car& car2=truck;
    drive(car2);
    
    //子类对象初始化父类类型的对象
    Car car3=truck;

    return 0;
}
 */

/*
//向父类构造方法传参
class Car{
public:
    Car(char* card,char* color){
        this->card=card;
        this->color=color;
    }
    void run(){
        cout<<"行驶"<<endl;
    }
protected:
    char* card;
    char* color;
};

//子类
class Truck:public Car{
private:
    int speed;
    Car car;
public:
    //给父类构造方法传参同时给属性对象赋值
    Truck(int speend,char* s_card,char* s_color,char* c_card,char* c_color):Car(s_card,s_color),car(s_card,s_color){
        this->speed=speed;
    }
    void cargo(){
        cout<<"拉货"<<endl;
    }
};

int main(){
    Truck truck(200,"9527","紫色","10086","黑色");
    return 0;
}
*/

/*
//构造函数和析构函数的调用顺序
//Car构造函数
//Truck构造函数
//Truck析构函数
//Car析构函数
class Car{
public:
    Car(char* card,char* color){
        this->card=card;
        this->color=color;
        cout<<"Car构造函数"<<endl;
    }
    ~Car(){
        cout<<"Car析构函数"<<endl;
    }
    void run(){
        cout<<"行驶"<<endl;
    }
protected:
    char* card;
    char* color;
};

//子类
class Truck:public Car{
private:
    int speed;
public:
    //给父类构造方法传参同时给属性对象赋值
    Truck(int speend,char* s_card,char* s_color):Car(s_card,s_color){
        this->speed=speed;
        cout<<"Truck构造函数"<<endl;

    }
    ~Truck(){
        cout<<"Truck析构函数"<<endl;
    }
    void cargo(){
        cout<<"拉货"<<endl;
    }
};

void func(){
    //父类的构造函数先调用，子类的析构函数先调用
    Truck truck(200,"9527","紫色");
}

int main(){
    
    func();
    
    return 0;
}
*/

/*
//子类调用父类的成员
class Car{
public:
    Car(char* card,char* color){
        this->card=card;
        this->color=color;
    }
    void run(){
        cout<<"行驶"<<endl;
    }
protected:
    char* card;
    char* color;
};

//子类
class Truck:public Car{
private:
    int speed;
public:
    //给父类构造方法传参同时给属性对象赋值
    Truck(int speend,char* s_card,char* s_color):Car(s_card,s_color){
        this->speed=speed;
        
    }
    void cargo(){
        cout<<"拉货"<<endl;
    }
    void run(){
        cout<<"拉货"<<endl;

    }
};

int main(){
    
    Truck t(200,"9527","白色");
    //是覆盖，并非多态，调不到子类的方法
    Car car=t;
    car.run();
    
    //出了子类调父类的方法，或者赋值
    Truck t2=t;
    t2.Car::run();
    
    return 0;
}
*/


/*
//多继承
//鸟
class Bird{
    
};
//飞鸟
class Fly_bird{
    
};
//布谷鸟
class Bugu_bird:public Bird,public Fly_bird{
    
};


int main(){
    return 0;
}
*/

/*
//继承的访问修饰符
class Car{
public:
    Car(char* card,char* color){
        this->card=card;
        this->color=color;
    }
    void run(){
        cout<<"行驶"<<endl;
    }
private:
    char* card;
    char* color;
};

//子类
class Truck:protected Car{
private:
    int speed;
public:
    //给父类构造方法传参同时给属性对象赋值
    Truck(int speend,char* s_card,char* s_color):Car(s_card,s_color){
        this->speed=speed;
        
    }
    void cargo(){
        cout<<"拉货"<<endl;
        this->run();
    }
    void run(){
        cout<<"拉货"<<endl;
        
    }
};

int main(){
    Truck t(300,"9527","aaaa");
    //t.Car::run();
    
    return 0;
}
*/

/*
//多继承的问题
//继承的二义性
//虚继承，不同路径继承来的同名成员只有一份拷贝，解决了不明确的问题
class A{
public:
    char *name;
};
class A1:virtual public A{

};
class A2:virtual public A{
    
};
class B:public A1,public A2{
    
};

int main(){
    B b;
    b.name="1111";
    //指定父类显示调用
//    b.A1::name="200";
//    b.A2::name="300";
 
}
*/


/*
//虚函数
//多态（程序的扩展性）
//动态多态：程序运行过程中，觉得哪个函数被调用
//静态多态：重载

//发生动态多态的条件
//1.继承
//2.父类的引用指向子类的对象
//3.函数的重写

#include "Plane.h"

#include "Jet.h"

#include "Copter.h"

//业务函数
void bizPlay(Plane& p){
    p.fly();
    p.land();
}

int main(){
    Plane p1;
    bizPlay(p1);
    
    Jet p2;
    bizPlay(p2);
    
    Copter p3;
    bizPlay(p3);
    
    return 0;
}
*/

/*
//纯虚函数（抽象类）
//1.当一个类具有一个纯虚函数，这个类就是抽象类
//2.抽象类不能实例化
//3.子类继承抽象类，必须要实现纯虚函数，如果没有，子类也是抽象类
//抽象类的作用：为了继承约束，根本不知道未来的实现
class Shape{
    //纯虚函数
    virtual void sayArea()=0;
};

class Circle:public Shape{
public:
    Circle(int r){
        this->r=r;
    }
    void sayArea(){
        cout<<"园的面积"<<endl;
    }
private:
    int r;
};

int main(){
    Circle r(10);
    return 0;
}
*/

/*
//接口（只是逻辑上的划分，语法上和抽象类的写法没有区别）
//可以当做一个接口
class Drawable{
    virtual void draw()=0;
};
*/

/*
//模板函数（泛型）

//这两个函数业务逻辑一样，数据类型不一样

template <typename T>
void my_swap(T& a,T& b) {
    T tmp=a;
    a=b;
    b=tmp;
}


int main(){
    int a=10;
    int b=20;
    
    my_swap(a,b);
    cout<<a<<","<<b<<endl;
    
    
    char c='c';char d='d';
    my_swap(c,d);
    cout<<c<<","<<d<<endl;

    
    return 0;
}
*/

/*
//模板类
template<class T>
class A{
public:
    A(T a){
        this->a=a;
    }
protected:
    T a;
};

//普通类模板类
class B:public A<int>{
public:
    B(int a,int b):A<int>(a){
        this->b=b;
    }
private:
    int b;
};

//模板类继承模板类
template<class T>
class C:public A<T>{
public:
    C(T a,T c):A<T>(a){
        this->c=c;
    }
private:
    T c;
};

int main(){
    //模板类对象
    C<int> c(10,12);
    A<int> a(5);
    return 0;
}
*/

/*
//c++异常处理，根据抛出的异常数据类型，进入到相应的catch块中
int main(){
    try{
        int age=2000;
        if(age>300){
            throw 9.9;
        }
    }catch(int a){
        cout<<a<<endl;
    }catch(char *str){
        cout<<str<<endl;
    }catch(...){
        cout<<"未知异常"<<endl;
    }
    
    return 0;
}
*/

/*
//throw抛出函数外
void func(int x,int y){
    if(y==0){
        throw 10;
    }
}

int main(){
    try{
    func(10,0);
    }catch(int e){
        cout<<e<<endl;
    }
    return 0;
}
*/

/*
//抛出异常
//异常类
class MyException{
    
};

void func1(int a,int b){
    if(b==0){
        //throw new MyException; //不要抛出异常指针
        throw MyException();
    }
}

int main(){
    try{
        func1(20,0);
    }catch(MyException &e){
        cout<<"收到异常"<<endl;
    }catch(MyException *e1){
        cout<<"收到异常指针"<<endl;
        delete e1;
    }
    return 0;
}
*/

/*
//声明函数会抛出的异常类型
void func1(int a,int b) throw(int){
    if(b==0){
        throw 0;
    }
 }
 */

/*
//标准异常（类似java默认的那些异常）
#include <stdexcept>

class NullPointException:public exception{
public:
    NullPointException(char* msg):exception(){
        
    }
};


void func1(int a,int b){
    if(b>20){
        throw out_of_range("超出范围");
    }else if(b==NULL){
        throw NullPointException("为空");
    }else if(b==0){
        throw invalid_argument("参数不合法");
    }
}

int main(){
    try{
        func1(10,NULL);
    }catch(out_of_range msg){
        cout<<msg.what()<<endl;
//    }catch(invalid_argument msg){
//        cout<<msg.what()<<endl;
    }catch(NullPointException& msg){
        cout<<"为空"<<endl;
    }

    
    return 0;
}
*/

/*
//外部类异常
class Err{
public:
    class Exception{
        
    };
};
void funp(){
    throw Err::Exception();
}
*/
