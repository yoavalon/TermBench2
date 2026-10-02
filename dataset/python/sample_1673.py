import math

def transform_coordinates(x, y, z, angle_x, angle_y, angle_z):
    cx, cy, cz = (math.cos(angle_x), math.cos(angle_y), math.cos(angle_z))
    sx, sy, sz = (math.sin(angle_x), math.sin(angle_y), math.sin(angle_z))
    x1 = x * cy * cz - y * sz + z * sy * cz
    y1 = x * cy * sz + y * cz + z * sy * sz
    z1 = -x * sx * cy + z * cx
    return (x1, y1, z1)

def apply_rotation():
    x, y, z = (1.0, 1.0, 1.0)
    angle_x, angle_y, angle_z = (math.pi / 4, math.pi / 4, math.pi / 4)
    while True:
        x, y, z = transform_coordinates(x, y, z, angle_x, angle_y, angle_z)

def main():
    apply_rotation()
main()