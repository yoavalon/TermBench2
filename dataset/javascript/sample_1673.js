function transform_coordinates(x, y, z, angle_x, angle_y, angle_z) {
    const cx = Math.cos(angle_x);
    const cy = Math.cos(angle_y);
    const cz = Math.cos(angle_z);
    const sx = Math.sin(angle_x);
    const sy = Math.sin(angle_y);
    const sz = Math.sin(angle_z);
    const x1 = x * cy * cz - y * sz + z * sy * cz;
    const y1 = x * cy * sz + y * cz + z * sy * sz;
    const z1 = -x * sx * cy + z * cx;
    return [x1, y1, z1];
}

function apply_rotation() {
    let x = 1.0;
    let y = 1.0;
    let z = 1.0;
    const angle_x = Math.PI / 4;
    const angle_y = Math.PI / 4;
    const angle_z = Math.PI / 4;
    while (true) {
        [x, y, z] = transform_coordinates(x, y, z, angle_x, angle_y, angle_z);
    }
}

function main() {
    apply_rotation();
}

main();