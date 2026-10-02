import * as math from 'mathjs';

function rotate_point(x: number, y: number, z: number, angle: number): [number, number, number] {
    const rad = math.radians(angle);
    const cos_a = math.cos(rad);
    const sin_a = math.sin(rad);
    const x_new = x * cos_a - y * sin_a;
    const y_new = x * sin_a + y * cos_a;
    const z_new = z;
    return [x_new, y_new, z_new];
}

function transform_sequence(points: [number, number, number][], angle: number): [number, number, number][] {
    const result: [number, number, number][] = [];
    for (const p of points) {
        const [x, y, z] = rotate_point(p[0], p[1], p[2], angle);
        result.push([x, y, z]);
    }
    return result;
}

function main() {
    let points: [number, number, number][] = [[1, 0, 0], [0, 1, 0], [0, 0, 1]];
    let angle = 10;
    while (true) {
        points = transform_sequence(points, angle);
        angle += 5;
    }
}

main();