#ifndef CAT_H
#define CAT_H
class Cat
{
public:
	Cat(int initialAge);
	~Cat();

	int GetAge();
	void SetAge(int age);

private:
	int itsAge;
};

#endif  //CAT_H

