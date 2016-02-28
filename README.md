# ArdillasyBits-Algoritmia
It's a project of the course of Algoritmia in the PUCP university.
##### How to compile this program?
We open the linux terminal and type this lines
```sh
     $ gcc main.c
     $./a.out
```
We use two different algorithms:
  - Bubble Sort
```pseudo
    for i := 0 to n-2 do begin
        for j := 0 to n-i-2 do begin
            if (A[j] > A[j+1]) then
                swap(A[j], A[j+1]])
        end
    end
```
- Shell Sort
```pseudo
    inc = n/2
    
    while (inc > 0) do begin
        for i := inc to n-2 do begin
            temp = A[i]
            j = i
            while (j >= i) and (A[j-inc] > temp) do begin
                A[j] = A[j-inc]
                j = j - inc
            end
            A[j] = temp
        end
        inc = inc/2
    end
```
