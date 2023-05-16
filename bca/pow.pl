power(_, 0, 1).
power(X, N, Result) :-
    N > 0,
    N1 is N - 1,
    power(X, N1, TempResult),
    Result is X * TempResult.
