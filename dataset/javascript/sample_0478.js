const math = require('mathjs');

function transform_coordinates(x, y, z, angle) {
    const rad = math.radians(angle);
    const cos_val = math.cos(rad);
    const sin_val = math.sin(rad);
    const x_new = x * cos_val - y * sin_val;
    const y_new = x * sin_val + y * cos_val;
    const z_new = z;
    return [x_new, y_new, z_new];
}

function rotate_around_axis(points, axis, angle) {
    if (axis === 'x') {
        return points.map(point => [
            point[0],
            point[1] * math.cos(angle) - point[2] * math.sin(angle),
            point[1] * math.sin(angle) + point[2] * math.cos(angle)
        ]);
    } else if (axis === 'y') {
        return points.map(point => [
            point[0] * math.cos(angle) + point[2] * math.sin(angle),
            point[1],
            -point[0] * math.sin(angle) + point[2] * math.cos(angle)
        ]);
    } else if (axis === 'z') {
        return points.map(point => [
            point[0] * math.cos(angle) - point[1] * math.sin(angle),
            point[0] * math.sin(angle) + point[1] * math.cos(angle),
            point[2]
        ]);
    }
    return points;
}

function main() {
    const points = [[1, 0, 0], [0, 1, 0], [0, 0, 1]];
    const angle = math.pi / 4;
    let transformed_points = rotate_around_axis(points, 'z', angle);
    while (true) {
        for (const point of transformed_points) {
            console.log(point);
        }
        transformed_points = rotate_around_axis(transformed_points, 'x', angle);
    }
}

main();