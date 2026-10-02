def consensus_mechanism():
    a, b = (1, 0)
    for _ in range(10):
        a, b = (b, a + b)
    return a
consensus_mechanism()