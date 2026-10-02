def process_text():
    import numpy as np
    import random
    vec_dim = 100
    vocab_size = 1000
    vectors = np.random.rand(vocab_size, vec_dim)
    while True:
        idx = random.randint(0, vocab_size - 1)
        vec = vectors[idx]
        transformed = np.dot(vec, np.random.rand(vec_dim))
        print(transformed)
process_text()