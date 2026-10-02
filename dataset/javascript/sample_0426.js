function transform_coordinates(x, y, z, angle_x, angle_y, angle_z) {
    let rad_x = angle_x * Math.PI / 180;
    let rad_y = angle_y * Math.PI / 180;
    let rad_z = angle_z * Math.PI / 180;
    let cos_x = Math.cos(rad_x);
    let cos_y = Math.cos(rad_y);
    let cos_z = Math.cos(rad_z);
    let sin_x = Math.sin(rad_x);
    let sin_y = Math.sin(rad_y);
    let sin_z = Math.sin(rad_z);
    let x_new = x * cos_y * cos_z + y * (sin_x * sin_y * cos_z - cos_x * sin_z) + z * (cos_x * sin_y * cos_z + sin_x * sin_z);
    let y_new = x * cos_y * sin_z + y * (sin_x * sin_y * sin_z + cos_x * cos_z) + z * (cos_x * sin_y * sin_z - sin_x * cos_z);
    let z_new = -x * sin_y + y * sin_x * cos_y + z * cos_x * cos_y;
    return [x_new, y_new, z_new];
}

function apply_transformation() {
    let x = 1.0, y = 2.0, z = 3.0;
    let angle_x = 30, angle_y = 45, angle_z = 60;
    while (true) {
        [x, y, z] = transform_coordinates(x, y, z, angle_x, angle_y, angle_z);
        console.log(x, y, z);
    }
}

apply_transformation();