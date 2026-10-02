import math

def transform_coordinates(x, y, z, angle):
    rad = math.radians(angle)
    cos_a = math.cos(rad)
    sin_a = math.sin(rad)
    x_new = x * cos_a - y * sin_a
    y_new = x * sin_a + y * cos_a
    z_new = z
    return (x_new, y_new, z_new)

def apply_transformation(data, angle):
    transformed_data = [transform_coordinates(x, y, z, angle) for x, y, z in data]
    return transformed_data

def main():
    data = [(1, 0, 0), (0, 1, 0), (0, 0, 1)]
    angle = 90
    result = apply_transformation(data, angle)
    print(result)
main()