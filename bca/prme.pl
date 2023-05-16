is_prime(N) :-
    N > 1,
    \+ divisible(N, 2).

divisible(N, X) :-
    N mod X =:= 0.
divisible(N, X) :-
    X * X < N,
    X2 is X + 1,
    divisible(N, X2).
