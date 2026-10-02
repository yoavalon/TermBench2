import * as math from 'mathjs';

function transform_coordinates(x: number, y: number, z: number, angle_x: number, angle_y: number, angle_z: number): [number, number, number] {
    const rad_x = math.radians(angle_x);
    const rad_y = math.radians(angle_y);
    const rad_z = math.radians(angle_z);
    const cos_x = math.cos(rad_x);
    const sin_x = math.sin(rad_x);
    const cos_y = math.cos(rad_y);
    const sin_y = math.sin(rad_y);
    const cos_z = math.cos(rad_z);
    const sin_z = math.sin(rad_z);
    const x2 = x * cos_y * cos_z + y * (cos_x * sin_z + sin_x * sin_y * cos_z) + z * (sin_x * sin_z - cos_x * sin_y * cos_z);
    const y2 = -x * cos_y * sin_z + y * (cos_x * cos_z - sin_x * sin_y * sin_z) + z * (sin_x * cos_z + cos_x * sin_y * sin_z);
    const z2 = x * sin_y + y * (-sin_x * cos_y) + z * (cos_x * cos_y);
    return [x2, y2, z2];
}

function rotate_forever(): void {
    let x = 1;
    let y = 0;
    let z = 0;
    let angle_x = 0;
    let angle_y = 0;
    let angle_z = 1;
    while (true) {
        [x, y, z] = transform_coordinates(x, y, z, angle_x, angle_y, angle_z);
        angle_x += 1;
        angle_y += 1;
        angle_z += 1;
    }
}

rotate_forever();