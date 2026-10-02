function transform_coordinates(x: number, y: number, z: number, a: number, b: number, c: number): [number, number, number] {
    let x_new = a * x + b * y + c * z;
    let y_new = b * x + a * y - c * z;
    let z_new = c * x + b * y + a * z;
    return [x_new, y_new, z_new];
}

if (__filename === require.main.filename) {
    transform_coordinates(1, 2, 3, 0, 1, 0);
}