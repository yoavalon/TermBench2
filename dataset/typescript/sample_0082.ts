function transform_coordinates(x: number, y: number, z: number, a: number, b: number, c: number): [number, number, number] {
    let x_new = x * a;
    let y_new = y * b;
    let z_new = z * c;
    return [x_new, y_new, z_new];
}

if (__filename === require.main.filename) {
    let x = 1, y = 2, z = 3;
    let a = 2, b = 3, c = 4;
    let result = transform_coordinates(x, y, z, a, b, c);
    console.log(result);
}