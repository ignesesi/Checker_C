#include <fstream>
#include <iostream>
#include <string>
#include <cstring>

struct answer
{
	short error_type = 0;
	///0 - no error
	///1 - difference
	///2 - shorter output
	///3 - longer output
	std::string correct = "",wrong = "";
	int line = -1;
};

inline void compile_cpp (std::string &problem, const std::string &name)
{
	char *compile = new char [problem.size() * 2 + 56];
	std::strcpy (compile, ("g++ " + problem + name + ".cpp -o " + problem + name).c_str());
	system(compile);

	delete[] compile;
	return;
}


inline void start_exe (std::string &problem, const std::string &name)
{
	char *exe = new char [problem.size() + 24];
	std::strcpy (exe, ("./" + problem + name).c_str());
	system(exe);
	
	delete[] exe;
	return;
}

inline void print_correct (const short &index)
{
	switch (index)
	{
		case 0:
			std::cout << "*";
			break;
		case 1:
			std::cout << "e";
			break;
		case 2:
			std::cout << "s";
			break;
		case 3:
			std::cout << "i";
			break;
	}
	std::cout << std::flush;
	return;
}

inline void print_error (int &correct, answer &ans)
{
	std::cout << "\n\nTests passed: " << correct << "\n";
	switch (ans.error_type)
	{
		case 1:///difference
			std::cout << "Find difference at line: " << ans.line << "\n";
			std::cout << "Correct answer: " << ans.correct << "\n";
			std::cout << "Your answer: " << ans.wrong << "\n";
			break;
		case 2:///shorter output
			std::cout << "\n\nYour output is shorter than the correct output.\n";
			break;
		case 3:///longer output
			std::cout << "\n\nYour output is longer than the correct output.\n";
			break;
	}
	return;
}

inline answer check_answers (std::string &problem)
{
	char *name = new char [problem.size() + 20];
	///quick.out
	std::strcpy (name, (problem + "_quick.out").c_str());
	std::ifstream quick(name);

	///slow.out
	std::strcpy( name, (problem + "_slow.out").c_str());
	std::ifstream slow(name);

	answer ans;
	for(int line = 0; !slow.eof(); line++)
	{
		std::string q, s;
		quick >> q;
		slow >> s;
		//getline(quick, q);
		//getline(slow, s);
		if(q != s)
		{
			delete[] name;
			quick.close();
			slow.close();
			ans.line = line;
			ans.correct += s;
			ans.wrong += q;
			ans.error_type = 1;
			return ans;
		}
	}
	/*if(!slow.eof())
	  {
	  std::cout << "BLA\n";
	  ans.error_type = 2;
	  }
	  if(!quick.eof())
	  {
	  std::cout << "ALO\n";
	  ans.error_type = 3;
	  }*/
	delete[] name;
	quick.close();
	slow.close();
	return ans;
}

int main ()
{
	std::string problem;
	std::cout << "Problems name: ";
	std::cin >> problem;
	std::cout << "\n";
	
	compile_cpp (problem, "_test_generator");
	compile_cpp (problem, "_quick");
	compile_cpp (problem, "_slow");

	int correct = 0;

	while (true)
	{
		start_exe (problem, "_test_generator");
		//Sleep (5)
		start_exe (problem, "_quick");
		start_exe (problem, "_slow");

		answer ans = check_answers (problem);
		if (ans.error_type == 0)
		{
			print_correct (correct % 4);
			correct ++;
			/*if(correct % 101 == 0)
			{
				std::cout << std::endl;
			}*/
			//std::cout<<"*";
		}
		else
		{
			print_error (correct, ans);
			break;
		}
	}
	return 0;
}
