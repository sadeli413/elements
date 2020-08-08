# elements

Finds all english words that can be spelled with symbols from the periodic table, with atomic numbers 1 - 118.

---

The english words are inside alpha.txt, and the elements are inside elements.txt

---
The checkWord algorithm checks a single word if it can be spelled entirely and solely from periodic table symbols
1. It creates an Array of Flags to keep track of which elements the word can be spelled from.
2. It checks a substring of either one character (single) or two characters (double).
    - If the substring matches a periodic table symbol, then add that element to the Flags Array. Check the next single.
    - If the single substring does NOT match, then check it as a double.
    - If the double substring does NOT match, then pop the Flags Array until you find a single. Pop that single, and begin checking at that point again, but as a double.
    - When the Flags Array is completely empty, that means the word cannot be spelled entirely by periodic table symbols, and return false
    - If you have completed checking the full word, and there are items in the Flags Array, return true. The Flags Array contains the elements that spell the word.

---
There are four main classes: Table, Element, Flag, and Array. 
- A Table has two arrays of Elements from 1 - 118. One array is sorted by atomic number, and the other is sorted by symbol in alphabetical order.
- An Element has an atomic number, a symbol, and a full name.
- A Flag has an Element, an index of a word, and a boolean if the Element symbol has one or two characters.
- An Array has a pointer and a size. You can add, remove, pop, peek, get, etc.