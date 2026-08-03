go :-
    write('Enter first number: '), nl,
    read(X),
    write('Enter second number: '), nl,
    read(Y),
    write('Enter third number: '), nl,
    read(Z),
    max_of_three(X, Y, Z).

max_of_three(X, Y, Z) :-
    Max is max(X, max(Y, Z)),
    write('The largest number is: '), write(Max).
