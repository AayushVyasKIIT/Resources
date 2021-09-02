# Problem Constraint Analysis

Created: May 29, 2021 5:51 PM

This section discusses about how to analyse the constraints present in a given problem.

![Problem%20Constraint%20Analysis%204ab99d6f49594fe6994da4a136c63fde/Untitled.png](Problem%20Constraint%20Analysis%204ab99d6f49594fe6994da4a136c63fde/Untitled.png)

$1 sec = 10^8 operations$

$20 sec = 20*10^8 operations$

suppose for #test set 1 : 2≤N≤2000 if my T(n) = O(n^2) then: **O(2000^2) ≤ 20*10^8**

result : our code will run without any problem as constraint satisfied.

but if for #test set 2 : 2≤N≤2*10^5 and T(n) of our code is O(n^2) then :

**O(2*10^5^2) == O(2*10^10) > 20*10^8**

result: our code wont fit in these constraint and will crash. 

final result : we cannot use an algorithm with O(n^2)