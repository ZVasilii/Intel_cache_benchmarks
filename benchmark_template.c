#define SIZE 128    // can be cahnged
#define STEP 1      // can be changed
#define REPEATS 100 // fixed value


int main() {
    // Ask the compiler to put the loop iterators in registers,
    // otherwise it will add additional memory accesses:
    register int i, j;

    // Allocate memory - an array of "long long"s (64 bits each):
    long long a[SIZE];

    for (i = 0; i < REPEATS; i++)
        // Iterating through the array:
        for (j = 0; j < SIZE; j += STEP)
            a[j] = i + j; // access memory at the address a+j
}


void _start() { // the program will begin from the "_start" label
    main(); // the main algorithm

    // Have to exit manually, if no stdlib is linked:
    asm(
        "mov $60, %rax;"
        "mov $0, %rbx;"
        "syscall"
    );
}

