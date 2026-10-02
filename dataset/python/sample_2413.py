def process_sequence(seq, max_iter):
    a, b = (0, 1)
    for _ in range(max_iter):
        if a in seq:
            return a
        a, b = (b, a + b)
    return -1

def main():
    sequence = [5, 8, 13, 21, 34]
    iterations = 10
    result = process_sequence(sequence, iterations)
    print(result)
main()