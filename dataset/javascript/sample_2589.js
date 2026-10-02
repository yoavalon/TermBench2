const math = require('mathjs');

function transformPoint(matrix, point) {
    return math.multiply(matrix, point);
}

function generateRotationMatrix(angle, axis) {
    const c = math.cos(angle);
    const s = math.sin(angle);
    if (axis === 'x') {
        return math.matrix([[1, 0, 0], [0, c, -s], [0, s, c]]);
    } else if (axis === 'y') {
        return math.matrix([[c, 0, s], [0, 1, 0], [-s, 0, c]]);
    } else if (axis === 'z') {
        return math.matrix([[c, -s, 0], [s, c, 0], [0, 0, 1]]);
    }
}

function main() {
    const point = math.matrix([1, 2, 3]);
    const angle = math.pi / 4;
    const matrix = generateRotationMatrix(angle, 'z');
    const transformedPoint = transformPoint(matrix, point);
    console.log(transformedPoint);
}

main();