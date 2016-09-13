#include <iostream>
using namespace std;

template <typename T>
class SmartPtr;

template <typename T>
class H_Ptr{
private:
	friend class SmartPtr<T>;
	H_Ptr(T *ptr):p(ptr),count(1){}
	~H_Ptr(){
		delete p;
	}
	int count;
	T* p;
};

template <typename T>
class SmartPtr{
public:
	SmartPtr(T *ptr):rp(new H_Ptr<T>(ptr)){}
	SmartPtr(const SmartPtr<T> &other):rp(other.rp){
		++rp->count;
	}
	SmartPtr<T>& operator=(const SmartPtr<T> &rhs){ //重载=运算符
		++rhs.rp->count;
		if(--rp->count == 0){
			delete rp;
		}
		rp = rhs.rp;
		return *this;
	} 
	T& operator*(){
		return *(rp->p);
	}
	T& operator->(){
		return rp->p;
	}
	~SmartPtr(){
		if(--rp->count == 0){
			delete rp;
		}
		else cout<<"There remains "<<rp->count<<" pointers"<<endl;
	}
private:
	H_Ptr<T> *rp;  //辅助类对象指针
};


int main(){
	int *p = new int(2);
	{
		SmartPtr<int> ptr1(p);
		{
			SmartPtr<int> ptr2(ptr1);
			{
				SmartPtr<int> ptr3 = ptr2;
				std::cout<<*ptr1<<std::endl;
				*ptr1 = 20;
				cout<<*ptr2<<endl;
			}
		}
	}
	system("pause");
	return 0;
}