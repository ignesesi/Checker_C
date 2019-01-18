
The programs, which you are testing, must be named **task1.cpp** and **task2.cpp** and must be in the same directory in which is the **checker**.

The test generator must be named **generator.cpp** and also must be in the same directory.

The result of the generator is saved in **test.in**. The result of **task1.cpp** is saved in **ans1.out** and the result of **task2.cpp** is in **ans2.out**.

Once all of the files are named like the ways explained above all you need to is to open terminal and write:

```
./checker
```

**checker_freopen** don't create any files. Your cpp files must use files for input and output. In the example programs is used this way, but it is commented:

```cpp
#include <cstdio>

//code

int main() {
	freopen("test.in", "r", stdin);
	freopen("ans.out", "w", stdout);
	
	std::cin >> ... ;
	std::cout << ... ;
	//code
}
```

Both checkers output is something like this:
```
Start checking...

...............................................................................................................DIFF

DONE
```
Dot **.** means that the output of **task1.cpp** and **task2.cpp** is the same. **DIFF** means that there is some difference and the checker stops so you can see which program is wrong and why.

