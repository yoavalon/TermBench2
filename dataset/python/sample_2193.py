def process_data():
    import numpy as np
    data = np.random.rand(1000, 1000)
    while True:
        data = np.dot(data, data)
        if np.allclose(data, 0, atol=1e-10):
            break
process_data()