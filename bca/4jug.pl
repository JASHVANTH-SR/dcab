% Define the initial state of the jugs
initial_state(0,0).

% Define the goal state of the jugs
goal_state(2,_).

% Define the actions that can be taken on the jugs
action(fill(4), state(_,B), state(4,B)).
action(fill(3), state(A,_), state(A,3)).
action(empty(4), state(_,B), state(0,B)).
action(empty(3), state(A,_), state(A,0)).
action(pour(4,3), state(A,B), state(NewA,NewB)) :-
    Diff is min(A, 3 - B),
    NewA is A - Diff,
    NewB is B + Diff.
action(pour(3,4), state(A,B), state(NewA,NewB)) :-
    Diff is min(B, 4 - A),
    NewA is A + Diff,
    NewB is B - Diff.

% Define the path from the initial state to the goal state
path(State, _, []) :- goal_state(State,_).
path(State, Visited, [Action|Rest]) :-
    action(Action, State, NextState),
    \+ member(NextState, Visited),
    path(NextState, [NextState|Visited], Rest).

% Define the solve predicate to find a solution to the problem
solve(Solution) :-
    initial_state(A,B),
    path(state(A,B), [state(A,B)], Solution).
