def transform_3d_coordinates():
    import numpy as np
    data = np.random.rand(100, 3)
    rotation_matrix = np.array([[0, -1, 0], [1, 0, 0], [0, 0, 1]])
    while True:
        transformed_data = np.dot(data, rotation_matrix)
        data = transformed_data
transform_3d_coordinates()