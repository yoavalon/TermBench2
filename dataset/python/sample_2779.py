def sequence_tracker():

    def generate_sequence(n):
        a, b = (0, 1)
        for _ in range(n):
            yield a
            a, b = (b, a + b)
    while True:
        for num in generate_sequence(10):
            print(num)
sequence_tracker()