# Number Guessing Game CLI

A cross-platform number guessing game written in pure **C**, as part of the **[Roadmap.sh Challenge](https://roadmap.sh/projects/number-guessing-game)**.
Includes difficulty level, input validation, modular structure, and a final hint mechanic.

## 📦 Features

- Difficulty levels: Easy, Medium, Hard
- Cross-platform random number generation
- Safe user input handling (no crashes or infinite loops)
- Smart Hints:
  - Tells if the target number is higher or lower than the last guess
  - On your last chance, tells if the number is **even or odd**

## 🛠️ How to Run the Project

### Prerequisites

- For compile:
  - Linux: **GCC** (*GNU Compiler Collection*)
  - Windows: **MSVC** (via *Developer Command Prompt for VS*)
- To run:
  - Any terminal (Bash, CMD, or PowerShell)

### Steps to Execute

1. Clone the repository:
   ```bash
   git clone https://github.com/jmsmarcelo/number-guessing-game-c.git
   cd number-guessing-game-c
   ```
2. Compile the project:
   ```bash
   mkdir build
   cd build

   # Linux:
   gcc -o number-guessing-game ../src/*.c

   # Windows (MSVC):
   cl /Fe:number-guessing-game ..\src\*.c
   ```
3. Run the application:
   ```bash
   ./number-guessing-game # Linux

   .\number-guessing-game # Windows
   ```

## 📖 How to Contribute

Contributions are welcome!

### To contribute

1. Fork the repository.

2. Create a new branch:
   ```bash
   git checkout -b my-new-feature
   ```

3. Commit your changes:
   ```bash
   git commit -m "add new feature"
   ```

4. Push to the branch:
   ```bash
   git push origin my-new-feature
   ```

5. Open a Pull Request.

## 🖼️ Screenshots

![Screenshot from 2025-07-06 23-48-16](https://github.com/user-attachments/assets/8fd39b87-5bf0-439f-82bc-189ffd9ad115)

## 📜 License

This project is licensed under the **MIT License**.
See the **[LICENSE](https://github.com/jmsmarcelo/number-guessing-game-c/blob/main/LICENSE)** file for details.

## 🧠 About the Project

This project was created by **[Jose Marcelo](https://jmsmarcelo.github.io)** as a personal learning challenge, focused on:
- Modular C programming
- Cross-platform development
- Safer input handling
