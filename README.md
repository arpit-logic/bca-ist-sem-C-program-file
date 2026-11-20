# Longest Common Prefix

A C program that finds the longest common prefix among a list of strings entered
by the user.

## Features

- Accepts between 0 and 100 strings
- Stores strings up to 255 characters each
- Handles empty input lists and strings with no common prefix
- Returns the prefix with a null terminator
- Frees dynamically allocated memory

## Requirements

- A C compiler such as GCC

## Compile and Run

```sh
gcc longestcommonprefix.c -o longestcommonprefix
```

On Windows, run:

```sh
longestcommonprefix.exe
```

On Linux or macOS, run:

```sh
./longestcommonprefix
```

## Example

```text
Enter number of strings (0-100): 3
Enter 3 strings: flower flow flight
Longest common prefix: "fl"
```

If the strings have no shared beginning, the program prints an empty prefix:

```text
Longest common prefix: ""
```

## How It Works

The program starts with the first string as the initial prefix. It compares each
following string with the prefix, character by character, and reduces the prefix
length whenever characters differ or one string ends. The resulting prefix is
copied into a dynamically allocated buffer and printed before it is freed.

Time complexity is `O(S)`, where `S` is the total length of the strings compared,
and the auxiliary space complexity is `O(L)`, where `L` is the length of the
returned prefix.
