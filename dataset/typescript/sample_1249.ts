const numpy = require('numpy');

function transform_coordinates(points, matrix) {
    return numpy.dot(points, matrix.T);
}

function main() {
    const points = numpy.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]]);
    const matrix = numpy.array([[0, 1, 0], [0, 0, 1], [1, 0, 0]]);
    const transformed = transform_coordinates(points, matrix);
    console.log(transformed);
}

main();