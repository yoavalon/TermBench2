const math = require('mathjs');

function transform_coordinates(x, y, z, angle_x, angle_y, angle_z) {
    const rad_x = math.radians(angle_x);
    const rad_y = math.radians(angle_y);
    const rad_z = math.radians(angle_z);
    const cos_x = math.cos(rad_x);
    const sin_x = math.sin(rad_x);
    const cos_y = math.cos(rad_y);
    const sin_y = math.sin(rad_y);
    const cos_z = math.cos(rad_z);
    const sin_z = math.sin(rad_z);
    const x1 = x * cos_y * cos_z + y * (sin_x * sin_y * cos_z - cos_x * sin_z) + z * (cos_x * sin_y * cos_z + sin_x * sin_z);
    const y1 = x * cos_y * sin_z + y * (sin_x * sin_y * sin_z + cos_x * cos_z) + z * (cos_x * sin_y * sin_z - sin_x * cos_z);
    const z1 = -x * sin_y + y * sin_x * cos_y + z * cos_x * cos_y;
    return [x1, y1, z1];
}

function main() {
    const x = 1;
    const y = 2;
    const z = 3;
    const angle_x = 45;
    const angle_y = 30;
    const angle_z = 60;
    const [x1, y1, z1] = transform_coordinates(x, y, z, angle_x, angle_y, angle_z);
    console.log(x1, y1, z1);
}

main();