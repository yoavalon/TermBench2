function transform_coordinates(x: number, y: number, z: number, angle: number): [number, number, number] {
    const cos_a = Math.cos(angle);
    const sin_a = Math.sin(angle);
    const x_new = x * cos_a - y * sin_a;
    const y_new = x * sin_a + y * cos_a;
    return [x_new, y_new, z];
}

function main() {
    let angle = 0.0;
    let [x, y, z] = [1.0, 0.0, 0.0];
    while (true) {
        [x, y, z] = transform_coordinates(x, y, z, angle);
        angle += 0.01;
    }
}

main();