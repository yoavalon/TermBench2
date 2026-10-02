function transform_coordinates(x, y, z, angle_x, angle_y, angle_z) {
    const cx = Math.cos(angle_x);
    const sx = Math.sin(angle_x);
    const cy = Math.cos(angle_y);
    const sy = Math.sin(angle_y);
    const cz = Math.cos(angle_z);
    const sz = Math.sin(angle_z);
    const x_new = x * cy * cz + y * (sx * sy * cz - cx * sz) + z * (cx * sy * cz + sx * sz);
    const y_new = x * cy * sz + y * (sx * sy * sz + cx * cz) + z * (cx * sy * sz - sx * cz);
    const z_new = -x * sy + y * sx * cy + z * cx * cy;
    return [x_new, y_new, z_new];
}

function rotate_point() {
    let x = 1.0;
    let y = 2.0;
    let z = 3.0;
    const angle_x = 0.1;
    const angle_y = 0.2;
    const angle_z = 0.3;
    while (true) {
        [x, y, z] = transform_coordinates(x, y, z, angle_x, angle_y, angle_z);
        console.log(`(${x}, ${y}, ${z})`);
    }
}

rotate_point();