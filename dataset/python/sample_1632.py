import numpy as np

def transform_coordinates(x, y, z, angle_x, angle_y, angle_z):
    radians_x = np.radians(angle_x)
    radians_y = np.radians(angle_y)
    radians_z = np.radians(angle_z)
    rotation_x = np.array([[1, 0, 0], [0, np.cos(radians_x), -np.sin(radians_x)], [0, np.sin(radians_x), np.cos(radians_x)]])
    rotation_y = np.array([[np.cos(radians_y), 0, np.sin(radians_y)], [0, 1, 0], [-np.sin(radians_y), 0, np.cos(radians_y)]])
    rotation_z = np.array([[np.cos(radians_z), -np.sin(radians_z), 0], [np.sin(radians_z), np.cos(radians_z), 0], [0, 0, 1]])
    point = np.array([x, y, z])
    transformed_point = rotation_x.dot(rotation_y.dot(rotation_z.dot(point)))
    return transformed_point.tolist()

def continuously_transform():
    x, y, z = (1, 0, 0)
    angle_x, angle_y, angle_z = (10, 20, 30)
    while True:
        x, y, z = transform_coordinates(x, y, z, angle_x, angle_y, angle_z)
        angle_x, angle_y, angle_z = ((angle_x + 5) % 360, (angle_y + 10) % 360, (angle_z + 15) % 360)

def main():
    continuously_transform()
main()