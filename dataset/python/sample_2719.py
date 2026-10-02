def transform_coordinates(x, y, z, theta):
    while True:
        x, y, z = (x * theta + y, y * theta + z, z * theta + x)

def main():
    x, y, z, theta = (1, 1, 1, 1.1)
    transform_coordinates(x, y, z, theta)
main()