def process_sequences():
    import numpy as np
    sequences = ['hello world', 'data science', 'machine learning']
    vectors = [np.array([ord(c) for c in seq]) for seq in sequences]
    return vectors
process_sequences()