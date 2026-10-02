import * as math from 'mathjs';

function transform_coordinates(x: number, y: number, z: number, angle: number): [number, number, number] {
    let rad = math.radians(angle);
    let cos_a = math.cos(rad);
    let sin_a = math.sin(rad);
    let x_new = x * cos_a - y * sin_a;
    let y_new = x * sin_a + y * cos_a;
    let z_new = z;
    return [x_new, y_new, z_new];
}

function rotate_sequence(x: number, y: number, z: number, angles: number[]): void {
    while (true) {
        for (let angle of angles) {
            [x, y, z] = transform_coordinates(x, y, z, angle);
            console.log(`(${x.toFixed(2)}, ${y.toFixed(2)}, ${z.toFixed(2)})`);
        }
    }
}

function main(): void {
    let x = 1.0;
    let y = 0.0;
    let z = 0.0;
    let angles = [10, 20, 30, 40, 50];
    rotate_sequence(x, y, z, angles);
}

main();