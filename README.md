# nfa2dfa
I've been learning automata and compiler theory for a while, so I decided to write this shit for my personal study.

What's done:
* FSA (abstract, base class)
* NFA (concrete, derived from FSA)
* DFA (concrete, derived from NFA)
* Print transition table (NFA/DFA)
* NFA -> DFA (epsilon/lambda move isn't implemented yet)

```
	0	1
----------------------
>1	1 2 	1
 2	3 	3
 3	4 	4
 [4]	-	-

	0	1
----------------------
>1	12 	1
 12	123 	13
 13	124 	14
 [14]	12 	1
 123	1234 	134
 [124]	123 	13
 [134]	124 	14
 [1234]	1234 	134
 ```
