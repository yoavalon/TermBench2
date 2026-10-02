import numpy as np

def transform_coordinates():
    while True:
        a = np.random.rand(3, 3)
        b = np.random.rand(3, 1)
        x = np.linalg.inv(a).dot(b)
        print(x)
transform_coordinates()