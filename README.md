# Mini Expression Evaluator (C++)

This project implements a stack-based arithmetic expression evaluator in C++.

## Features
- Supports basic operations: +, -, *, /
- Handles parentheses correctly
- Maintains operator precedence
- Accepts dynamic user input

## Concepts Used
- Stack Data Structure
- Expression Parsing
- Operator Precedence Handling
- Basic Compiler Front-End Concepts

## How it Works
The program parses the input expression and evaluates it using two stacks:
- One for values
- One for operators

It ensures correct order of execution based on precedence and parentheses.

## Example
Input:
3 + 5 * (2 + 1)

Output:
18

## Future Improvements
- Support for variables
- Error handling for invalid expressions
- Floating-point operations
