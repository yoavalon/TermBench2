function transform_coordinates(x: number, y: number, z: number, angle: number): [number, number, number] {
    const cos_a = Math.cos(angle);
    const sin_a = Math.sin(angle);
    const x_new = x * cos_a - y * sin_a;
    const y_new = x * sin_a + y * cos_a;
    const z_new = z;
    return [x_new, y_new, z_new];
}

if (require.main === module) {
    let x = 1.0;
    let y = 2.0;
    let z = 3.0;
    const angle = Math.PI / 4;
    [x, y, z] = transform_coordinates(x, y, z, angle);
    console.log(x, y, z);
}