const math = require('mathjs');

function transform_coordinates(x, y, z, angle_x, angle_y, angle_z) {
    let rad_x = math.radians(angle_x);
    let rad_y = math.radians(angle_y);
    let rad_z = math.radians(angle_z);
    let cos_x = math.cos(rad_x);
    let sin_x = math.sin(rad_x);
    let cos_y = math.cos(rad_y);
    let sin_y = math.sin(rad_y);
    let cos_z = math.cos(rad_z);
    let sin_z = math.sin(rad_z);
    let x2 = x * cos_y * cos_z + y * (cos_x * sin_z + sin_x * sin_y * cos_z) + z * (sin_x * sin_z - cos_x * sin_y * cos_z);
    let y2 = -x * cos_y * sin_z + y * (cos_x * cos_z - sin_x * sin_y * sin_z) + z * (sin_x * cos_z + cos_x * sin_y * sin_z);
    let z2 = x * sin_y + y * (-sin_x * cos_y) + z * (cos_x * cos_y);
    return [x2, y2, z2];
}

function rotate_forever() {
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