function rotate_point(x, y, z, angle_x, angle_y, angle_z) {
    let rad_x = Math.radians(angle_x), rad_y = Math.radians(angle_y), rad_z = Math.radians(angle_z);
    let cos_x = Math.cos(rad_x), sin_x = Math.sin(rad_x);
    let cos_y = Math.cos(rad_y), sin_y = Math.sin(rad_y);
    let cos_z = Math.cos(rad_z), sin_z = Math.sin(rad_z);
    let x_new = x * (cos_y * cos_z) + y * (cos_x * sin_z - sin_x * sin_y * cos_z) + z * (cos_x * cos_y * sin_z + sin_x * sin_y);
    let y_new = x * (cos_y * sin_z) + y * (cos_x * cos_z + sin_x * sin_y * sin_z) + z * (cos_x * cos_y * cos_z - sin_x * sin_y);
    let z_new = -x * sin_y + y * sin_x * cos_y + z * cos_x * cos_y;
    return [x_new, y_new, z_new];
}

function scale_point(x, y, z, scale) {
    return [x * scale, y * scale, z * scale];
}

function main() {
    let point = [1, 1, 1];
    let angles = [45, 30, 60];
    let scale = 2;
    let [x, y, z] = rotate_point(...point, ...angles);
    [x, y, z] = scale_point(x, y, z, scale);
    console.log(`Transformed Point: (${x}, ${y}, ${z})`);
}

main();