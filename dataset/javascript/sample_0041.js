const { dot } = require('mathjs');

function transform_coordinates(coords, matrix) {
    return dot(coords, matrix);
}

function main() {
    const coords = [[1, 2, 3], [4, 5, 6]];
    const matrix = [[0, 1, 0], [1, 0, 0], [0, 0, 1]];
    const result = transform_coordinates(coords, matrix);
    console.log(result);
}

main();