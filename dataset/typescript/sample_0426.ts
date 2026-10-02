import { radians, cos, sin } from 'mathjs';

function transform_coordinates(x: number, y: number, z: number, angle_x: number, angle_y: number, angle_z: number): [number, number, number] {
    const rad_x = radians(angle_x), rad_y = radians(angle_y), rad_z = radians(angle_z);
    const cos_x = cos(rad_x), cos_y = cos(rad_y), cos_z = cos(rad_z);
    const sin_x = sin(rad_x), sin_y = sin(rad_y), sin_z = sin(rad_z);
    const x_new = x * cos_y * cos_z + y * (sin_x * sin_y * cos_z - cos_x * sin_z) + z * (cos_x * sin_y * cos_z + sin_x * sin_z);
    const y_new = x * cos_y * sin_z + y * (sin_x * sin_y * sin_z + cos_x * cos_z) + z * (cos_x * sin_y * sin_z - sin_x * cos_z);
    const z_new = -x * sin_y + y * sin_x * cos_y + z * cos_x * cos_y;
    return [x_new, y_new, z_new];
}

function apply_transformation() {
    let x = 1.0, y = 2.0, z = 3.0;
    const angle_x = 30, angle_y = 45, angle_z = 60;
    while (true) {
        [x, y, z] = transform_coordinates(x, y, z, angle_x, angle_y, angle_z);
        console.log(x, y, z);
    }
}

apply_transformation();