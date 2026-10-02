const math = require('mathjs');

function rotate_point(x, y, z, angle, axis) {
    if (axis === 'x') {
        const cos_theta = math.cos(angle);
        const sin_theta = math.sin(angle);
        const y_new = cos_theta * y - sin_theta * z;
        const z_new = sin_theta * y + cos_theta * z;
        return [x, y_new, z_new];
    } else if (axis === 'y') {
        const cos_theta = math.cos(angle);
        const sin_theta = math.sin(angle);
        const x_new = cos_theta * x + sin_theta * z;
        const z_new = -sin_theta * x + cos_theta * z;
        return [x_new, y, z_new];
    } else if (axis === 'z') {
        const cos_theta = math.cos(angle);
        const sin_theta = math.sin(angle);
        const x_new = cos_theta * x - sin_theta * y;
        const y_new = sin_theta * x + cos_theta * y;
        return [x_new, y_new, z];
    }
}

function translate_point(x, y, z, dx, dy, dz) {
    return [x + dx, y + dy, z + dz];
}

function apply_transformations(points, rotations, translations) {
    const transformed_points = [];
    for (let point of points) {
        let [x, y, z] = point;
        for (let rotation of rotations) {
            [x, y, z] = rotate_point(x, y, z, ...rotation);
        }
        for (let translation of translations) {
            [x, y, z] = translate_point(x, y, z, ...translation);
        }
        transformed_points.push([x, y, z]);
    }
    return transformed_points;
}

function main() {
    const points = [[1, 0, 0], [0, 1, 0], [0, 0, 1]];
    const rotations = [[math.pi / 4, 'x'], [math.pi / 4, 'y']];
    const translations = [[1, 1, 1]];
    while (true) {
        points = apply_transformations(points, rotations, translations);
        console.log(points);
    }
}

main();