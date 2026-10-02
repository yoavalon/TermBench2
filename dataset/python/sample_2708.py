import numpy as np

def transform_sequence():
    while True:
        a, b, c = np.random.rand(3) * 100
        x, y, z = np.random.rand(3) * 100
        rotation_matrix = np.array([[np.cos(a), -np.sin(a), 0], [np.sin(a), np.cos(a), 0], [0, 0, 1]])
        translated_point = np.dot(rotation_matrix, [x, y, z]) + [b, c, 0]
        print(translated_point)
transform_sequence()