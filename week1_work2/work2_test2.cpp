#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;
//1.Animal이라는 기본 클래스 정의 (makeSound()라는 순수가상함수 포함)
//2.Animal 클래스를 상속받아 다양한 동물 클래스를 생성
//3.메인함수에서 Animal타입의 포인터 배열을 선언하고 Dog, Cat, Cow를 각각 배열의 원소로 선언 -> Animal 배열문을 반복문으로 순회하면서 각 동물의 울음소리를 내게 한다.

class Animal //애니멀 부모클래스
{
public:
	Animal() {}
	virtual void makeSound() = 0;
	virtual void makeMove() = 0;
	virtual ~Animal() {}
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
	int count;
public:
	Zoo() : count(0) {
		for (int i = 0; i < 10; i++) {
			animals[i] = nullptr;
		}
	}

	void addAnimal(Animal* animal) {

		if (count < 10) { // 배열 초과 방지
			animals[count] = animal;
			count++;
		}else {
			cout << "Zoo is full!" << endl;
		}
	}

	void performActions() {

		for (int i = 0; i < count; i++) {
			animals[i]->makeSound();
			animals[i]->makeMove();
		}

	}
	~Zoo() {
		cout << "방생" << endl;
		for (int d = 0; d < count; d++) {
			if (animals[d] != nullptr) {
			delete animals[d];
		}
		}
	}

};

Animal* createRandomAnimal() {
	
		int a = rand() % 3;
	
		if (a==0) {
			return new dog;		
		}
		if (a==1) {
			return new cat;			
		}
		if (a==2) {
			return new cow;			
		}

	
}


int main()
{
	srand(time(NULL));
	Zoo dreamland;

	for (int i = 0; i < 10; i++) {
		dreamland.addAnimal(createRandomAnimal());
	}

	cout << "animals are making sounds and moving!" << endl;
	dreamland.performActions();

	return 0;
}