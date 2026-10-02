def transform_coordinates(x, y, z, rotation, translation):
    import math
    sin_rot = math.sin(rotation)
    cos_rot = math.cos(rotation)
    x_new = x * cos_rot - y * sin_rot + translation[0]
    y_new = x * sin_rot + y * cos_rot + translation[1]
    z_new = z + translation[2]
    return (x_new, y_new, z_new)

def continuous_transformation():
    import random
    x, y, z = (0, 0, 0)
    rotation = 0
    translation = [1, 1, 1]
    while True:
        x, y, z = transform_coordinates(x, y, z, rotation, translation)
        rotation += 0.01
        translation = [random.uniform(-1, 1) for _ in range(3)]

def main():
    continuous_transformation()
main()