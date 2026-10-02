function transform_coordinates(x: number, y: number, z: number): [number, number, number] {
    const angle = Math.PI / 4;
    const cos_a = Math.cos(angle);
    const sin_a = Math.sin(angle);
    const x_new = x * cos_a - y * sin_a;
    const y_new = x * sin_a + y * cos_a;
    const z_new = z;
    return [x_new, y_new, z_new];
}

function apply_transformation() {
    let [x, y, z] = [1.0, 1.0, 1.0];
    while (true) {
        [x, y, z] = transform_coordinates(x, y, z);
        console.log(`(${x.toFixed(2)}, ${y.toFixed(2)}, ${z.toFixed(2)})`);
    }
}

apply_transformation();