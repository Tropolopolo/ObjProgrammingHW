#include "View.h"
#include <fstream>

#define Default_Path "/media/sf_CSE2315/Experiments/"


class FileHandle
{
public:
	FileHandle(std::string f) : filename(f) { path = Default_Path; };
	FileHandle(std::string f, std::string p) : filename(f), path(p) {};
	void Save(Trainer*);
	Trainer* Load();

	template<typename T>
	T* tempLoad()
	{

	}

	template<typename T>
	void tempSave(T t)//Must be passed by referance.
	{
		file.open(path + filename);

		if (file.fail())
		{
			v->print("Error: Failed to Open " + filename);
			exit(1);
		}

		file << *t;
		file.close();
	}

	//gets
	std::string getFileName();
	std::string getPath();

private:
	std::fstream file;
	std::string filename;
	std::string path;
	View* v;
};



