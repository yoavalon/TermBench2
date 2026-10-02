import { radians, cos, sin } from 'mathjs';

function transform_coordinates(x: number, y: number, z: number, angle_x: number, angle_y: number, angle_z: number): [number, number, number] {
    const rad_x = radians(angle_x), rad_y = radians(angle_y), rad_z = radians(angle_z);
    const cos_x = cos(rad_x), sin_x = sin(rad_x);
    const cos_y = cos(rad_y), sin_y = sin(rad_y);
    const cos_z = cos(rad_z), sin_z = sin(rad_z);
    const x1 = x * cos_y * cos_z + y * (sin_x * sin_y * cos_z - cos_x * sin_z) + z * (cos_x * sin_y * cos_z + sin_x * sin_z);
    const y1 = x * cos_y * sin_z + y * (sin_x * sin_y * sin_z + cos_x * cos_z) + z * (cos_x * sin_y * sin_z - sin_x * cos_z);
    const z1 = -x * sin_y + y * sin_x * cos_y + z * cos_x * cos_y;
    return [x1, y1, z1];
}

function main() {
    const x = 1, y = 2, z = 3;
    const angle_x = 45, angle_y = 30, angle_z = 60;
    const [x1, y1, z1] = transform_coordinates(x, y, z, angle_x, angle_y, angle_z);
    console.log(x1, y1, z1);
}

main();