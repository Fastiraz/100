# 100.cpp

The following C++ code generates combinations of characters from different character sets based on the command-line arguments provided. It is designed for hackers and password cracking purposes.

The solution is to use recursion on the given character array.
The idea is to pass all possible lengths and an empty string
initially to a helper function. In the helper function we keep
appending all the characters one by one to the current string
and recur to fill the remaining string till the desired length
is reached. It can be better visualized using the below recursion tree:

```txt
     (a, b)
      /   \
     a     b
    / \   / \
   aa ab ba bb
```

## **Algorithm**

1. Initialize an empty list `passwords`.
2. For `i` in range(1, length+1):
    a. Generate all possible combinations of length `i` of the characters in `arr` using the `itertools.product()` method.
    b. Convert each combination to a string using the `join()` method.
    c. Add these strings to the `passwords` list using the `extend()` method.
3. Return the `passwords` list.

## **Usage**

The program accepts the following command-line arguments:

- `-l` or `--lowercase` to include lowercase letters
- `-u` or `--uppercase` to include uppercase letters
- `-n` or `--numbers` to include numbers
- `-s` or `--special` to include special characters
- `-j` or `--japanese` to include Japanese characters
- `-r` or `--russian` to include Russian characters
- `-c` or `--chinese` to include Chinese characters
- `-a` or `--arabic` to include Arabic characters
- `-k` or `--korean` to include Korean characters
- `-h` or `--hindi` to include Hindi characters

You can mix and match these options to create the desired character set for generating the combinations.

To execute the program, compile and run the code in a C++ compiler with the desired command-line arguments.

## **Example**

Here's an example command to run the program with lowercase letters and numbers:

```bash
g++ -o 100 100.cpp  # Compile the program
./100 -l -u -n -s   # Use the program
```

This will generate combinations using lowercase letters and numbers.

Execution Time
The program also measures the execution time and displays it at the end.

> Note: This program is designed for hackers and password cracking purposes. Please ensure you have proper authorization and legal rights before using it.

Feel free to modify the code or adjust the command-line arguments to suit your requirements.