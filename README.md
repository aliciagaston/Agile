# Agile

HOw to compile :


Compiling the demo's can be done as follows:

gcc demo_rx.c rs232.c -Wall -Wextra -o2 -o test_rx

gcc demo_tx.c rs232.c -Wall -Wextra -o2 -o test_tx

Run the demo by typing:

./test_rx

or

./test_tx



To include this library into your project:

Put the two files rs232.h and rs232.c in your project/sourcedirectory.

Write #include "rs232.h" in your sourcefiles that needs access to the library.

Add the file rs232.c to your project settings (in order to get it compiled and linked with your program).

