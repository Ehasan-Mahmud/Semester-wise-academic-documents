go :-
    write('Enter first number: '), nl,
    read(X),
    write('Enter second number: '), nl,
    read(Y),
    sum(X, Y).

sum(X, Y) :-
    S is X + Y,
    write('Sum = '), nl,
    write(S), nl.
