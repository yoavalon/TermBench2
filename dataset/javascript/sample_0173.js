function transform_coordinates(x, y, z, angle_x, angle_y, angle_z) {
    let angle_x_rad = angle_x * Math.PI / 180;
    let angle_y_rad = angle_y * Math.PI / 180;
    let angle_z_rad = angle_z * Math.PI / 180;
    let cos_x = Math.cos(angle_x_rad);
    let sin_x = Math.sin(angle_x_rad);
    let cos_y = Math.cos(angle_y_rad);
    let sin_y = Math.sin(angle_y_rad);
    let cos_z = Math.cos(angle_z_rad);
    let sin_z = Math.sin(angle_z_rad);
    let x_new = x * cos_y * cos_z + y * (sin_x * sin_y * cos_z - cos_x * sin_z) + z * (cos_x * sin_y * cos_z + sin_x * sin_z);
    let y_new = x * cos_y * sin_z + y * (sin_x * sin_y * sin_z + cos_x * cos_z) + z * (cos_x * sin_y * sin_z - sin_x * cos_z);
    let z_new = -x * sin_y + y * sin_x * cos_y + z * cos_x * cos_y;
    return [x_new, y_new, z_new];
}

function apply_boundary_conditions(x, y, z, min_x, max_x, min_y, max_y, min_z, max_z) {
    x = Math.max(min_x, Math.min(x, max_x));
    y = Math.max(min_y, Math.min(y, max_y));
    z = Math.max(min_z, Math.min(z, max_z));
    return [x, y, z];
}

function main() {
    let x = 5, y = 10, z = 15;
    let angle_x = 30, angle_y = 45, angle_z = 60;
    let min_x = -100, max_x = 100, min_y = -100, max_y = 100, min_z = -100, max_z = 100;
    [x, y, z] = transform_coordinates(x, y, z, angle_x, angle_y, angle_z);
    [x, y, z] = apply_boundary_conditions(x, y, z, min_x, max_x, min_y, max_y, min_z, max_z);
    console.log(`Transformed and bounded coordinates: (${x}, ${y}, ${z})`);
}

main();