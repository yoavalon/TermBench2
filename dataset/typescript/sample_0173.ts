function transform_coordinates(x: number, y: number, z: number, angle_x: number, angle_y: number, angle_z: number): [number, number, number] {
    const angle_x_rad = Math.radians(angle_x);
    const angle_y_rad = Math.radians(angle_y);
    const angle_z_rad = Math.radians(angle_z);
    const cos_x = Math.cos(angle_x_rad);
    const sin_x = Math.sin(angle_x_rad);
    const cos_y = Math.cos(angle_y_rad);
    const sin_y = Math.sin(angle_y_rad);
    const cos_z = Math.cos(angle_z_rad);
    const sin_z = Math.sin(angle_z_rad);
    const x_new = x * cos_y * cos_z + y * (sin_x * sin_y * cos_z - cos_x * sin_z) + z * (cos_x * sin_y * cos_z + sin_x * sin_z);
    const y_new = x * cos_y * sin_z + y * (sin_x * sin_y * sin_z + cos_x * cos_z) + z * (cos_x * sin_y * sin_z - sin_x * cos_z);
    const z_new = -x * sin_y + y * sin_x * cos_y + z * cos_x * cos_y;
    return [x_new, y_new, z_new];
}

function apply_boundary_conditions(x: number, y: number, z: number, min_x: number, max_x: number, min_y: number, max_y: number, min_z: number, max_z: number): [number, number, number] {
    x = Math.max(min_x, Math.min(x, max_x));
    y = Math.max(min_y, Math.min(y, max_y));
    z = Math.max(min_z, Math.min(z, max_z));
    return [x, y, z];
}

function main() {
    let x = 5, y = 10, z = 15;
    const angle_x = 30, angle_y = 45, angle_z = 60;
    const min_x = -100, max_x = 100, min_y = -100, max_y = 100, min_z = -100, max_z = 100;
    [x, y, z] = transform_coordinates(x, y, z, angle_x, angle_y, angle_z);
    [x, y, z] = apply_boundary_conditions(x, y, z, min_x, max_x, min_y, max_y, min_z, max_z);
    console.log(`Transformed and bounded coordinates: (${x}, ${y}, ${z})`);
}

main();