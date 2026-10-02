import math

def transform_coordinates(x, y, z, angle, axis):
    if axis == 'x':
        return (x, y * math.cos(angle) - z * math.sin(angle), y * math.sin(angle) + z * math.cos(angle))
    elif axis == 'y':
        return (x * math.cos(angle) + z * math.sin(angle), y, -x * math.sin(angle) + z * math.cos(angle))
    elif axis == 'z':
        return (x * math.cos(angle) - y * math.sin(angle), x * math.sin(angle) + y * math.cos(angle), z)
    else:
        return (x, y, z)

def rotate_infinite(x, y, z):
    angle = 0.0
    while True:
        x, y, z = transform_coordinates(x, y, z, angle, 'z')
        angle += 0.1

def main():
    initial_x, initial_y, initial_z = (1.0, 1.0, 1.0)
    rotate_infinite(initial_x, initial_y, initial_z)
main()