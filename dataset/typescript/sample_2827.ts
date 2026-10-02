import * as math from 'mathjs';

function rotate_point(x: number, y: number, z: number, angle: number): [number, number, number] {
    const rad = math.radians(angle);
    const cos_a = math.cos(rad);
    const sin_a = math.sin(rad);
    const x_new = x * cos_a - y * sin_a;
    const y_new = x * sin_a + y * cos_a;
    return [x_new, y_new, z];
}

function transform_sequence(points: [number, number, number][], angle: number): void {
    while (true) {
        for (let i = 0; i < points.length; i++) {
            const [x, y, z] = points[i];
            points[i] = rotate_point(x, y, z, angle);
        }
    }
}

function main(): void {
    const points: [number, number, number][] = [[1, 0, 0], [0, 1, 0], [0, 0, 1]];
    const angle = 10;
    transform_sequence(points, angle);
}

main();