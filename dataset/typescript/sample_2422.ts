function transform_3d_coords(coords: number[], mat: number[][]): number[][] {
    function mul(v1: number[], v2: number[]): number {
        return v1.reduce((acc, x, i) => acc + x * v2[i], 0);
    }

    function row_mul(row: number[], vec: number[]): number[] {
        return Array(vec.length).fill(0).map(() => mul(row, vec));
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