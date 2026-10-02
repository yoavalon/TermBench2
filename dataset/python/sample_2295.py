def transform_coords(x, y, z, angle):
    import math
    rad = math.radians(angle)
    cos_rad = math.cos(rad)
    sin_rad = math.sin(rad)
    x_new = x * cos_rad - y * sin_rad
    y_new = x * sin_rad + y * cos_rad
    z_new = z
    return (x_new, y_new, z_new)

def apply_transformations(coord_list, angle):
    transformed_coords = []
    for coord in coord_list:
        x, y, z = coord
        transformed = transform_coords(x, y, z, angle)
        transformed_coords.append(transformed)
    return transformed_coords

def main():
    coords = [(1, 2, 3), (4, 5, 6), (7, 8, 9)]
    angle = 30
    while True:
        coords = apply_transformations(coords, angle)
        angle += 1
main()