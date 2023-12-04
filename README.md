# CSC212-Term-Project
**Project:
Convex Hull

Problem/Solution:


**Requirements:
**Convex Hull to**
^^^

**_Implement Graham’s Scan algorithm_**
- find a way to save a visualization
  - can generate a DOT file

**_Read a set of points from a file_**

**Status Update**
- For current working version of convexHull.cpp please download convexHull.cpp and convexHull.h to your program.
convexHull (version 4)
  * convexHull can be called in main by convexHull "name of object"("file name");
  * convexHull.cpp also allows the user to print the output to the terminal or to a dot file by either calling "name of object".print() or "name of object".dot() in the main.cpp file.
  * convexHull.dot and convexHull2.dot files can be visualized by using graph.cpp
  * convexHullGraphviz.dot file can be visualized by copying and pasting it into https://dreampuf.github.io/GraphvizOnline/

 
---


<h2 align="center">Setup Instructions</h2>

This project was created using CLion.

This project incorporates the SFML library for generating visualizations of a convex hull data structure from a dotfile. 

Our code prints Convex Hull points to the terminal and produces two different types of dotfiles for visualization purposes when given a file in the following format:
```
(x1,y1)
(x2,y2)
(x3,y3)
...
```
---

**INSTALL CLION:**

You can install CLion onto your computer using this link: [CLion Download](https://www.jetbrains.com/clion/download/)

1. Click the download CLion for your operating system.
2. Open the downloaded file and follow the provided instructions.
3. Once installed, open the software and sign in with a JB account.

Now CLion is installed and ready to use.

---

**INSTALLING SFML:**

The external library SFML was used in this project.

**MacOS:**

1. Download homebrew from [here](https://brew.sh/).
2. Open the terminal and run the command provided on the website to install homebrew.
3. Type `brew install sfml` in the terminal to install SFML.

**Windows:**

Follow the SFML documentation instructions [here](https://www.sfml-dev.org/tutorials/2.6/).

<h2 align="center">Project Instructions</h2>

---

**No SFML Required:**

In CLion, create a project using C++ 11, titled `convexHull`.

1. Inside the `convexHull` project, create the files `main.cpp`, `convexHull.cpp`, and `convexHull.h`.
2. Navigate to the GitHub repo `convexHull` directory and copy the `main.cpp`, `convexHull.cpp`, and `convexHull.h` files from the GitHub repository and paste them into the `convexHull` project files with the matching titles.
3. Remove the content of the `CMakeLists.txt` file and copy the `CMakeLists.txt` from the GitHub repository `convexHull` directory, then paste it into the `CMakeLists.txt` file in the `convexHull` project.
4. Refactor the `CMakeLists.txt` if needed.
5. Choose a txt file with text in the specified format for parsing (test files can be found in the `test_cases` folder)
6. In the `convexHull` project, run these two lines separately in the terminal (allows for one Txt file argument):

    ```
    g++ -std=c++11 main.cpp convexHull.cpp -o gen
    ./gen generic_file_name.txt
    ```


    A dotfile will be created named `convexHullGraphviz.dot`. The terminal will output the Convex Hull points or an error message if it fails to construct from the txt file values.
   

    The `convexHullGraphviz.dot` cannot be visualized with our SFML implementation and is meant to be copied and pasted into the Graphviz website ([Graphviz Online](https://dreampuf.github.io/GraphvizOnline/)).

**WITH SFML:**

In CLion, create a project using C++ 11, titled `convexHull` with SFML:
/Users/"Computer Name"/CLionProjects/SFML/convexHull

1. Inside the `convexHull` project, create the files `main.cpp`, `convexHull.cpp`, `convexHull.h`, `graph.cpp`, and `graph.h`.
2. Remove any content inside the files if there is any
3. Navigate to the GitHub repo `Convex Hull with SFML` directory and copy the `main.cpp`, `convexHull.cpp`, `convexHull.h`, `graph.cpp`, and `graph.h` files and paste them into the `convexHull` project files with the matching titles. For example (main.cpp -> main.cpp).
4. Remove the content of the `CMakeLists.txt` file and copy the `CMakeLists.txt` from the `Convex Hull with SFML` directory, then paste it into the `CMakeLists.txt` file in the `convexHull` project.
5. The CMakeLists.txt logo should appear with two blue arrows going in a circle; click that, and it will refactor the CMakeLists.txt.
6. Before running the code, you may create txt files using the command `touch (name of txt).txt ` in the terminal.
7. After creating your txt files, you may input your data in the txt file with the format:

    ```
   (x1,y1)
   (x2,y2)
   (x3,y3)
   ...
    ```
  
8. After creating your data sets in the txt file(s), drag each txt file into the cmake folder `cmake-build-debug` located on the left side of the project.
9. Next navigate to the top right of your project in clion and locate the three dots next to the debug button
10. Click on the three dots followed by `Edit...` where you can then input up to three txt file inputs in program arguments:

    Ex: test1.txt test2.txt test3.txt
    
11. Then click the blue OK button at the bottom of the configurations
12. After closing out of the edit configurations tab, you are then able to run the code using the run button located at the top right corner of your project.

    Up to three dotfiles named `convexHull_#.dot` will be created depending on the number of file          arguments provided. The terminal will also output the Convex Hull points of each file.

    In the rare case that the dot files do not get automatically put into the cmake-build-debug:
    
    Drag the three desired `convexHull.dot` file(s) from the `convexHull` project and put them in the      `cmake-build-debug` folder in the `convexHull` project.
    ```
    convexHull_#.dot
    ```
    Then in the top right corner of CLion, press the run button again.
