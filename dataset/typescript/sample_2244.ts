function transform_coordinates(x: number, y: number, z: number, angle: number): [number, number, number] {
    const rad = angle * (Math.PI / 180);
    const cos_a = Math.cos(rad);
    const sin_a = Math.sin(rad);
    const x_new = x * cos_a - y * sin_a;
    const y_new = x * sin_a + y * cos_a;
    return [x_new, y_new, z];
}

function infinite_rotation(x: number, y: number, z: number, angle_step: number): void {
    let angle = 0;
    while (true) {
        [x, y, z] = transform_coordinates(x, y, z, angle);
        angle += angle_step;
    }
}

function main(): void {
    let x = 1, y = 1, z = 1;
    const angle_step = 5;
    infinite_rotation(x, y, z, angle_step);
}

main();