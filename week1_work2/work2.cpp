#include <iostream>
#include <string>
using namespace std;
//1.Animal이라는 기본 클래스 정의 (makeSound()라는 순수가상함수 포함)
//2.Animal 클래스를 상속받아 다양한 동물 클래스를 생성
//3.메인함수에서 Animal타입의 포인터 배열을 선언하고 Dog, Cat, Cow를 각각 배열의 원소로 선언 -> Animal 배열문을 반복문으로 순회하면서 각 동물의 울음소리를 내게 한다.

class Animal
{
public:
	Animal() {}
	virtual void makeSound(){};
};

class dog : public Animal
{
public:
	void makeSound() {
		cout << "Dog barks : wall! wall!" << endl;
	}
};

class cat : public Animal
{
public:
	void makeSound() {
		cout << "Cat meows : Yaong!! Yaong!!" << endl;
	}
};

class cow : public Animal
{
public:
	void makeSound() {
		cout << "Cow moos : ummeh~ ummeh~" << endl;
	}
};

int main()
{
	Animal* animals[3];
	animals[0] = new dog();
	animals[1] = new cat();
	animals[2] = new cow();
	cout << "animals makes sounds!!" << endl;

	for (int i = 0; i < 3; i++) {
		animals[i]->makeSound();
	}


}