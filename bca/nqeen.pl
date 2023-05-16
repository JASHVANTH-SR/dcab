n_queens(N, Solution) :-
    length(Solution, N),
    Solution ins 1..N,
    safe_queens(Solution).

safe_queens([]).
safe_queens([Q|Queens]) :-
    safe_queens(Queens, Q, 1),
    safe_queens(Queens).

safe_queens([], _, _).
safe_queens([Q|Queens], Q0, D0) :-
    Q0 #\= Q,
    abs(Q0 - Q) #\= D0,
    D1 #= D0 + 1,
    safe_queens(Queens, Q0, D1).

