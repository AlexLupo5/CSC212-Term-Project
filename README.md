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

<h2 align="center">Setup Instructions:</h2>

This project was created using CLion.

The project can be executed in two modes: one incorporating SFML for generating visualizations of a convex hull data structure, and another mode without SFML. Despite the absence of SFML in the latter, both modes produce .dot files that can be used for visualization, in addition to printing the Convex Hull points to the terminal.

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

**WITHOUT SFML:**

In CLion, create a project using C++ 11, titled `convexHull`.

1. Inside the `convexHull` project, create the files `main.cpp`, `convexHull.cpp`, `convexHull.h`, and `convexHull.txt`.
2. Copy the `main.cpp` (convexHull), `convexHull.cpp`, `convexHull.h`, and `convexHull.txt` from the GitHub repository and paste them into the `convexHull` project files with the matching titles.
3. Remove the content of the `CMakeLists.txt` file and copy the `CMakeLists.txt (convexHull)` from the GitHub repository, then paste it into the `CMakeLists.txt` file in the `convexHull` project.
4. Refactor the `CMakeLists.txt` if needed.
5. In the `convexHull` project, run these two lines separately in the terminal:

    ```bash
    g++ -std=c++11 main.cpp convexHull.cpp -o gen
    ./gen convexHull.txt
    ```

    Three dot files will be created named `convexHull.dot`, `convexHull2.dot`, and `convexHullGraphviz.dot`. The terminal will output the Convex Hull points or an error message if it fails to construct from the txt file values.

    To produce a visualization of the convex hull, `convexHull.dot` and `convexHull2.dot` files require SFML.

    The `convexHullGraphviz.dot` cannot be visualized with our SFML implementation and is meant to be copied and pasted into the Graphviz website ([Graphviz Online](https://dreampuf.github.io/GraphvizOnline/)).

**WITH SFML:**

In CLion, create two separate projects both using C++ 11, one titled `convexHull` and the other called `HelloSFML`.

1. Inside the `convexHull` project, create the files `main.cpp`, `convexHull.cpp`, `convexHull.h`, and `convexHull.txt`.
2. Copy the `main.cpp` (convexHull), `convexHull.cpp`, `convexHull.h`, and `convexHull.txt` from the GitHub repository and paste them into the `convexHull` project files with the matching titles.
3. Remove the content of the `CMakeLists.txt` file and copy the `CMakeLists.txt (convexHull)` from the GitHub repository, then paste it into the `CMakeLists.txt` file in the `convexHull` project.
4. Refactor the `CMakeLists.txt` if needed.
5. Inside the `HelloSFML` project, create the files `main.cpp`, `graph.cpp`, and `graph.h`.
6. Copy the `main.cpp` (SFML), `graph.cpp`, and `graph.h` from the GitHub repository and put them into the `HelloSFML` project files with the matching title.
7. Remove the content of the `CMakeLists.txt` file and copy the `CMakeLists.txt (SFML)` from the GitHub repository, then paste it into the `CMakeLists.txt` file in the `HelloSFML` project.
8. The CMakeLists.txt logo should appear with two blue arrows going in a circle; click that, and it will refactor the CMakeLists.txt.
9. In the `convexHull` project, run these two lines separately in the terminal:

    ```bash
    g++ -std=c++11 main.cpp convexHull.cpp -o gen
    ./gen convexHull.txt
    ```

    Three dot files will be created named `convexHull.dot`, `convexHull2.dot`, and `convexHull_Graphviz.dot`. Also, the terminal will also output the Convex Hull points.

    Take the `convexHull.dot` and `convexHull2.dot` files from the `convexHull` project and put them in the `cmake-build-debug` folder in the `HelloSFML` project.

    Then in the top right corner of CLion, press the `HelloSFML` tab and press `Edit Configurations`.

    Inside of the `Edit Configurations`, copy and paste this into the Program arguments:

    ```
    convexHull.dot convexHull2.dot
    ```

    Then click the OK button and press the play button in the upper right corner of CLion, and it will output the graph of the Convex Hull.

