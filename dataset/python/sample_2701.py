def process_sequence():
    import numpy as np
    vocab = ['a', 'b', 'c']
    vector_size = 3
    while True:
        sequence = np.random.choice(vocab, size=np.random.randint(1, 10))
        vectorized_sequence = np.array([np.random.rand(vector_size) for _ in sequence])
        print(vectorized_sequence)
process_sequence()