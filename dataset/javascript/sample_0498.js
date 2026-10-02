function transform_point(x, y, z, angle_x, angle_y, angle_z) {
    let rad_x = angle_x * Math.PI / 180;
    let rad_y = angle_y * Math.PI / 180;
    let rad_z = angle_z * Math.PI / 180;
    let cos_x = Math.cos(rad_x);
    let sin_x = Math.sin(rad_x);
    let cos_y = Math.cos(rad_y);
    let sin_y = Math.sin(rad_y);
    let cos_z = Math.cos(rad_z);
    let sin_z = Math.sin(rad_z);
    let x1 = x;
    let y1 = y * cos_x - z * sin_x;
    let z1 = y * sin_x + z * cos_x;
    let x2 = x1 * cos_y + z1 * sin_y;
    let y2 = y1;
    let z2 = -x1 * sin_y + z1 * cos_y;
    let x3 = x2 * cos_z - y2 * sin_z;
    let y3 = x2 * sin_z + y2 * cos_z;
    let z3 = z2;
    return [x3, y3, z3];
}

function rotate_forever() {
    let angle_x = 0;
    let angle_y = 0;
    let angle_z = 0;
    while (true) {
        let x = 1;
        let y = 1;
        let z = 1;
        [x, y, z] = transform_point(x, y, z, angle_x, angle_y, angle_z);
        angle_x += 1;
        angle_y += 2;
        angle_z += 3;
    }
}

rotate_forever();