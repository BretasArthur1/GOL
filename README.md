# Conway's Game of Life

This project implements the famous Conway's Game of Life in C++, using the MVC (Model-View-Controller) pattern. The game simulates the behavior of living and dead cells on a two-dimensional grid and evolves them according to Conway's rules.

## 📊 Table of Contents

1. [Description](#description)
2. [MVC Pattern](#mvc-pattern)
3. [Technologies Used](#technologies-used)
4. [Project Structure](#project-structure)
5. [How to Run](#how-to-run)
6. [Results](#results)
7. [Contributions](#contributions)
8. [License](#license)
9. [Contact](#contact)

## 📝 Description

The Game of Life is a cellular automaton devised by mathematician John Conway. Cells on a two-dimensional grid interact with their neighbors according to simple rules that determine whether they live, die, or are born in the next generation. Despite its simple rules, the Game of Life can produce complex and interesting behavior.

### Main Goals

- **Simulate the Game of Life:** Implement the basic rules governing cell interactions.
- **MVC Architecture:** Provide a clear separation between game logic (model), visualization (view), and interaction control (controller).
- **User Interaction:** Allow control over generations and iterations via the terminal.
- **Modular Interface:** Make the code easy to maintain and extend.

## 🎯 MVC Pattern

The MVC (Model-View-Controller) pattern is used to organize the code in a modular and maintainable way:

- **Model:** Responsible for all game logic and rules, storing the current state of the simulation. For the Game of Life, the model manages the grid state and the rules that determine cell transitions.
- **View:** Responsible for presenting the current state of the simulation to the user. The view does not handle game logic; it only displays information.
- **Controller:** Acts as an intermediary between the model and the view. It receives user inputs (such as start or stop commands), updates the model accordingly, and instructs the view to refresh the display.

This structure ensures each part of the code has a single responsibility, making maintenance and extension easier.

## 🛠 Technologies Used

- **Programming Language:** C++
- **Compiler:** g++ or equivalent

## 📂 Project Structure

```plaintext
conway_game_of_life/
│
├── JV_PJA_Main.cpp       # Program entry point
├── JV_PJA_Controller.cpp # Application controller
├── JV_PJA_Controller.h   
├── JV_PJA_Model.cpp      # Game logic and grid state
├── JV_PJA_Model.h
├── JV_PJA_View.cpp       # Responsible for displaying the game's state
├── JV_PJA_View.h
├── README.md             # Project documentation
└── LICENSE               # License information
```

- **JV_PJA_Main.cpp:** Contains the main function that initializes the game.
- **JV_PJA_Controller.cpp / JV_PJA_Controller.h:** Controls interaction logic between the user and the simulation, calling model methods and updating the view.
- **JV_PJA_Model.cpp / JV_PJA_Model.h:** Implements the Game of Life rules and logic, managing the state of cells and grid updates.
- **JV_PJA_View.cpp / JV_PJA_View.h:** Responsible for rendering the grid and the state of cells to the screen without modifying game logic.

## 🚀 How to Run

### 1. Clone the repository

```bash
git clone https://github.com/BretasArthur1/conway_game_of_life
cd conway_game_of_life
```

### 2. Compile the project

```bash
g++ -o GameOfLife JV_PJA_Main.cpp JV_PJA_Controller.cpp JV_PJA_Model.cpp JV_PJA_View.cpp
```

### 3. Run the program

```bash
./GameOfLife
```

The program runs in the terminal where you can observe the evolution of cells on the grid at each iteration.

## 🏆 Results

This project correctly implements the rules of the Game of Life, producing a dynamic simulation of generations of cells. The simulation can end automatically or be stopped manually by the user.

## 🤝 Contributions

Contributions are welcome! If you find a bug or want to suggest improvements, feel free to open issues or submit pull requests.

## 📄 License

This project is licensed under the MIT License — see the [LICENSE](LICENSE) file for details.

## 📫 Contact

For questions or suggestions, contact:

- **Email:** arthurbretas1@gmail.com
- **LinkedIn:** [My LinkedIn](https://www.linkedin.com/in/arthur-bretas-b2a6a82b9/)
- **GitHub:** [My GitHub](https://github.com/BretasArthur1)
