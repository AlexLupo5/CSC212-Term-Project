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

(x1,y1)

(x2,y2)

(x3,y3)...

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
2. Navigate to the GitHub repo `convexHull` directory and copy the `main.cpp`, `convexHull.cpp`, and `convexHull.h` from the GitHub repository and paste them into the `convexHull` project files with the matching titles.
3. Remove the content of the `CMakeLists.txt` file and copy the `CMakeLists.txt` from the GitHub repository `convexHull` directory, then paste it into the `CMakeLists.txt` file in the `convexHull` project.
4. Refactor the `CMakeLists.txt` if needed.
5. Choose a file in the specified format for parsing (test files can be found in the test_cases folder)
6. In the `convexHull` project, run these two lines separately in the terminal (allows for one Txt file argument):

    ```
    g++ -std=c++11 main.cpp convexHull.cpp -o gen
    ./gen generic_file_name.txt
    ```


    A dotfile will be created named `convexHullGraphviz.dot`. The terminal will output the Convex Hull points or an error message if it fails to construct from the txt file values.
   

    The `convexHullGraphviz.dot` cannot be visualized with our SFML implementation and is meant to be copied and pasted into the Graphviz website ([Graphviz Online](https://dreampuf.github.io/GraphvizOnline/)).

**WITH SFML:**

1. Inside the `convexHull` project, create the files `mainSFML.cpp`, `graph.cpp`, and `graph.h`.
2. Navigate to the GitHub repo `SFML` directory and copy the `main.cpp`, `convexHull.cpp`, and `convexHull.h` files and paste them into the `convexHull` project files with the matching titles (main.cpp -> mainSFML.cpp).
3. Remove the content of the `CMakeLists.txt` file and copy the `CMakeLists.txt` from the current directory, then paste it into the `CMakeLists.txt` file in the `convexHull` project.
4. Refactor the `CMakeLists.txt` if needed.
5. The CMakeLists.txt logo should appear with two blue arrows going in a circle; click that, and it will refactor the CMakeLists.txt.
6. In the `convexHull` project, run these two lines separately in the terminal (allows for up to three Txt file arguments):

    ```
    g++ -std=c++11 mainSFML.cpp graph.cpp -o gen
    ./gen generic_file_name_1.txt generic_file_name_2.txt generic_file_name_3.txt
    ```

    Up to three dotfiles named `convexHull_#.dot` will be created depending on the number of file arguments provided. The terminal will also output the Convex Hull points.

    Take the desired `convexHull.dot` file(s) from the `convexHull` project and put them in the `cmake-build-debug` folder in the `convexHull` project.

    Then in the top right corner of CLion, press the `convexHull` tab and press `Edit Configurations`.

    Inside `Edit Configurations`, copy and paste this as a command line argument:

    ```
    convexHull_#.dot
    ```

    Then click the OK button and press the play button in the upper right corner of CLion, and it will output a visual shape of the Convex Hull(s).

