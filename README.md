rpned is a Reverse-Polish Notation calculator inspired by "ed" and written in C.

Current Operations:
+,
-,
*,
/,
sin,
cos,
tan,
asin,
acos,
atan
dtr (Degrees to radians),
rtd (Radians to degrees),
sqrt,
nrt (Nth root),


Current Commands:
:q (Quit the program),
:f (Flush the stack),
:d (Pop (drop the highest item of) the stack),
:s (Print out the stack state)

Also when writing a command you can write the number of times
the command will be executed.
Example: ":4d" will pop out the stack 4 times.




Example of usage:
`
$ rpned
>> 10
>> 15
>> :s
|-----------STACK-----------|
15.000000
10.000000
0.000000
|-----------STACK-----------|
>> +
>> :s
|-----------STACK-----------|
25.000000
0.000000
|-----------STACK-----------|
>> 100
>> 90
>> :s
|-----------STACK-----------|
90.000000
100.000000
25.000000
0.000000
|-----------STACK-----------|
>> dtr
>> :s
|-----------STACK-----------|
1.570796
100.000000
25.000000
0.000000
|-----------STACK-----------|
>> cos
>> :s
|-----------STACK-----------|
0.000000
100.000000
25.000000
0.000000
|-----------STACK-----------|
>> :2d
>> :s
|-----------STACK-----------|
25.000000
0.000000
|-----------STACK-----------|
>> :f
>> :s
|-----------STACK-----------|
0.000000
|-----------STACK-----------|
>> :q
$
`


