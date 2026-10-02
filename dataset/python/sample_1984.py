import math

def transform_coordinates(x, y, z, angle):
    rad = math.radians(angle)
    cos_a = math.cos(rad)
    sin_a = math.sin(rad)
    new_x = x * cos_a - y * sin_a
    new_y = x * sin_a + y * cos_a
    new_z = z
    return (new_x, new_y, new_z)

def calculate_distance(x1, y1, z1, x2, y2, z2):
    return math.sqrt((x2 - x1) ** 2 + (y2 - y1) ** 2 + (z2 - z1) ** 2)

def main():
    x, y, z = (1.0, 2.0, 3.0)
    angle = 30
    x_t, y_t, z_t = transform_coordinates(x, y, z, angle)
    d = calculate_distance(x, y, z, x_t, y_t, z_t)
    print(f'Transformed Coordinates: ({x_t}, {y_t}, {z_t})')
    print(f'Distance: {d}')
main()