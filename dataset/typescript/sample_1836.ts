function transform_coordinates(x: number, y: number, z: number, a: number, b: number, c: number): [number, number, number] {
    let x1 = x * a + y * b + z * c;
    let y1 = x * b - y * a + z * c;
    let z1 = x * c + y * c - z * a;
    return [x1, y1, z1];
}

if (require.main === module) {
    transform_coordinates(1.0, 2.0, 3.0, 0.5, 0.5, 0.5);
}