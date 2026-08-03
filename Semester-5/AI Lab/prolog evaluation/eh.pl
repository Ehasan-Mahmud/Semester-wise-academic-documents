students(alice).
students(bob).
students(carol).
students(david).
courses(math).
courses(physics).
courses(ai).
courses(history).
teachers(smith).
teachers(jones).
teachers(brown).
teaches(smith, math).
teaches(smith, physics).
teaches(jones, ai).
teaches(brown, history).
enrolled(alice, math).
enrolled(alice, ai).
enrolled(bob, physics).
enrolled(bob, history).
enrolled(carol, math).
enrolled(carol, physics).
enrolled(david, ai).
enrolled(david, history).

mathphysics(X):- enrolled(X, math), enrolled(X, physics).
classmates(X, Y):- enrolled(X, Z), enrolled(Y, Z), X= alice, X\= Y.
difteaches(X):- teaches(X, Z), teaches(X, W), Z\=W.
findstudent(X):- enrolled(X, N), enrolled(X, M), N\=M.
taught(S, E):- enrolled(S, Y), teaches(E, Y), E= smith.
pairclassmates(X, Y):- enrolled(X, C), enrolled(Y, C), X\=Y.
stlist(T, S):- teaches(T, C), enrolled(S, C).


