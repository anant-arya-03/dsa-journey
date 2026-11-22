# C++ Memory Alignment and Structure Padding

## 1. Bits, bytes and data types
A bit holds 0 or 1. A byte is commonly 8 bits (the C++ standard permits other byte widths). `sizeof` reports bytes. Common sizes: `char` 1 byte, `int` 4 bytes, `float` 4 bytes, `double` 8 bytes. Check on your system.

## 2. Size vs alignment
**Size** means bytes occupied; **alignment** restricts where a variable may start. On many systems, `int` has size 4 and alignment 4: its offset must be divisible by 4. `alignof(T)` reports alignment. Size and alignment are not always equal.

## 3. Why `char + int + char` can use 12 bytes
```cpp
struct Example {
    char c; // 1 byte
    int a;  // commonly 4 bytes, alignment 4
    char d; // 1 byte
};
```
Without padding, the fields total 1 + 4 + 1 = 6 bytes. But alignment adds gaps:

```text
Byte offset:  00 01 02 03 | 04 05 06 07 | 08 09 10 11
Contents:     c  P  P  P |  a  a  a  a |  d  P  P  P
```
`P` = padding byte.
1. `c` occupies offset 0.
2. `a` needs to start at a multiple of 4, so offsets 1, 2, 3 are padding.
3. `a` occupies offsets 4 through 7.
4. `d` occupies offset 8.
5. The occupied length is now 9 bytes. The structure alignment is typically 4, so the total size rounds **up** to 12; offsets 9–11 are tail padding.

**Total: 1 + 3 + 4 + 1 + 3 = 12 bytes.** Offsets 0 through 11 are 12 locations, because counting starts at 0. Offset 12 begins the next element in an array.

## 4. The next-multiple rule
After correctly aligning *each* member, round the final occupied length up to a multiple of the structure's alignment. For alignment 4:

| Occupied bytes | Final bytes |
|---:|---:|
| 9 | 12 |
| 12 | 12 |
| 13 | 16 |
| 17 | 20 |

The rule concerns **alignment**, not necessarily the size of the biggest data type. Never round down.

## 5. Changing the order
```cpp
struct A { char c; int a; char d; }; // typically 12 bytes
struct B { char c; char d; int a; }; // typically 8 bytes
```

```text
B offsets:  00 01 02 03 | 04 05 06 07
B contents: c  d  P  P |  a  a  a  a
```
Member order can reduce padding. Avoid reordering when external binary formats or interfaces depend on layout.

## 6. Check using C++
```cpp
#include <iostream>
#include <cstddef>
using namespace std;

struct Example { char c; int a; char d; };
struct Reordered { char c; char d; int a; };

int main() {
    cout << "sizeof(char): " << sizeof(char) << '\n';
    cout << "sizeof(int): " << sizeof(int) << '\n';
    cout << "alignof(int): " << alignof(int) << '\n';
    cout << "sizeof(Example): " << sizeof(Example) << '\n';
    cout << "alignof(Example): " << alignof(Example) << '\n';
    cout << "Offsets: " << offsetof(Example, c) << ' '
         << offsetof(Example, a) << ' ' << offsetof(Example, d) << '\n';
    cout << "sizeof(Reordered): " << sizeof(Reordered) << '\n';
}
```

## 7. Practice questions with answers
1. **What is a bit?** A binary digit (0 or 1).
2. **How many bits are in a byte?** Usually 8; C++ allows other byte widths.
3. **What does `sizeof` measure?** C++ bytes.
4. **Typical `char` size?** 1 byte.
5. **Typical `int` size?** 4 bytes.
6. **What is alignment?** A restriction on an object's starting address.
7. **Where can an int with alignment 4 start?** Offsets 0, 4, 8, 12, etc. relative to an aligned base.
8. **Why padding at offsets 1–3?** To start the int at offset 4.
9. **Why four boxes for the int?** It occupies 4 bytes on the assumed system.
10. **Where does the last char go?** Offset 8.
11. **Why is the structure 12 rather than 9 bytes?** Tail padding makes the total a multiple of alignment 4.
12. **Why is the last offset 11 instead of 12?** Twelve bytes are numbered 0 through 11.
13. **Round occupied length 13 up with alignment 4.** 16 bytes.
14. **Round occupied length 12 up with alignment 4.** 12 bytes.
15. **Typical size of `{char a; char b; int c;}`?** 8 bytes.
16. **Typical size of `{int a; char b; char c;}`?** 8 bytes.
17. **Typical size of `{char a; double b; char c;}` with double size/alignment 8?** 24 bytes.
18. **Can reordering fields save space?** Yes, it can reduce padding.
19. **What is internal padding?** Unused bytes between members.
20. **What is tail padding?** Unused bytes at the end of the structure.
21. **Is largest member size always equal to structure alignment?** No. Check `alignof`.
22. **Why is tail padding useful in arrays?** It helps ensure each next structure starts at an aligned address.

## Exam shortcut
Write each member's size and alignment; place it at the next valid aligned offset; add its size; then round the final occupied length up to a multiple of the structure's alignment. Exact layouts can vary by compiler and platform.
