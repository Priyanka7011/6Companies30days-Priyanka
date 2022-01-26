def minSwaps(self, grid: List[List[int]]) -> int:
        n = len(grid)
        arr = []
        S = set()
        for row in grid:
            c = 0
            for i in row[::-1]:
                if i:
                    break
                c += 1
            while c in S:
                c -= 1
            if c >= 0:
                S.add(c)
                arr += c,
            
        if len(arr) < n:
            return -1
        
        res = 0
        for i, v in enumerate(arr):
            for v2 in arr[i+1:]:
                if v2 > v:
                    res += 1
        return res

""""
from first rorw to last, count number of trailing zeroes. Record only the highest number not shown yet. For example, at row 0, trailing zeroes = 10, set it to 10. Row 1, trailing zeroes = 10 as well, because 10 already shown, set it to 9. One row to be 10 is ALREADY enough. (This will be explained later).

When all number is recorded, this creates an array with unique integers. If array size is less than n, in other words, array is not 0, 1, 2, ..., n-1, then it's impossible to form a VALID matrix.

If array size is n, we now calculate min adjacent swaps to sort the array. Notice for a correct swap of adjacent number i, j (i < j) to j, i, it reduces total number of inversion of the array by exactly 1. This means for a sorted array of inversion = 0, minimum number of swaps needed is exactly number of inversions. So we just calculate inversions.

Now why we need to record highest different trailing zeroes? To avoid ambiguity for counting inversions. For an counter-example, for array a1, a2, ..., a10, if a1 = 8, a2=9, a3=9, we only need to count a2 as an inversion, because a3 only needs 7 zeroes and stay at row 2 and matrix is still valid. Why take higest different trailing zeroes starting from first row? It creates an array that needs minimum adacent swaps.
"""