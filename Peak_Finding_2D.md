## 2D peak finding algorithm in O(n) worst case time

Link: [StackOverflow](https://stackoverflow.com/questions/23120300/2d-peak-finding-algorithm-in-on-worst-case-time)

A peak in a 2D array is a value such that all it's 4 neighbours are less than or equal to it, i.e. for
   
   `a[i][j] to be a local maximum`

   a[i+1][j] <= a[i][j]
   && a[i-1][j] <= a[i][j]
   && a[i][j+1] <= a[i][j]
   && a[i+1][j-1] <= a[i][j]

Now given an `NxN` 2D array, find a peak in the array.

### Algorithm

1. Let's assume that width of the array is bigger than height, otherwise we will split in another direction.
2. Split the array into three parts: central column, left side and right side.
3. Go through the central column and two neighbour columns and look for maximum.
     - If it's in the central column - this is our peak
     - If it's in the left side, run this algorithm on subarray `left_side + central_column`
     - If it's in the right side, run this algorithm on subarray `right_side + central_column`

### Why this works:

For cases where the maximum element is in the central column - obvious. 
If it's not, we can step from that maximum to increasing elements and will definitely not cross the central row, so a peak 
will definitely exist in the corresponding half.

### Why this is O(n):

Step #3 takes less than or equal to `max_dimension` iterations and `max_dimension` at least halves on every two algorithm steps. 
This gives `n+n/2+n/4+...` which is **O(n)**. 

**Important detail:** We split by the maximum direction. For square arrays this means that split directions will be alternating.
