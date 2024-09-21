# AlgebraXpert
<h3><i>AlgebraXpert is a powerful desktop application built to solve a wide array of algebraic problems. It offers solutions for linear and quadratic equations, systems of equations with up to n variables, as well as advanced matrix operations such as calculating determinants, inverses, and eigenvalues.</i></h3>


## Built With
[![C++][c++]][cpp-url] [![qt][qt]][qt-url] [![qmake][qmake]][qmake-url]  [![qtest][qtest]][qtest-url]

## 1. Project Scope and Features

1. **Linear Equations Solver**
2. **Quadratic Equations Solver**
3. **Systems of Linear Equations Solver (up to n variables)**
4. **Matrix Operations [determinants, inverses, and eigenvalues]**

Users can navigate a simple text-based interface to select the type of problem they want to solve, input parameters, and receive solutions.

---

## 2. User Interface and Experience

- **Menu Navigation**:
    - A simple text-based interface where users choose the type of problem they want to solve.
    - Sub-menus for each category, allowing users to specify the exact operation (e.g., matrix multiplication or solving quadratic equations).
  
- **Input and Output**:
    - Error-handling features for invalid inputs (e.g., non-invertible matrices).
    - Solutions are presented clearly.

## 3. How to Run
1. Clone the repository.
2. Install g++ compiler run the following
```
sudo apt update
sudo apt install g++
```
2. you must install qmake to build the app (Linux - debian based distros)
```
sudo apt update
sudo apt install -y qt5-qmake
sudo apt install -y build-essential
```
3. Navigate to the project dir and Run the following
```
chmod +x run.sh
./run.sh
```
4. to run tests, navigate to tests dir in the repo and run
```
chmod +x run_tests.sh
./run_tests.sh
```



[qt]: https://img.shields.io/badge/qt-black?style=for-the-badge&logo=qt
[qt-url]: https://doc.qt.io/qtcreator/creator-how-to-install.html
[c++]: https://img.shields.io/badge/CPP-darkblue?style=for-the-badge&logo=cplusplus
[cpp-url]: https://cplusplus.com/doc/tutorial/

[qmake]: https://img.shields.io/badge/qmake-grey?style=for-the-badge&logo=
[qmake-url]: https://doc.qt.io/qtcreator/creator-how-to-install.html

[qtest]: https://img.shields.io/badge/qtest%20Framework-darkgreen?style=for-the-badge&logo=
[qtest-url]: https://doc.qt.io/qtcreator/creator-how-to-install.html