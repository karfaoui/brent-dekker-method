# brent-dekker-method
### Brent's method root-finding algorithm (minimization without derivatives)
Brent’s method [1], which is due to Richard Brent [2] approximately solving f(x) = 0, where f is a continous function: R → R. 
This algorithm is an extension of an earlier one by Theodorus Dekker [3]  (this algorithm is also called the brent-dekker-method). Why is this useful? There are two basic reasons:

1. Root-finding algorithms allow solving any equation defined by continuous functions. Solving an equation f(x) = g(x) can be rewritten as a root finding problem h(x) = 0 where h(x) = f(x) - g(x).

2. In general, the roots of a function cannot be computed exactly. In some special cases, a closed formulation can be derived, which allows finding function roots (the last example below, roots can be determined by a closed form).

### C++ implementation

An implementation of Brent's method in C++ is illustrated here. We show the inner workings, in code, of this method with three examples of root-finding.

<b>Example 1</b>:<br/> <i>f(x) = sin ( x ) - x / 2</i>
 
![Example 1](/images/example_1.png "f(x) = sin ( x ) - x / 2")<br>

<b>Example 2</b>:<br/> <i>f(x) = 2 * x - exp ( -x )</i>
 
![Example 2](/images/example_2.png "f(x) = 2 * x - exp ( -x )")<br>

<b>Example 3</b>:<br/> <i>f(x) = x <sup>4</sup> + x <sup>3</sup> - 5 * X <sup>2</sup> + 3</i>
 
![Example 3](/images/example_3.png "f(x) = x <sup>4</sup> + x <sup>3</sup> - 5 * X <sup>2</sup> + 3")<br>


### References

1. Brent (1973) published an Algol 60 implementation.
2. Brent, R. P. (1973), "Chapter 4: An Algorithm with Guaranteed Convergence for Finding a Zero of a Function", Algorithms for Minimization without Derivatives, Englewood Cliffs, NJ: Prentice-Hall, ISBN 0-13-022335-2
3. Dekker, T. J. (1969), "Finding a zero by means of successive linear interpolation", in Dejon, B.; Henrici, P., Constructive Aspects of the Fundamental Theorem of Algebra, London: Wiley-Interscience, ISBN 978-0-471-20300-1

