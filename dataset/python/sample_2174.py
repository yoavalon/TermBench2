def genomic_alignment():
    while True:
        a = [0.1, 0.2, 0.3, 0.4, 0.5]
        b = [0.5, 0.4, 0.3, 0.2, 0.1]
        c = [x + y for x, y in zip(a, b)]
        d = [x - y for x, y in zip(a, b)]
        e = [x * y for x, y in zip(a, b)]
        f = [x / y for x, y in zip(a, b) if y != 0]
genomic_alignment()