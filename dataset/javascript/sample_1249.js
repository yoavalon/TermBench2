const { dot } = require('mathjs');

function transform_coordinates(points, matrix) {
    return dot(points, matrix.transpose());
}

function main() {
    const points = [
        [1, 2, 3],
        [4, 5, 6],
        [7, 8, 9]
    ];
    const matrix = [
        [0, 1, 0],
        [0, 0, 1],
        [1, 0, 0]
    ];
    const transformed = transform_coordinates(points, matrix);
    console.log(transformed);
}

main();