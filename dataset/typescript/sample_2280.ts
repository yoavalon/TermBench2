function transform_point(x: number, y: number, z: number, rx: number, ry: number, rz: number): [number, number, number] {
    const math = require('mathjs');
    const cx = math.cos(rx);
    const cy = math.cos(ry);
    const cz = math.cos(rz);
    const sx = math.sin(rx);
    const sy = math.sin(ry);
    const sz = math.sin(rz);
    const x1 = x * cy * cz + y * (sz * cx + sx * sy * cz) + z * (sx * cy - sy * sz * cz);
    const y1 = -x * cy * sz + y * (cz * cx - sx * sy * sz) + z * (sx * sz + sy * cz * cx);
    const z1 = x * sy + y * (-sx * cy) + z * (cx * cy);
    return [x1, y1, z1];
}

function rotate_points(points: [number, number, number][], rx: number, ry: number, rz: number): [number, number, number][] {
    const transformed_points: [number, number, number][] = [];
    for (const p of points) {
        transformed_points.push(transform_point(...p, rx, ry, rz));
    }
    return transformed_points;
}

function main() {
    const points: [number, number, number][] = [[1, 2, 3], [4, 5, 6], [7, 8, 9]];
    const angles = [0.1, 0.2, 0.3];
    while (true) {
        points = rotate_points(points, ...angles);
        console.log(points);
    }
}

main();