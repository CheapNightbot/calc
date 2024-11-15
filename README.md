# Cheap Calculator ~

A simple and stumid command-line calculator to perform basic arithmetic operations such as addition, subtraction, multiplication, and division. ♡(>ᴗ•)

<div align="center">
    
![Demo](https://github.com/user-attachments/assets/af7e817b-17a1-4c19-9dcb-cded4ba714cb)

</div>

<details>
    <summary>TABLE OF CONTENTS</summary>

- [Features](#features)
- [Installation](#installation)
    - [Cleaning Up](#cleaning-up)
- [Usage](#usage)
    - [Commands](#commands)
    - [Example](#example)
- [Contributing](#contributing)
- [License](#license)

</details>

## Features

- Supports the following basic operations:
    - `+`: Addition
    - `-`: Subtraction
    - `*`: Multiplication
    - `/`: Division
    - `//`: Integer division (round to nearest integer)
- Colorful output.
- Python REPL inspired prompt and feel.

## Installation

> [!NOTE]
> This project uses `gcc` & `make` for building. Ensure you have them installed on your system.

1. Clone this repository:

    ```bash
    git clone https://github.com/CheapNightbot/calc.git
    ```

2. Navigate into the project directory:

    ```bash
    cd calc
    ```

3. Build the project:

    ```bash
    make
    ```

    OR

    ```bash
    make calc
    ```

4. Run the calculator:

    ```bash
    ./build/calc
    ```

### Cleaning Up:

> [!WARNING]
> "This will delete the 'build' directory and the executable!"

To clean up the build files:

```bash
make clean
```

## Usage

### Commands:

- `clear` or `clean`: Clears the terminal screen.
- `exit` or `quit`: Exits the calculator.
- `help`: Displays the help/usage message.

### Example:

```bash
>>> 3 + 4
7
>>> 10 - 4
6
>>> 5 * 5
25
>>> 7 / 3
2.33
>>> 7 // 3
2
```

## Contributing

If you want to contribute, feel free to fork this repository, make your changes, and submit a pull request.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
