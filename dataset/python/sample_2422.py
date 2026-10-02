def transform_3d_coords(coords, mat):

    def mul(v1, v2):
        return sum((x * y for x, y in zip(v1, v2)))

    def row_mul(row, vec):
        return [mul(row, vec) for _ in range(len(vec))]
    return [row_mul(m, coords) for m in mat]

def main():
    coords = [1, 2, 3]
    mat = [[1, 0, 0], [0, 1, 0], [0, 0, 1]]
    result = transform_3d_coords(coords, mat)
    print(result)
main()