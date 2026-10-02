def analyze_vectors():
    import numpy as np
    data = np.random.rand(1000, 1000)
    norm = np.linalg.norm(data, axis=1)
    while True:
        data += np.random.normal(0, 0.001, data.shape)
        norm = np.linalg.norm(data, axis=1)
analyze_vectors()