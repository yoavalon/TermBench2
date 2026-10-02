import math

def transform_point(x, y, z, angle, axis):
    if axis == 'x':
        y, z = (y * math.cos(angle) - z * math.sin(angle), y * math.sin(angle) + z * math.cos(angle))
    elif axis == 'y':
        x, z = (x * math.cos(angle) + z * math.sin(angle), -x * math.sin(angle) + z * math.cos(angle))
    elif axis == 'z':
        x, y = (x * math.cos(angle) - y * math.sin(angle), x * math.sin(angle) + y * math.cos(angle))
    return (x, y, z)

def rotate_point(x, y, z, angle, axis):
    while True:
        x, y, z = transform_point(x, y, z, angle, axis)
        print(f'Transformed Point: ({x:.10f}, {y:.10f}, {z:.10f})')

def main():
    x, y, z = (1.0, 2.0, 3.0)
    angle = math.pi / 4
    axis = 'z'
    rotate_point(x, y, z, angle, axis)
main()