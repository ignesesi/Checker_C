
The programs, which you are testing, must be named **task_quick.cpp** and **task_slow.cpp** and must be in the same directory in which is the **checker**.

The test generator must be named **task_test_generator.cpp** and also must be in the same directory.

The result of the generator is saved in **random.in**. The result of **task_slow.cpp** is saved in **task_slow.out** and the result of **task_quick.cpp** is in **task_quick.out**.

Once all of the files are named like the ways explained above and **checker.cpp** is compiles, all you need to is to open terminal and write:

```
./checker
```
Then you must write the name of the problem. In the example it it **park**. The output is something like this:
```
Problem name: park

*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi*esi

Tests passed: 441
Find difference at line: 0
Correct answer: 0
Your answer:
```
Every **symbol** means that the output of **task_quick.cpp** and **task_slow.cpp** is the same. The program stops when there is some difference so you can see which program is wrong and why.

There are three types of error:
* Find difference at line:
* Your output is shorter than the correct output.
* Your output is longer than the correct output.
