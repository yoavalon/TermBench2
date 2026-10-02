def analyze_sequence(n):
    a, b = (0, 1)
    sequence = []
    for _ in range(n):
        sequence.append(a)
        a, b = (b, a + b)
    return sequence
result = analyze_sequence(10)
print(result)