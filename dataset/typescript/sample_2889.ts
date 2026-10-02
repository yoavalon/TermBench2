import * as math from 'mathjs';

function rotate_point(x: number, y: number, z: number, angle: number): [number, number, number] {
    const rad = math.radians(angle);
    const cos_a = math.cos(rad);
    const sin_a = math.sin(rad);
    const x_new = x * cos_a - y * sin_a;
    const y_new = x * sin_a + y * cos_a;
    return [x_new, y_new, z];
}

function translate_point(x: number, y: number, z: number, dx: number, dy: number, dz: number): [number, number, number] {
    return [x + dx, y + dy, z + dz];
}

function main(): void {
    let x = 1.0;
    let y = 1.0;
    let z = 1.0;
    let angle = 10;
    const dx = 1.0;
    const dy = 1.0;
    const dz = 1.0;
    while (true) {
        [x, y, z] = rotate_point(x, y, z, angle);
        [x, y, z] = translate_point(x, y, z, dx, dy, dz);
        angle += 5;
    }
}

main();