# 42_ft_containers

## Summary:
The STL standard C++ containers have all a specific usage.
To make sure you understand them, let’s re-implement them!

### How to clone and build

1. Clone the repo
   ```sh
   git clone https://github.com/tomkrueger42/42_ft_containers.git
   ```
2. Compile the code
   ```sh
   make
   ```

Make will compile the code into two binaries, 'ft_containers' and 'std_containers', each using their respective namespace.
These binaries consist of the functions testing the underlying data structures.

3. To compare the output of 'ft_containers' and 'std_containers', run
   ```sh
   ./run_test.sh
   ```

This script executes both binaries and stores their outputs in out.<binary_filename>, respectively. Also a diff of both files is stored in out.std_ft.diff to track the differences of both outputs. For a quick overview, the diff is also printed into the terminal.

##### Also, the runtime of each test will be printed to the console. This is to compare the performance between the ft_containers and std_containers!


To clean the directory, just use
   ```sh
   make clean
   ```
   or
   ```sh
   make fclean
   ```
