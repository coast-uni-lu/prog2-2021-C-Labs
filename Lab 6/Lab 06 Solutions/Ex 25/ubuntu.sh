# Installation of Clang
sudo apt-get install clang

# Setup LLVM Symbolizer
sudo ln -s /usr/bin/llvm-symbolizer-3.8 /usr/bin/llvm-symbolizer
ASAN_SYMBOLIZER_PATH=/usr/bin/llvm-symbolizer

# Compile using Clang with adress sanitizing flag on
clang -O1 -g -fsanitize=address -fno-omit-frame-pointer main.c

# Execute
./a.out