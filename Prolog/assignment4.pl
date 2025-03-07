%Task #1 %Checked
assoc( At, [val(At, V)| _], V ).
assoc(At, [_ | Tail], V) :- assoc(At, Tail, V).


%Taks #2 %Checked
eval(Expr, _, Val):- number(Expr), Val is Expr.

eval(Expr, Assoc, Val):- atom(Expr), assoc(Expr, Assoc, Val).

eval(plus(A, B), Assoc, Val):- eval(A, Assoc, Val1), eval(B, Assoc, Val2), Val is Val1 + Val2.

eval(minus(A, B), Assoc, Val):- eval(A, Assoc, Val1), eval(B, Assoc, Val2), Val is Val1 - Val2.

eval(minus(A), Assoc, Val):- eval(A, Assoc, Val1), Val is -Val1.

eval(times(A, B), Assoc, Val):- eval(A, Assoc, Val1), eval(B, Assoc, Val2), Val is Val1 * Val2.

eval(divide(A, B), Assoc, Val):- eval(A, Assoc, Val1), eval(B, Assoc, Val2), Val is Val1 / Val2.


%Task #3 #Checked
deepreverse([], []).

deepreverse([Head| Tail], Reversedlist):-
    deepreverse(Head, Reversedhead),
    deepreverse(Tail, Reversedtail),
    append(Reversedtail, [Reversedhead], Reversedlist).

deepreverse(Atom, Atom) :- atom(Atom).
deepreverse(Atom, Atom) :- string(Atom).
deepreverse(Atom, Atom) :- number(Atom).


%Task #4
setinsertion(X, [], [X]).

setinsertion(X, [X|Tail], [X|Tail]).

setinsertion(X, [Head|Tail], [Head|NewTail]) :- X \= Head, setinsertion(X, Tail, NewTail).

%Task #5 %Completed %Checked
sortedinsert( X, [], [X]).

sortedinsert(X, [Head|Tail], [X, Head|Tail]) :- X < Head.

sortedinsert(X, [Head|Tail], [Head|NewTail]) :- X >= Head, sortedinsert(X, Tail, NewTail).

%Task #6 %Completed %Checked
graph1( [ edge( 1, 2 ), edge( 2, 3 ), edge( 3, 4 ), edge( 4, 1 ) ] ). %Test graphs
graph2( [ edge( 1, 2 ), edge( 2, 3 ), edge( 2, 4 ), edge( 3, 4 ),
edge( 4, 3 ), edge( 3, 1 ), edge( 4, 1 ) ] ).
graph3( [ edge( 1, 2 ), edge( 1, 3 ), edge( 2, 3 ), edge( 3, 2 ),
edge( 3, 4 ), edge( 2, 4 ), edge( 4, 6 ), edge( 4, 5 ),
edge( 5, 6 ), edge( 6, 5 ), edge( 6, 7 ), edge( 5, 7 ),
edge( 7, 1 ) ] ).

% part A %Completed %Checked
allnodes([], []).
allnodes([edge(A, B)|Tail], Nodes) :-
    allnodes(Tail, TailNodes),
    setinsertion(A, TailNodes, TempNodes),
    setinsertion(B, TempNodes, Nodes).


%part B %Completed %Checked
neighbour([edge(N1, N2)|_], N1, N2).

neighbour([_|Tail], N1, N2) :- neighbour(Tail, N1, N2).

%part C %Completed %Checked
pathextension(_, Path, 0, Path).

pathextension(G, [Current|Path], N, NewPath) :-
    N > 0,
    neighbour(G, Next, Current),
    \+ member(Next, [Current|Path]),
    N1 is N - 1,
    pathextension(G, [Next, Current|Path], N1, NewPath).

%part D
hamiltonian(G,Circ) :-
    allnodes(G, [F|Rest]),
    append([F], Rest, All),
    length(All, L),
    N is L-1,
    pathextension(G, [F], N, [First|Tail]),
    append([First], Tail, Circ),
    neighbour(G, F, First).
