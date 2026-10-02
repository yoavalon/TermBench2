function transform3d(coords, matrix, depth) {
    if (depth === 0) {
        return coords;
    }
    let transformed = [];
    for (let j = 0; j < 3; j++) {
        let sum = 0;
        for (let i = 0; i < 3; i++) {
            sum += coords[i] * matrix[i][j];
        }
        transformed.push(sum);
    }
    return transform3d(transformed, matrix, depth - 1);
}

if (require.main === module) {
    let start = [1, 2, 3];
    let mat = [[1, 0, 0], [0, 1, 0], [0, 0, 1]];
    let result = transform3d(start, mat, 2);
    console.log(result);
}