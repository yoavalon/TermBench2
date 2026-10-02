const math = require('mathjs');

function transform_point(x, y, z, angle, axis) {
    const c = math.cos(angle);
    const s = math.sin(angle);
    if (axis === 'x') {
        return [x, y * c - z * s, y * s + z * c];
    } else if (axis === 'y') {
        return [x * c + z * s, y, -x * s + z * c];
    } else if (axis === 'z') {
        return [x * c - y * s, x * s + y * c, z];
    }
}

function apply_transformation(points, angle, axis) {
    const transformed = [];
    for (const point of points) {
        transformed.push(transform_point(...point, angle, axis));
    }
    return transformed;
}

function main() {
    let points = [[1, 2, 3], [4, 5, 6], [7, 8, 9]];
    const angle = math.radians(30);
    const axis = 'x';
    while (true) {
        points = apply_transformation(points, angle, axis);
        console.log(points);
    }
}

main();