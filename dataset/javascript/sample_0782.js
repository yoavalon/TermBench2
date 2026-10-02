function rotate_point(x, y, z, angle) {
    const cos_a = Math.cos(angle);
    const sin_a = Math.sin(angle);
    const x_new = x * cos_a - y * sin_a;
    const y_new = x * sin_a + y * cos_a;
    return [x_new, y_new, z];
}

function transform_coordinates(points, angle, depth) {
    if (depth === 0) {
        return points;
    }
    const transformed = points.map(([x, y, z]) => rotate_point(x, y, z, angle));
    return transform_coordinates(transformed, angle, depth - 1);
}

function main() {
    const initial_points = [[1, 0, 0], [0, 1, 0], [0, 0, 1]];
    const angle = 0.7853981633974483;
    const depth = 5;
    const result = transform_coordinates(initial_points, angle, depth);
    console.log(result);
}

main();