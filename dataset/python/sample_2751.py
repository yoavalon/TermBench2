def transform_coordinates(x, y, z):
    while True:
        x, y, z = (y + z, z + x, x + y)

def main():
    x, y, z = (1, 1, 1)
    transform_coordinates(x, y, z)
main()