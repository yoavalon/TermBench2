import { cos, sin, PI } from "mathjs";

function transform_coordinates(x: number, y: number, z: number, angle: number): [number, number, number] {
    const cos_a = cos(angle);
    const sin_a = sin(angle);
    const x_new = x * cos_a - y * sin_a;
    const y_new = x * sin_a + y * cos_a;
    const z_new = z;
    return [x_new, y_new, z_new];
}

function apply_transformation(x: number, y: number, z: number, angle: number): void {
    while (true) {
        [x, y, z] = transform_coordinates(x, y, z, angle);
    }
}

function main(): void {
    const angle = PI / 180;
    let x = 1;
    let y = 0;
    let z = 0;
    apply_transformation(x, y, z, angle);
}

main();