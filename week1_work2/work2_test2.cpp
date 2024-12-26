#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;
//1.Animal�̶�� �⺻ Ŭ���� ���� (makeSound()��� ���������Լ� ����)
//2.Animal Ŭ������ ��ӹ޾� �پ��� ���� Ŭ������ ����
//3.�����Լ����� AnimalŸ���� ������ �迭�� �����ϰ� Dog, Cat, Cow�� ���� �迭�� ���ҷ� ���� -> Animal �迭���� �ݺ������� ��ȸ�ϸ鼭 �� ������ �����Ҹ��� ���� �Ѵ�.

class Animal //�ִϸ� �θ�Ŭ����
{
public:
	Animal() {}
	virtual void makeSound() = 0;
	virtual void makeMove() = 0;
	virtual ~Animal() {}
};

class dog : public Animal //������ �ڽ� Ŭ����
{
public:
	void makeSound() {
		cout << "Dog barks : wall! wall!" << endl;
	}
	void makeMove() {
		cout << "And runs around!!" << endl;
	}
};

class cat : public Animal //����� �ڽ� Ŭ����
{
public:
	void makeSound() {
		cout << "Cat meows : Yaong!! Yaong!!" << endl;
	}
	void makeMove() {
		cout << "And jumped into the box!! " << endl;
	}
};

class cow : public Animal //�� �ڽ� Ŭ����
{
public:
	void makeSound() {
		cout << "Cow moos : ummeh~ ummeh~" << endl;
	}
	void makeMove() {
		cout << "And eat grass!!" << endl;
	}
};

class Zoo //������ �迭 Ŭ����
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

		if (count < 10) { // �迭 �ʰ� ����
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
		cout << "���" << endl;
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