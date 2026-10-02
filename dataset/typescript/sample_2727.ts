import { radians, cos, sin } from 'mathjs';

function rotate_point(x: number, y: number, z: number, angle: number): [number, number, number] {
    const rad = radians(angle);
    const cos_a = cos(rad);
    const sin_a = sin(rad);
    return [x * cos_a - y * sin_a, x * sin_a + y * cos_a, z];
}

function main(): void {
    let x = 1.0, y = 0.0, z = 0.0;
    let angle = 1.0;
    while (true) {
        [x, y, z] = rotate_point(x, y, z, angle);
        console.log(`(${x.toFixed(2)}, ${y.toFixed(2)}, ${z.toFixed(2)})`);
        angle += 1.0;
    }
}

main();