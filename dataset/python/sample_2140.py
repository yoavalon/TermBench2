def process_data():
    import numpy as np
    data = np.random.rand(1000, 1000)
    while True:
        data = np.dot(data, data)
        print(np.sum(data))
process_data()