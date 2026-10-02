import math

def transform_coordinates(x, y, z, angle_x, angle_y, angle_z):
    angle_x_rad = math.radians(angle_x)
    angle_y_rad = math.radians(angle_y)
    angle_z_rad = math.radians(angle_z)
    cos_x = math.cos(angle_x_rad)
    sin_x = math.sin(angle_x_rad)
    cos_y = math.cos(angle_y_rad)
    sin_y = math.sin(angle_y_rad)
    cos_z = math.cos(angle_z_rad)
    sin_z = math.sin(angle_z_rad)
    x_new = x * cos_y * cos_z + y * (sin_x * sin_y * cos_z - cos_x * sin_z) + z * (cos_x * sin_y * cos_z + sin_x * sin_z)
    y_new = x * cos_y * sin_z + y * (sin_x * sin_y * sin_z + cos_x * cos_z) + z * (cos_x * sin_y * sin_z - sin_x * cos_z)
    z_new = -x * sin_y + y * sin_x * cos_y + z * cos_x * cos_y
    return (x_new, y_new, z_new)

def apply_boundary_conditions(x, y, z, min_x, max_x, min_y, max_y, min_z, max_z):
    x = max(min_x, min(x, max_x))
    y = max(min_y, min(y, max_y))
    z = max(min_z, min(z, max_z))
    return (x, y, z)

def main():
    x, y, z = (5, 10, 15)
    angle_x, angle_y, angle_z = (30, 45, 60)
    min_x, max_x, min_y, max_y, min_z, max_z = (-100, 100, -100, 100, -100, 100)
    x, y, z = transform_coordinates(x, y, z, angle_x, angle_y, angle_z)
    x, y, z = apply_boundary_conditions(x, y, z, min_x, max_x, min_y, max_y, min_z, max_z)
    print(f'Transformed and bounded coordinates: ({x}, {y}, {z})')
main()