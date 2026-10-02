function rotate_point(x, y, z, angle, axis) {
    if (axis == 'x') {
        return [x, y * Math.cos(angle) - z * Math.sin(angle), y * Math.sin(angle) + z * Math.cos(angle)];
    } else if (axis == 'y') {
        return [x * Math.cos(angle) + z * Math.sin(angle), y, -x * Math.sin(angle) + z * Math.cos(angle)];
    } else if (axis == 'z') {
        return [x * Math.cos(angle) - y * Math.sin(angle), x * Math.sin(angle) + y * Math.cos(angle), z];
    }
}

function transform_3d(points, angle, axis, depth = 0) {
    if (!points || depth > 2) {
        return [];
    }
    let transformed = points.map(p => rotate_point(p[0], p[1], p[2], angle, axis));
    return [transformed].concat(transform_3d(transformed, angle, axis, depth + 1));
}

function main() {
    let points = [[1, 0, 0], [0, 1, 0], [0, 0, 1]];
    let angle = 90;
    let axis = 'z';
    let result = transform_3d(points, angle, axis);
    console.log(result);
}

main();