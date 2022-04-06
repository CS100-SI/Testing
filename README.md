## Cloning Repo
* Clone the repo
  * https://github.com/CS100-SI/Introductory
* Create a new branch and enter it
  * Name the branch with your first name and last name initial followed by `-main`
    * i.e. JohnT-main
* Create a `CMakeLists.txt` file in your branch
* Push the branch on to the repo
* Open a pull request in GitHub using the `Pull requests` tab and `New pull request`.
  * You have successfully done this practice if I **reject** the request without labeling an `Issue` to it.
    * If you get an `Issue` response (you can find this within your pull request), follow the given feedback to fix your cloning/branching.
    * Add and commit your fixes, but make sure to include `fixes #<Issue Number>` in your commit  
        * The `Issue Number` can be found next to the Issue's title.

For all repos in these sessions, you will be essentially repeating the above steps. The branch you create will be your "main". 
If you need to branch more from there, you can do so, and you have free reign to review or merge pull requests to your **own main branch**.

If you created a branch, but it does not contain essential files from `main`. Here's what you can do:
* `git checkout main`
* `git fetch`
* `git checkout [branch name]`
* `git rebase main`

Now, you should have the up-to-date information

## CMake and Unit Testing
CMake is is a simple tool used for designing, building and testing/running code.  
To start, you need to first install `CMake`. If you are planning on using `hammer`, you can ignore this part and jump straight to **Code** section.  
### Installing CMake
In your terminal, type
```
sudo apt-get -y install cmake
```
to install CMake.

Then type
```
cmake -version
```
to see what version your cmake is and if it was installed correctly. 
Ideally, you should see something along the lines of this (your version may be different):
```
cmake version 3.16.3
```
And, that's essentially it. Yay! You got `CMake` installed!

### Code
Using `CMake` requires a `CMakeLists.txt`, and I'm sure you've seen this in your Lab 1 already. 
But as a refresher, I've gone ahead and provided it here again.  
To start, you'll need to include the following in `CMakeLists.txt`:
```CMake
CMAKE_MINIMUM_REQUIRED(VERSION #[[Your CMake Version]])
SET(CMAKE_CXX_STANDARD 17)

ADD_EXECUTABLE(#[[Executable Name]] 
    #[[All necessary .cpp files]]
)
```
You can have multiple `ADD_EXECUTABLE`'s within a `CMake`. 
This is part of why `CMake` is so useful; a single `CMake` can compile multiple executables doing different things all at once.

This is the most I'll give you regarding `CMake`. There's so much you can do with it, but this is essentially all you'll need for these sessions.  

### Testing Time
When you cloned this repository, you also got two `.h` files and a `test.cpp`. Below is what each of the `.h` files do.  
```C
## Arithmetic.h ##

Add(x, y);
    Desc: Adds x and y together
    In: int, int
    Ret: int
Sub(x, y);
    Desc: Subtracts y from x
    In: int, int
    Ret: int
Mult(x, y);
    Desc: Multiplies x by y
    In: double, double
    Ret: double
Div(x, y);
    Divides x by y
    In: double, double
    Ret: double
```
```C++
## LinkedList.h ##
Node:
    value: int
    next: Node*
    Node(int value = 0, Node* next = nullptr);
LinkedList:
    head: Node*
    tail: Node*
    LinkedList();
    Append(x);
        Desc: Appends x to the end of the list
        In: int
        Ret: void
    Pop();
        Desc: Pops the front of the list and returns the value. Returns -1 when list is empty.
        In: void
        Ret: int
    GetList();
        Desc: Returns the list foward with a newline after each value. Returns "Empty\n" when list is empty.
        In: void
        Ret: string
```
Your (group's) task is to test both of these files and to fix any errors or bugs you may have found in them using `gtest`.
I have include a `test.cpp` file for you to write your tests in with an example test (This **will not** count towards your number of tests).  
For each of the files there should be a minimum number of tests:
* `Arithmetic.h`
    * 2-3+ tests per function (this includes at least *one* **edge case**)
* `LinkedList.h`
    * 5-7+ **total** tests with a mix of the functions (this includes at least *two* **edge cases**)

You will need to fix the `CMakeLists.txt` to include both the `gtest` and to create the executable for test.
Simply put, your `CMakeLists.txt` should look something like this:
```CMake
CMAKE_MINIMUM_REQUIRED(VERSION #[[Your CMake Version]])
ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 17)

ADD_EXECUTABLE(#[[Executable Name]]
      #[[All necessary .cpp files]]
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
```
You will need to fill out the rest.  

#### IMPORTANT
If you installed `CMake` **on your own computer**, use `cmake .` instead of `cmake3 .`. 
This is just a disparity between the version used in CS100 labs and the current `CMake` version.
You'll still use `make` after.

Also notice that you can put code in the Tests as you would a normal function. You can also have multiple `EXPECT_EQ` per test. Use this to your advantage, especially since `LinkedList.h` requires you to create and use an object as you normall would.