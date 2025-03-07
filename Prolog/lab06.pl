  enggerm(table, tisch,  m).
  enggerm(chair, stuhl, m).
  enggerm(bed, bett, n).
  enggerm(child, kind, n).
  enggerm(brother, bruder, m).
  enggerm(sister,  schwester, f).
  enggerm(house,  haus, n).
  enggerm(sun,  sonne, f).
  enggerm(cloud,  wolke,  f).
  enggerm(wind,  wind,  m).
  enggerm(rain, regen, m).

  engit(table, tavolo, m).
  engit(chair, sedia, f).
  engit(bed, letto, m).
  engit(child, bambino, m).
  engit(child, bambina, f).
  engit(brother, fratello, m).
  engit(sister, sorella, f).
  engit(house, casa, f).
  engit(sun, sole, f).
  engit(cloud, nube, f).
  engit(wind, vento, m).
  engit(rain, pioggia, f).

  article( f, die ).
  article( m, der ).
  article( n, das ).

  gerwitharticle( E, A, G ) :- enggerm(E, G, Gender), article(Gender, A).

  gerit( G, I ) :- enggerm(E, G, _), engit(E, I, _).

  samegender(E) :- enggerm(E, _, Gender), engit(E, _, Gender).

  %Part 2 of the lab
  male(carl_xvi_gustaf).
  female(silvia).
  male(daniel).
  female(victoria).
  male(carl_philip).
  female(sofia).
  female(madeleine).
  male(christopher_o_neill).
  female(estelle).
  male(oscar).
  male(alexander).
  male(gabriel).
  male(julian).
  female(leonore).
  male(nicolas).
  female(adrienne).

  parent(carl_xvi_gustaf, victoria).
  parent(silvia, victoria).

  parent(carl_xvi_gustaf, carl_philip).
  parent(silvia, carl_philip).

  parent(carl_xvi_gustaf, madeleine).
  parent(silvia, madeleine).

  parent(daniel, estelle).
  parent(victoria, estelle).

  parent(daniel, oscar).
  parent(victoria, oscar).

  parent(carl_philip, alexander).
  parent(sofia, alexander).

  parent(carl_philip, gabriel).
  parent(sofia, gabriel).

  parent(carl_philip, julian).
  parent(sofia, julian).

  parent(madeleine, leonore).
  parent(christopher_o_neill, leonore).

  parent(madeleine, nicolas).
  parent(christopher_o_neill, nicolas).

  parent(madeleine, adrienne).
  parent(christopher_o_neill, adrienne).

  rulesover(carl_xvi_gustaf, sweden).
  rulesover(silvia, sweden).
  rulesover(daniel, vastergotland).
  rulesover(victoria, vastergotland).
  rulesover(carl_philip, varmland).
  rulesover(sofia, varmland).
  rulesover(madeleine, halsingland).
  rulesover(madeleine, gastrikland).
  rulesover(estelle, ostergotland).
  rulesover(oscar, skane).
  rulesover(alexander, sodermanland).
  rulesover(gabriel, dalama).
  rulesover(julian, halland).
  rulesover(leonore, gotland).
  rulesover(nicolas, angermanland).
  rulesover(adrienne, blekinge).

  child(X, Y) :- parent(Y, X).
  sibling(Y1, Y2) :- child(Y1, X1), child(Y2, X1),
                     child(Y1, X2), child(Y2, X2),
                     X1 \= X2,Y1 \= Y2.
  sister(X, Y) :-  female(X), sibling(X, Y).
  brother(X, Y) :- male(X), sibling(X, Y).

  mother(X, Y) :- female(X), parent(X, Y).
  father(X, Y) :- male(X), parent(X, Y).

  son(X, Y) :- male(X), child(X, Y).
  daughter(X, Y) :- female(X), child(X, Y).

  king(X) :- male(X), rulesover(X, sweden).
  queen(X) :- female(X), rulesover(X, sweden).

  duke(X) :- male(X), rulesover(X, Y), Y \= sweden.
  duchess(X) :- female(X), rulesover(X, Y), Y \= sweden.
