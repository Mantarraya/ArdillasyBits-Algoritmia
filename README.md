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
    procedure Bubble_Sort(A[], n)
    
        for i := 0 to n-2 do begin
            for j := 0 to n-i-2 do begin
                if (A[j] > A[j+1]) then
                    swap(A[j], A[j+1]])
            end
        end
        
    end procedure
```
- Shell Sort
```pseudo
    procedure Shell_Sort(A[], n)
    
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
        
    end procedure
```
And a search algorithm:
- Ternary Search
```pseudo
    function Ternary_Search(A[], ini, fin, k)
    
        if (ini > fin) then
            return -1
            
        terc = (fin - ini + 1)/3
        
        if (A[ini+terc] == k) then
            return ini+terc
        else if (A[fin-terc] == k) then
            return fin-terc
            
        if (A[ini+terc] > k) then
            return Ternary_Search(A, ini, ini+terc-1, k)
        else if (A[fin-terc] > k) then
            return Ternary_Search(A, ini+terc+1, fin-terc-1, k)
        else
            return Ternary_Search(A, fin-terc+1, fin, k)
            
    end function
```
