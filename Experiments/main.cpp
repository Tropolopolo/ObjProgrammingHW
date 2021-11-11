#include "Controller.h"

template<typename T, int N>
class Array
{
private:
	T m_Array[N];

public:
	int GetSize() const { return N; }
};
/*
When to use templates?

Templates are really useful but can cause issues when the become too complex.

if a template were to become too complex and then there is an issue with the code then the process to figure out what is wrong with the code becomes much harder due to using variable types.


*/


int main(int argc, char* argv[])
{
	Trainer* t = new Trainer("Adam", 0);
	FileHandle* f = new FileHandle("Monster.txt");
	View* v = new View(t);
	Controller* c = new Controller(v, t, f);
	c->cli();
	return 0;
}








//What is next?
/*
1. Look into how to do generic classes.
	This is of peticular interest for the FileHandling class since we would want to be able to save the information of multiple types of classes without having to create inumerable amounts of methods or classes.

2. See about doing some object inheritance particularly with the Monster class creating different classes for the different types of monsters.
	2'. Afterwards we will be able to implement polymorphism

3. Look into doing some threading along with working with the mutex class to restrict variables.

4. Look into other librarys that are included in c++.

5. Check out Regular Expressions, Smart Pointers, etc.

*/
