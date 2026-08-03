male(john).
male(paul).
male(mike).
male(david).
female(mary).
female(susan).
female(lisa).
female(emma).
father(john, paul).
father(john, susan).
father(paul, mike).
father(paul, lisa).
father(mike, emma).
mother(mary, paul).
mother(mary, susan).
mother(susan, mike).
mother(susan, lisa).
mother(lisa, emma).



parent(X, Y) :- father(X, Y).
parent(X, Y) :- mother(X, Y).
grandparent(X, Y) :- parent(X, Z), parent(Z, Y).
sibling(X, Y) :- parent(Z, X), parent(Z, Y), X \= Y.
brother(X, Y) :- sibling(X, Y), male(X).
sister(X, Y) :- sibling(X, Y), female(X).
ancestor(X, Y) :- parent(X, Y).
ancestor(X, Y) :- parent(X, Z), ancestor(Z, Y).