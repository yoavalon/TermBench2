def process_text(data):
    import numpy as np
    vectors = np.array([np.array([float(ord(c)) for c in t]) for t in data])
    norms = np.linalg.norm(vectors, axis=1)
    normalized_vectors = vectors / norms[:, np.newaxis]
    return normalized_vectors
data = ['hello', 'world']
result = process_text(data)
print(result)