const math = require('mathjs');

function transform_point(x, y, z, angle_x, angle_y, angle_z) {
    const cos_x = math.cos(angle_x);
    const sin_x = math.sin(angle_x);
    const cos_y = math.cos(angle_y);
    const sin_y = math.sin(angle_y);
    const cos_z = math.cos(angle_z);
    const sin_z = math.sin(angle_z);
    const x_new = cos_y * (cos_z * x + sin_z * y) + sin_y * z;
    const y_new = cos_x * (sin_y * (cos_z * x + sin_z * y) - cos_y * z) - sin_x * (sin_z * x - cos_z * y);
    const z_new = sin_x * (sin_y * (cos_z * x + sin_z * y) - cos_y * z) + cos_x * (sin_z * x - cos_z * y);
    return [x_new, y_new, z_new];
}

function continuous_rotation() {
    let x = 0, y = 0, z = 0;
    let angle_x = 0, angle_y = 0, angle_z = 0;
    const increment = 0.01;
    while (true) {
        angle_x += increment;
        angle_y += increment;
        angle_z += increment;
        [x, y, z] = transform_point(x, y, z, angle_x, angle_y, angle_z);
    }
}

function main() {
    continuous_rotation();
}

main();