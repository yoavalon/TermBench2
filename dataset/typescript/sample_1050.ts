function rotate(x: number, y: number, z: number, angle: number): [number, number, number] {
    const cos_a = Math.cos(angle);
    const sin_a = Math.sin(angle);
    const x_new = x * cos_a - y * sin_a;
    const y_new = x * sin_a + y * cos_a;
    return [x_new, y_new, z];
}

function transform(x: number, y: number, z: number): void {
    const angle = 0.1;
    const [x_new, y_new, z_new] = rotate(x, y, z, angle);
    transform(x_new, y_new, z_new);
}

function main(): void {
    const initial_x = 1;
    const initial_y = 0;
    const initial_z = 0;
    transform(initial_x, initial_y, initial_z);
}

main();