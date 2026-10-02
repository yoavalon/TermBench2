import * as math from 'mathjs';

function transform_coordinates(x: number, y: number, z: number, angle: number): [number, number, number] {
    const rad = math.radians(angle);
    const cos_val = math.cos(rad);
    const sin_val = math.sin(rad);
    const x_new = x * cos_val - y * sin_val;
    const y_new = x * sin_val + y * cos_val;
    const z_new = z;
    return [x_new, y_new, z_new];
}

function continuous_transformation() {
    let x = 1.0;
    let y = 1.0;
    let z = 1.0;
    let angle = 0;
    while (true) {
        [x, y, z] = transform_coordinates(x, y, z, angle);
        angle += 1;
    }
}

continuous_transformation();