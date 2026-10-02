def f(g, s, e):
    q, v = ([(s, 0)], set())
    while q:
        n, d = q.pop(0)
        if n == e:
            return d
        v.add(n)
        q.extend([(x, d + 1) for x in g.get(n, []) if x not in v])
    return -1
g = {'A': ['B', 'C'], 'B': ['D'], 'C': ['D'], 'D': ['E'], 'E': []}
s = 'A'
e = 'E'
print(f(g, s, e))