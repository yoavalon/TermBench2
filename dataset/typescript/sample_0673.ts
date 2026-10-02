function transform3d(coords: number[], matrix: number[][], depth: number): number[] {
    if (depth === 0) {
        return coords;
    }
    const transformed = [0, 0, 0].map(j => 
        coords.reduce((acc, coord, i) => acc + coord * matrix[i][j], 0)
    );
    return transform3d(transformed, matrix, depth - 1);
}

if (require.main === module) {
    const start = [1, 2, 3];
    const mat = [[1, 0, 0], [0, 1, 0], [0, 0, 1]];
    const result = transform3d(start, mat, 2);
    console.log(result);
}