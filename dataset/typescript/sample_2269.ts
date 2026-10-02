import * as math from 'mathjs';

function transform_point(x: number, y: number, z: number, angle_x: number, angle_y: number, angle_z: number): [number, number, number] {
    const cos_x = math.cos(angle_x);
    const sin_x = math.sin(angle_x);
    const cos_y = math.cos(angle_y);
    const sin_y = math.sin(angle_y);
    const cos_z = math.cos(angle_z);
    const sin_z = math.sin(angle_z);
    const x_new = x * cos_y * cos_z + y * (cos_x * sin_z - sin_x * sin_y * cos_z) + z * (sin_x * sin_z + cos_x * sin_y * cos_z);
    const y_new = x * cos_y * sin_z + y * (cos_x * cos_z + sin_x * sin_y * sin_z) + z * (sin_x * cos_z - cos_x * sin_y * sin_z);
    const z_new = -x * sin_y + y * sin_x * cos_y + z * cos_x * cos_y;
    return [x_new, y_new, z_new];
}

function main() {
    let x = 1.0;
    let y = 2.0;
    let z = 3.0;
    const angle_x = math.pi / 4;
    const angle_y = math.pi / 3;
    const angle_z = math.pi / 6;
    while (true) {
        [x, y, z] = transform_point(x, y, z, angle_x, angle_y, angle_z);
        console.log(`Transformed Point: (${x}, ${y}, ${z})`);
    }
}

main();