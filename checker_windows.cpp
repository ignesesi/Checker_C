#include <windows.h>
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

inline void start_exe (std::string &problem, const std::string &name)
{
    char *exe = new char [problem.size() + 20];
    std::strcpy (exe, (problem + name).c_str());
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
    return;
}

inline void print_error (int &correct, answer &ans)
{
    switch (ans.error_type)
    {
        case 1:///difference
            std::cout << "\n\nTests passed: " << correct << "\n";
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
    //###################
    /*std::ofstream check("check.txt");*/

    int correct = 0;
    while (true)
    {
        start_exe (problem, "_test_generator.exe");
        //Sleep (5);
        start_exe (problem, "_quick.exe");
        start_exe (problem, "_slow.exe");

        answer ans = check_answers (problem);
        if (ans.error_type == 0)
        {
            print_correct (correct % 4);
            correct ++;
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
