# Mini Expression Evaluator (C++)

A stack-based arithmetic expression evaluator implemented in C++.  
This project demonstrates parsing, evaluation logic, and basic compiler-inspired processing of expressions.

---

## Features
- Supports arithmetic operations: `+`, `-`, `*`, `/`
- Handles nested parentheses
- Maintains correct operator precedence
- Accepts dynamic user input
- Robust error handling for invalid expressions

---

## Core Concepts
- Stack Data Structure (for values and operators)
- Expression Parsing
- Operator Precedence Handling
- Basic Compiler Front-End Concepts (token processing and evaluation)

---

## How It Works
The evaluator processes the input expression using two stacks:

- **Values Stack** → stores numeric operands  
- **Operators Stack** → stores operators and parentheses  

### Execution Flow:
1. Parse input character by character  
2. Push numbers into the values stack  
3. Push operators into the operator stack based on precedence  
4. Apply operations when required  
5. Resolve parentheses by evaluating sub-expressions  

This ensures correct evaluation order and mimics a simplified parsing mechanism.

---

## Error Handling
- Detects invalid characters in input
- Ensures balanced parentheses
- Handles division by zero using exception handling
- Prevents invalid execution states

---

## Example

**Input:**
3 + 5 * (2 + 1)

**Output:**
18

---

## Future Improvements
- Support for floating-point expressions
- Unary operator handling (e.g., `-5`)
- Enhanced error reporting
- Conversion to postfix (Reverse Polish Notation)
