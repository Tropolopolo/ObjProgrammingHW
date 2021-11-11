#include "View.h"
#include "Trainer.h"
#include "FileHandle.h"
#include "Sort.h"

#define spacer "-------------------"
class Controller
{
public: 
	Controller(View* view, Trainer* tra, FileHandle* file) : v(view), t(tra), f(file) {};

	void cli();
	void exeCMD(int);

	void exeMonster(int, Monster*);
	void exeTrainer(int, Trainer*);
	void exeFileHandle(int, FileHandle*);
	Monster* getMonsterInfo();


private:
	View* v;
	Trainer* t;
	FileHandle* f;
};