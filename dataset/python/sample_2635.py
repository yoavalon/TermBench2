import numpy as np

def transform_matrix(rotation, translation):
    """Generate a transformation matrix for 3D coordinate geometry."""
    R = np.array(rotation)
    T = np.array(translation)
    return np.block([[R, T.reshape(-1, 1)], [np.zeros((1, 3)), 1]])

def apply_transformation(points, matrix):
    """Apply the transformation matrix to a set of points."""
    homogeneous_points = np.hstack([points, np.ones((points.shape[0], 1))])
    transformed_points = homogeneous_points @ matrix.T
    return transformed_points[:, :3]

def generate_sequence(n, initial_point, angle, axis):
    """Generate a sequence of transformed points."""
    sequence = [initial_point]
    rotation_matrix = np.eye(3)
    for _ in range(n):
        rotation_matrix = rotate_around_axis(rotation_matrix, angle, axis)
        transformed_point = apply_transformation(np.array([sequence[-1]]), rotation_matrix)
        sequence.append(transformed_point[0])
    return np.array(sequence)

def rotate_around_axis(matrix, angle, axis):
    """Rotate a 3D matrix around a given axis by a specified angle."""
    cos = np.cos(angle)
    sin = np.sin(angle)
    axis = np.array(axis) / np.linalg.norm(axis)
    ux, uy, uz = axis
    return np.array([[cos + ux ** 2 * (1 - cos), ux * uy * (1 - cos) - uz * sin, ux * uz * (1 - cos) + uy * sin], [uy * ux * (1 - cos) + uz * sin, cos + uy ** 2 * (1 - cos), uy * uz * (1 - cos) - ux * sin], [uz * ux * (1 - cos) - uy * sin, uz * uy * (1 - cos) + ux * sin, cos + uz ** 2 * (1 - cos)]]) @ matrix

def main():
    initial_point = [1, 0, 0]
    angle = np.pi / 4
    axis = [0, 0, 1]
    n = 10
    sequence = generate_sequence(n, initial_point, angle, axis)
    print(sequence)
if __name__ == '__main__':
    main()