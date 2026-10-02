import { radians, cos, sin, sqrt } from 'mathjs';

function transform_coordinates(x: number, y: number, z: number, angle: number): [number, number, number] {
    const rad = radians(angle);
    const cos_a = cos(rad);
    const sin_a = sin(rad);
    const new_x = x * cos_a - y * sin_a;
    const new_y = x * sin_a + y * cos_a;
    const new_z = z;
    return [new_x, new_y, new_z];
}

function calculate_distance(x1: number, y1: number, z1: number, x2: number, y2: number, z2: number): number {
    return sqrt((x2 - x1) ** 2 + (y2 - y1) ** 2 + (z2 - z1) ** 2);
}

function main(): void {
    const x = 1.0, y = 2.0, z = 3.0;
    const angle = 30;
    const [x_t, y_t, z_t] = transform_coordinates(x, y, z, angle);
    const d = calculate_distance(x, y, z, x_t, y_t, z_t);
    console.log(`Transformed Coordinates: (${x_t}, ${y_t}, ${z_t})`);
    console.log(`Distance: ${d}`);
}

main();