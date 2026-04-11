	# CSE3150 Homework 3: Arrays, Pointers, and Exceptions

## Implementation Details

### Pointers and nullptr
I used pointers in two primary ways for this assignment. First, the `names` array is a pointer-to-pointers (`char**`), allowing for a dynamic list of C-strings. Second, the `updateGPA` function accepts a `double*` to modify the student's GPA directly in memory. [cite_start]I initialized pointers and checked for validity using the `nullptr` keyword to ensure safety before dereferencing.

### Const and References
To optimize performance and prevent accidental data modification, I used `const` and references in my function signatures. For example, `printStudent` uses a `const char*` for the name and a `const double&` for the GPA. [cite_start]This passes the data by reference (saving memory) while guaranteeing the function cannot change the original values.

### Type Casting
In the `averageGPA` logic within `main`, I used `static_cast<int>` to convert the calculated double value of the average GPA into a rounded integer for display, as required by the specifications.

### Exceptions
I implemented error handling using `try-catch` blocks. The program throws exceptions as `const char*` strings if the user tries to add a student when the array is at full capacity, or if they attempt to calculate an average when the list is empty.

### Control Flow
The program uses a `do-while` loop to keep the menu active until the user chooses to quit. Inside the loop, a `switch` statement handles the different menu options, ensuring clean and organized logic for each mode.
