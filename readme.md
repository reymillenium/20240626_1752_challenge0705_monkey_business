# COP 1334 Assignment - Introduction to C++

## Chapter 7: Challenge 05

## Title: Monkey Business

### Exercise Description:

A local zoo wants to keep track of how many pounds of food each of its three monkeys eats each day during a typical week. Write a program that stores this information in a two-dimensional 3 × 5 array, where each row represents a different monkey, and each column represents a different day of the
week. The program should first have the user input the data for each monkey. Then, it should create a report that includes the following information:

• Average amount of food eaten per day by the whole family of monkeys.

• The least amount of food eaten during the week by any one monkey.

• The greatest amount of food eaten during the week by any one monkey.

_Input Validation: Do not accept negative numbers for pounds of food eaten._

## Execution from the Terminal (Alternative way without an IDE):

We must provide to the Compiler the same switches that we usually do in the IDE:

```terminal
g++ -Wall -std=c++17 main.cpp
```

That will create a file named 'a.out' if you are working in MacOS or a .exe file if you are on Windows. That's the default executable file's name when we don't provide a name.

But we can also specify the name of the resulting executable file:

```terminal
g++ -Wall -std=c++17 main.cpp -o your_prefered_executable_file_name
```

And in order to run that a.out file, we must execute on the terminal:

```terminal
 % ./a.out
```

## Result of Execution on the Terminal (MacOS example):

```terminal
reinier@reinier % ./your_prefered_executable_file_name

Please type how many pounds of food the 1st monkey will eat on Monday: 2.4
Please type how many pounds of food the 1st monkey will eat on Tuesday: 23.3
Please type how many pounds of food the 1st monkey will eat on Wednesday: 23.5
Please type how many pounds of food the 1st monkey will eat on Thursday: 0.4
Please type how many pounds of food the 1st monkey will eat on Friday: 3.2
Please type how many pounds of food the 2nd monkey will eat on Monday: 32.5
Please type how many pounds of food the 2nd monkey will eat on Tuesday: 34.2
Please type how many pounds of food the 2nd monkey will eat on Wednesday: 54.3
Please type how many pounds of food the 2nd monkey will eat on Thursday: 54.7
Please type how many pounds of food the 2nd monkey will eat on Friday: 3.6
Please type how many pounds of food the 3rd monkey will eat on Monday: 434.9
Please type how many pounds of food the 3rd monkey will eat on Tuesday: 4.3
Please type how many pounds of food the 3rd monkey will eat on Wednesday: 54.0
Please type how many pounds of food the 3rd monkey will eat on Thursday: 34.3
Please type how many pounds of food the 3rd monkey will eat on Friday: 34.3

The average amount of food eaten per day by the whole family of monkeys is 52.93 lbs.
The least amount of food eaten during the week by any one monkey is 0.40 lbs.
The greatest amount of food eaten during the week by any one monkey is 434.90 lbs.
  
Process finished with exit code 0
reinier@reinier % 
```

### Author

**Reinier Garcia**

* [Github](https://github.com/reymillenium)
* [Twitter](https://twitter.com/ReinierGarciaR)
* [Linkedin](https://www.linkedin.com/in/reiniergarcia/)
* [Website](https://www.reiniergarcia.dev/)
* [Stack Overflow](https://stackoverflow.com/users/9616949/reinier-garcia)

### License

Copyright © 2024, [Reinier Garcia](https://github.com/reymillenium).


