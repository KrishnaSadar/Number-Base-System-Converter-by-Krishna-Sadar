# Number Base System Converter by Krishna Sadar

## Project Overview

The **Number Base System Converter** is a robust web application designed to convert numbers between various base systems, ranging from binary to hexadecimal and even custom bases up to 36. This project demonstrates advanced algorithmic logic and an intuitive user interface, making it a valuable tool for developers, mathematicians, and students.
[Check out the live project](https://nbscconverterkrishnasadar.tiiny.site/)

## Key Features

- **Base Conversion**: Supports conversion between decimal, binary, octal, hexadecimal, and custom bases up to base 36.
- **Fractional Number Handling**: Capable of converting both integer and fractional parts of numbers.
- **User-Friendly Interface**: Intuitive input fields and a clean, responsive design.
- **Social Media Links**: Quick access to LinkedIn, Instagram, and GitHub profiles.

## Algorithms and Logic

1. **Character to Integer Conversion**:
   - **Function**: `toInteger(char c)`
   - **Logic**: Converts alphanumeric characters to their respective integer values, handling digits ('0'-'9'), uppercase letters ('A'-'Z'), and lowercase letters ('a'-'z').

2. **Integer to Character Conversion**:
   - **Function**: `toCharacter(int n)`
   - **Logic**: Converts integer values back to their respective alphanumeric characters, facilitating base conversions.

3. **Validity Check**:
   - **Functions**: `Valid(const char* number, int base)` and `ValidFractional(const char* number, int base)`
   - **Logic**: Ensures that the input number conforms to the specified base, allowing for robust error handling and user feedback.

4. **Integer Conversion**:
   - **Function**: `cTod(char* number, int base)`
   - **Logic**: Converts the integer part of a number from any base to a decimal (base 10) value using positional value calculation.

5. **Fractional Conversion**:
   - **Functions**: `cTodF(char* number, int base)` and `convertFractionalPart(const char* number, int inputBase, int outputBase, char* result)`
   - **Logic**: Handles the conversion of the fractional part of numbers, ensuring accurate base-to-base conversion using positional values and iterative methods.

6. **Decimal to Target Base Conversion**:
   - **Function**: `cFromd(long long n, int base, char* result)`
   - **Logic**: Converts a decimal value to the desired target base, assembling the final converted number string.

## Technology Stack

- **Frontend**: HTML5, CSS3, JavaScript
- **Backend Algorithms**: Implemented in C and translated into JavaScript for web use.
- **UI/UX**: Responsive design with improved accessibility and ease of use.

## Project Motivation

The motivation behind creating the Number Base System Converter was to develop a comprehensive tool that combines complex numerical algorithms with a user-friendly interface. The project showcases the application of mathematical principles in a practical, web-based solution.

## Challenges Overcome

- Ensuring accurate conversion of both integer and fractional numbers between any two bases.
- Designing an interface that is both functional and aesthetically pleasing.
- Handling edge cases and validating user input to prevent errors.

## Learnings and Impact

Through this project, I have deepened my understanding of numerical systems and honed my skills in algorithm design and web development. The Number Base System Converter serves as a testament to my ability to tackle complex problems and create solutions that are both effective and user-centric.

## How to Use

1. **Clone the repository**:
   ```bash
   git clone https://github.com/yourprofile/number-base-system-converter.git
   cd number-base-system-converter
