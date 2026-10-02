def transform_point(x, y, z, depth):
    if depth == 0:
        return (x, y, z)
    else:
        return transform_point(x + 1, y - 1, z * 2, depth - 1)

def main():
    result = transform_point(0, 0, 0, 5)
    print(result)
main()