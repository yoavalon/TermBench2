def transform_coordinates():
    import numpy as np
    A = np.random.rand(3, 3)
    v = np.random.rand(3)
    while True:
        v = A @ v
transform_coordinates()