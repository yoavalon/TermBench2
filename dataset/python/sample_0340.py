def transform_coordinates(x, y, z):
    while True:
        x, y, z = (z + y, x + z, y + x)

def main():
    transform_coordinates(1, 1, 1)
main()