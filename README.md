# 42_ft_containers

## Summary:

The STL standard C++ containers have all a specific usage.
To make sure I understand them, I re-implemented them!

This repository contains one of my projects of the core curriculum at [42 Heilbronn].

The project ft_containers is about some of the container class templates from the C++ standard template library (STL).
As with all C++ projects at 42 Heilbronn, the code has to be written according to the C++98 standard.

## Description

The task in this project is to reimplement some of the [container] types from the C++ STL:

- [`vector`]
- [`map`]
- [`stack`]
- [`set`] _(bonus)_

Further, some additional features are required:
- [`iterator_traits`]
- [`reverse_iterator`]
- [`enable_if`]
- [`is_integral`]
- [`equal`]
- [`lexicographical_compare`]
- [`pair`]
- [`make_pair`]

The structure of each standard container has to be taken as reference.
As the solution has to comply with the C++98 standard, every C++98 feature (even deprecated ones) is expected.
Any later feature of the containers must not be implemented.
If the container has an iterator system, then this has to be implemented as well.

Apart from implementing `set`, the bonus part is to use a [red-black tree] as internal data structure for `map` and `set`.

## Approach

My general approach was to follow the original implementation rather closely, so I read a lot of source code of the STL.
A good overview over the required member functions, their actions, and parameters was provided by [cplusplus.com].

I decided to implement a red-black tree for `map` and `set`.

## Testing

To check that my own containers (namespace `ft`) work as the original ones (namespace `std`), some tests are included.

The [Makefile] rule `all` compiles my [tests] into two binaries, `ft` and `std`, using the containers from the respective namespace.
Running them shows the test output, including the time from a small benchmark.

A small script [run_test.sh] is also included.
It automates the comparison between the `ft` and the `std` containers and saves the result in a file `result.diff`.
Ideally, this file should only contain the benchmark times.

Apart from my own tests, I used the following testers:
- [Mikastiv/ft_containers-terminator]
- [mli42/containers_test]

## How to clone and build

1. Clone the repo
   ```sh
   git clone https://github.com/tomkrueger42/42_ft_containers.git
   ```
2. Compile the code, note that the makefile and dependencies are currently only tested on macOS!
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


## Resources

#### C++ STL

- [CPP Reference]
- [cplusplus.com]
- [GNU Compiler Collection]
- [LLVM Compiler Infrastructure]

[42 Heilbronn]: https://www.42heilbronn.de/learncoderepeat

[container]: https://en.cppreference.com/w/cpp/container
[`vector`]: https://cplusplus.com/reference/vector/vector/
[`map`]: https://cplusplus.com/reference/map/map/
[`stack`]: https://cplusplus.com/reference/stack/stack/
[`set`]: https://cplusplus.com/reference/set/set/
[`iterator_traits`]: https://cplusplus.com/reference/iterator/iterator_traits/
[`reverse_iterator`]: https://cplusplus.com/reference/iterator/reverse_iterator/
[`enable_if`]: https://cplusplus.com/reference/type_traits/enable_if/
[`is_integral`]: https://cplusplus.com/reference/type_traits/is_integral/
[`equal`]: https://cplusplus.com/reference/algorithm/equal/
[`lexicographical_compare`]: https://cplusplus.com/reference/algorithm/lexicographical_compare/
[`pair`]: https://cplusplus.com/reference/utility/pair/
[`make_pair`]: https://cplusplus.com/reference/utility/make_pair/
[red-black tree]: https://en.wikipedia.org/wiki/Red-black_tree

[Makefile]: https://github.com/tomkrueger42/42_ft_containers/blob/main/Makefile
[tests]: https://github.com/tomkrueger42/42_ft_containers/blob/main/tests/src/main.cpp
[run_test.sh]: https://github.com/tomkrueger42/42_ft_containers/blob/main/run_test.sh
[Mikastiv/ft_containers-terminator]: https://github.com/Mikastiv/ft_containers-terminator
[mli42/containers_test]: https://github.com/mli42/containers_test

[CPP Reference]: https://en.cppreference.com/w/
[cplusplus.com]: https://cplusplus.com/reference/
[GNU Compiler Collection]: https://github.com/gcc-mirror/gcc/tree/master/libstdc++-v3/include/bits
[LLVM Compiler Infrastructure]: https://github.com/llvm-mirror/libcxx/tree/master/include
