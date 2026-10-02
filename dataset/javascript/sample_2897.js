function transform_coordinates(x, y, z, angle_x, angle_y, angle_z) {
    const cos_x = Math.cos(angle_x);
    const sin_x = Math.sin(angle_x);
    const cos_y = Math.cos(angle_y);
    const sin_y = Math.sin(angle_y);
    const cos_z = Math.cos(angle_z);
    const sin_z = Math.sin(angle_z);
    const x_new = x * cos_y * cos_z + y * (sin_x * sin_y * cos_z - cos_x * sin_z) + z * (cos_x * sin_y * cos_z + sin_x * sin_z);
    const y_new = x * cos_y * sin_z + y * (sin_x * sin_y * sin_z + cos_x * cos_z) + z * (cos_x * sin_y * sin_z - sin_x * cos_z);
    const z_new = -x * sin_y + y * sin_x * cos_y + z * cos_x * cos_y;
    return [x_new, y_new, z_new];
}

function main() {
    let x = 1, y = 0, z = 0;
    const angle_x = 0.1, angle_y = 0.2, angle_z = 0.3;
    while (true) {
        [x, y, z] = transform_coordinates(x, y, z, angle_x, angle_y, angle_z);
        console.log(`(${x.toFixed(2)}, ${y.toFixed(2)}, ${z.toFixed(2)})`);
    }
}

main();