# Computations Modulo P

Created: August 26, 2021 5:44 PM

## N! Factorial %MOD 10^P

print (n! % p)

![Untitled](Computations%20Modulo%20P%20a836ad44ac464450ae42cc10b5bc5aca/Untitled.png)

above is wrong

---

![Untitled](Computations%20Modulo%20P%20a836ad44ac464450ae42cc10b5bc5aca/Untitled%201.png)

this is correct

---

**What does this signifies?**

while calculating the value of a very large number which C++ cannot find, this will lead to obvious overflows.

1000! cannot be calculated and its full value cannot be printed, so what we are asked to do is print its %MOD which can be 10^p, Does that mean printing  **`answer%MOD`** as shown in the above diagram? The answer is ,no. Because even to just print the answer%MOD we have to calculate the answer which will eventually leads to overflow.

So, what should we do? Instead just printing the answer%MOD at-last we should utilise it inside the loop which will prevent the overflow.

**`answer = (answer*i)%MOD`**

**Example:** Take for example multiplying 2 numbers MOD 10

257 * 3716 = __________ _ ; this indirectly means that we just need to print the last digit of the result obtained as the answer.

So, instead of multiplying the numbers 257*3612, obtaining the result and then taking its MOD 10 to get the last digit, What we can do is just take the MOD 10 of a and MOD 10 of b and multiply them and output its MOD 10.

257 * 3716 = __________ 2

(257%10) * (3716%10) ⇒ 7*6 = 42 ⇒ 42%10 = 2 ans.

The first one will lead to overflow whereas the second one just does what we need without unnecessarily computing arithmetic operation on very big numbers.

![Untitled](Computations%20Modulo%20P%20a836ad44ac464450ae42cc10b5bc5aca/Untitled%202.png)

So,in the above image we actually don't need to compute the last MOD outside as it is already done in the for loop.

---

## AREA OF RECTANGLE

A,B ≤ $10^{18}$ 

**compute the area :** (A*B)%MOD (overflows)

**correct answer** : ((A%MOD)*(B%MOD))%MOD

![Untitled](Computations%20Modulo%20P%20a836ad44ac464450ae42cc10b5bc5aca/Untitled%203.png)

Addition and multiplication are straight forward and we can do them directly.

But Subtraction and division may require some extra attention to be given.

![Untitled](Computations%20Modulo%20P%20a836ad44ac464450ae42cc10b5bc5aca/Untitled%204.png)

![Untitled](Computations%20Modulo%20P%20a836ad44ac464450ae42cc10b5bc5aca/Untitled%205.png)

As it is clearly visible , we do get a negative value but the answer is not correct. To fix this ,we can:

![Untitled](Computations%20Modulo%20P%20a836ad44ac464450ae42cc10b5bc5aca/Untitled%206.png)

### DIVISION

we cannot calculate division straight forward, as we shown in the image below. The results show no sign of correctness.

![Untitled](Computations%20Modulo%20P%20a836ad44ac464450ae42cc10b5bc5aca/Untitled%207.png)

Here we are using the Eulers theorem :

![Untitled](Computations%20Modulo%20P%20a836ad44ac464450ae42cc10b5bc5aca/Untitled%208.png)

![Untitled](Computations%20Modulo%20P%20a836ad44ac464450ae42cc10b5bc5aca/Untitled%209.png)

![Untitled](Computations%20Modulo%20P%20a836ad44ac464450ae42cc10b5bc5aca/Untitled%2010.png)

---

## FAST MODULO ,FLOOR AND CEILING

So the built-in STL for handling these operations are present and comes handy when solving problems, But the are not fast.

![Untitled](Computations%20Modulo%20P%20a836ad44ac464450ae42cc10b5bc5aca/Untitled%2011.png)

The % is very very slow instead follow the second code that says:

```cpp
int answer = a+b;
if(answer >=MOD){
	answer-=MOD
```

---