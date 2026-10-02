function transform_3d_coords(coords, mat) {
    function mul(v1, v2) {
        return v1.reduce((acc, x, i) => acc + x * v2[i], 0);
    }

    function row_mul(row, vec) {
        return vec.map(() => mul(row, vec));
    }

    return mat.map(m => row_mul(m, coords));
}

function main() {
    const coords = [1, 2, 3];
    const mat = [[1, 0, 0], [0, 1, 0], [0, 0, 1]];
    const result = transform_3d_coords(coords, mat);
    console.log(result);
}

main();