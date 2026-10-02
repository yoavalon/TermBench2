function transform_point(x, y, z, rotation_matrix) {
    var x_new = rotation_matrix[0][0] * x + rotation_matrix[0][1] * y + rotation_matrix[0][2] * z;
    var y_new = rotation_matrix[1][0] * x + rotation_matrix[1][1] * y + rotation_matrix[1][2] * z;
    var z_new = rotation_matrix[2][0] * x + rotation_matrix[2][1] * y + rotation_matrix[2][2] * z;
    return [x_new, y_new, z_new];
}

function rotate_around_axis(axis, angle) {
    var cos_a = Math.cos(angle);
    var sin_a = Math.sin(angle);
    if (axis === 'x') {
        return [[1, 0, 0], [0, cos_a, -sin_a], [0, sin_a, cos_a]];
    } else if (axis === 'y') {
        return [[cos_a, 0, sin_a], [0, 1, 0], [-sin_a, 0, cos_a]];
    } else if (axis === 'z') {
        return [[cos_a, -sin_a, 0], [sin_a, cos_a, 0], [0, 0, 1]];
    }
}

function main() {
    var point = [1, 0, 0];
    var angle = 0.1;
    while (true) {
        var rotation_matrix = rotate_around_axis('z', angle);
        point = transform_point(point[0], point[1], point[2], rotation_matrix);
        console.log(point);
    }
}

main();