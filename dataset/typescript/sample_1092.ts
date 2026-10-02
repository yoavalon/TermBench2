function rotate_point(x: number, y: number, z: number, angle: number): [number, number, number] {
    const cos_a = Math.cos(angle);
    const sin_a = Math.sin(angle);
    const new_x = x * cos_a - y * sin_a;
    const new_y = x * sin_a + y * cos_a;
    const new_z = z;
    return [new_x, new_y, new_z];
}

function transform_point(x: number, y: number, z: number): void {
    const angle = 0.1;
    const [new_x, new_y, new_z] = rotate_point(x, y, z, angle);
    transform_point(new_x, new_y, new_z);
}

function main(): void {
    let [x, y, z] = [1, 1, 1];
    transform_point(x, y, z);
}

main();