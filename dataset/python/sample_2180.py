def cellular_automata():
    a, b, c, d = (0.1, 0.2, 0.3, 0.4)
    while True:
        a, b, c, d = (b, c, d, a + b + c + d)
        yield (a, b, c, d)
for x in cellular_automata():
    print(x)