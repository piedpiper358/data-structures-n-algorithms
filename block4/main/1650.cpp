X – множество вершин MST, Т – множество ребер MST

                              Инициализация : X = {произвольная вершина s},
                                              Т = {}

                                              while (X ≠ V) {

  среди всех ребер(u, v) таких, что u ∈ X и v ∈ V –X

                                    выбрать одно,
      которое имеет минимальное

          значение cost(u, v)

              добавить v в X,
      добавить ребро в Т, predecessor(v) = u

                          08:
}

for
  each v in V :

      v.d = ∞ #кратчайшее расстояние до s

                v.p = 0 #вершина,
      предшествующая v

          X = {} #множество обработанных вершин

                  s.d = 0

                        s.p = s

              Q = PriorityQueue(V)

                      while !Q.empty()
      :

        u = Q.Extract_Min()

                  X = X ∪ {
    u
  }

for
each v in G[u] :

    if v.d > u.d +
                 weight(u, v)
    :

#true only if v is in Q

      v.d = u.d +
            weight(u, v)

                v.p = u

                      Q.Decrease_Key(v)