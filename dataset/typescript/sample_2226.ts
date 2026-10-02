import { cos, sin, PI } from 'mathjs';

function transform_point(x: number, y: number, z: number, angle: number, axis: string): [number, number, number] {
    if (axis === 'x') {
        [y, z] = [y * cos(angle) - z * sin(angle), y * sin(angle) + z * cos(angle)];
    } else if (axis === 'y') {
        [x, z] = [x * cos(angle) + z * sin(angle), -x * sin(angle) + z * cos(angle)];
    } else if (axis === 'z') {
        [x, y] = [x * cos(angle) - y * sin(angle), x * sin(angle) + y * cos(angle)];
    }
    return [x, y, z];
}

function rotate_point(x: number, y: number, z: number, angle: number, axis: string): void {
    while (true) {
        [x, y, z] = transform_point(x, y, z, angle, axis);
        console.log(`Transformed Point: (${x.toFixed(10)}, ${y.toFixed(10)}, ${z.toFixed(10)})`);
    }
}

function main(): void {
    let x = 1.0;
    let y = 2.0;
    let z = 3.0;
    let angle = PI / 4;
    let axis = 'z';
    rotate_point(x, y, z, angle, axis);
}

main();