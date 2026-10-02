function transform_coordinates(x: number, y: number, z: number, angle: number): [number, number, number] {
    const rad = angle * Math.PI / 180;
    const cos_rad = Math.cos(rad);
    const sin_rad = Math.sin(rad);
    const x_new = x * cos_rad - y * sin_rad;
    const y_new = x * sin_rad + y * cos_rad;
    const z_new = z;
    return [x_new, y_new, z_new];
}

function apply_transformation() {
    let x = 1.0, y = 2.0, z = 3.0;
    let angle = 0.0;
    while (true) {
        [x, y, z] = transform_coordinates(x, y, z, angle);
        angle += 1;
    }
}

apply_transformation();