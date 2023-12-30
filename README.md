# Push_swap

Push Swap is a sorting algorithm project in the 42 Cursus. The objective is to sort a stack of integers using a limited set of instructions. The algorithm is based on finding the Longest Increasing Subsequence (LIS) within the initial stack and efficiently rearranging the elements.

### Algorithm Steps:
1. **Find the Longest Increasing Subsequence (LIS):**
- Identify the smallest value in Stack A.
- Determine the Longest Increasing Subsequence starting from the smallest value.
2. **Move LIS to Stack A:**
- Transfer all elements not in the LIS to Stack B, leaving only the LIS in Stack A.
3. **Calculate Moves for Each Element:**
- Iterate through Stack B and record the number of moves required for each element to reach its correct position in Stack A.
4. **Reorder Stack A:**
- Push the element requiring the fewest moves (cheapest element) to its appropriate position in Stack A.
- Repeat until Stack B is empty.
5. **Final Step:**
- Move the smallest element to the top of Stack A to complete the sorting process.
