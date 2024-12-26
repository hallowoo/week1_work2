#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
//1.Animal이라는 기본 클래스 정의 (makeSound()라는 순수가상함수 포함)
//2.Animal 클래스를 상속받아 다양한 동물 클래스를 생성
//3.메인함수에서 Animal타입의 포인터 배열을 선언하고 Dog, Cat, Cow를 각각 배열의 원소로 선언 -> Animal 배열문을 반복문으로 순회하면서 각 동물의 울음소리를 내게 한다.

class Animal //애니멀 부모클래스
{
public:
	Animal() {}
	virtual void makeSound() {};
	virtual void makeMove() {};
};

class dog : public Animal //강아지 자식 클래스
{
public:
	void makeSound() {
		cout << "Dog barks : wall! wall!" << endl;
	}
	void makeMove() {
		cout << "And runs around!!" << endl;
	}
};

class cat : public Animal //고양이 자식 클래스
{
public:
	void makeSound() {
		cout << "Cat meows : Yaong!! Yaong!!" << endl;
	}
	void makeMove() {
		cout << "And jumped into the box!! " << endl;
	}
};

class cow : public Animal //소 자식 클래스
{
public:
	void makeSound() {
		cout << "Cow moos : ummeh~ ummeh~" << endl;
	}
	void makeMove() {
		cout << "And eat grass!!" << endl;
	}
};

class Zoo //동물원 배열 클래스
{
private:
	Animal* animals[10];
public:
	void addAnimal(Animal* animal) {
				
		int i = -1;
		i = i++;
		animals[i] = new Animal(*animal);
	}

	void performActions() {

		for (int i = 0; i < 3; i++) {
			animals[i]->makeSound();
			animals[i]->makeMove();
		}

	}
	~Zoo() {
		cout << "방생" << endl;
		for (int d = 0; d < 10; d++) {
			delete animals[d];
		}
	}

};

Animal* creatRandomAnimal() {
	
	Animal* animals[10];
	srand(time(NULL));

	for (int i = 0; i < 10; i++) {
		int a = rand() % 3;
		if (a == 0) { animals[i] = new dog; }
		if (a == 1) { animals[i] = new cat; }
		if (a == 2) { animals[i] = new cow; }

	}return 0;
}


int main()
{
	/*Animal* animals[3];
	animals[0] = new dog;
	animals[1] = new cat;
	animals[2] = new cow;
	cout << "animals makes sounds!!" << endl;

	for (int i = 0; i < 3; i++) {
		animals[i]->makeSound();
	}*/

	Zoo dreamland;

	Animal* a = new dog;
	dreamland.addAnimal(a);

	return 0;
}