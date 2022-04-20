# QLexer
lexical analysis, lexing or tokenization is the process of converting a sequence of characters.

https://en.wikipedia.org/wiki/Markdown
https://en.wikipedia.org/wiki/Lexical_analysis#Tokenization

Originally written by : https://github.com/pbek/qmarkdowntextedit subclassed as QPlainTextEdit widget.

This version uses a subclassed QTextEdit widget wich can insert pictures into the c, c++ source and header files.
Several options like "search and replace" is removed, but can be adapted again.


### The idea is to bring documentation straight into the source code. 
### To document complex code, pictures are really helpfull.

### Let's go for a ride and see if it works !

![main](https://user-images.githubusercontent.com/44880102/164116334-8c44b99e-7546-41cb-b58d-efc4d370863e.jpg)

![readme](https://user-images.githubusercontent.com/44880102/164114480-c4a909ec-5672-41ec-898b-ee799d59afa9.jpg)

An easy example is provided as QLexer widget.

![screen](https://user-images.githubusercontent.com/44880102/164114645-49fc5d5e-d6ce-44ed-9e23-4f51c51bbf05.jpg)

`~/documents/input.cpp` is a sample file to be processed by the TokenIzer.h file.

The tokenizer is basic and works ! Token output is below. The illegal character has to do with an empty line, this is ok for now.
This proves a integrated documenatation into the source files is not a problem at all. Who expected that?

I think the next example will be using a inline assembly like : https://www.codeproject.com/articles/15971/using-inline-assembly-in-c-c

Token output of file `~/documents/input.cpp`

```

``
`
cpp
#
include
<
iostream
>
Illegal character: -17Illegal character: -65Illegal character: -68int
main
(
)
{
bool
Ali88
=
true
;
int
_hiTa
=
1395
;
float
ehsan_vi
;
ehsan_vi
=
12
.
34
;
for
(
int
i
=
0
;
i
<
100
;
i
++
)
cout
<
<
"Hi"
<
<
A
[
i
]
;
switch
(
Ali88
)
{
case
true
:
cout
<
<
'Hita'
;
break
;
case
false
:
cout
<
<
"Hita"
;
break
;
default
:
signed
long
double
test_
;
test_
=
-
19
;
ehsan_vi
+
=
_hita
+
test
;
break
;
}
std
::
cout
<
<
"Give me the TokenIzer"
<
<
std
::
endl
;
return
0
;
}
``
`
