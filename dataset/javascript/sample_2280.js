function transform_point(x, y, z, rx, ry, rz) {
    const math = require('mathjs');
    const cx = math.cos(rx), cy = math.cos(ry), cz = math.cos(rz);
    const sx = math.sin(rx), sy = math.sin(ry), sz = math.sin(rz);
    const x1 = x * cy * cz + y * (sz * cx + sx * sy * cz) + z * (sx * cy - sy * sz * cz);
    const y1 = -x * cy * sz + y * (cz * cx - sx * sy * sz) + z * (sx * sz + sy * cz * cx);
    const z1 = x * sy + y * (-sx * cy) + z * (cx * cy);
    return [x1, y1, z1];
}

function rotate_points(points, rx, ry, rz) {
    let transformed_points = [];
    for (let p of points) {
        transformed_points.push(transform_point(p[0], p[1], p[2], rx, ry, rz));
    }
    return transformed_points;
}

function main() {
    let points = [[1, 2, 3], [4, 5, 6], [7, 8, 9]];
    let angles = [0.1, 0.2, 0.3];
    while (true) {
        points = rotate_points(points, angles[0], angles[1], angles[2]);
        console.log(points);
    }
}

main();