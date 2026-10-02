function transform_3d(point, matrix) {
    let result = [0, 0, 0];
    for (let i = 0; i < 3; i++) {
        for (let j = 0; j < 3; j++) {
            result[i] += point[j] * matrix[i][j];
        }
    }
    return result;
}

function main() {
    let point = [1.0, 2.0, 3.0];
    let matrix = [[0, 1, 0], [0, 0, 1], [1, 0, 0]];
    let transformed = transform_3d(point, matrix);
    console.log(transformed);
}

main();