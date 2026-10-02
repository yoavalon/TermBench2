function rotate_point(x: number, y: number, z: number, angle_x: number, angle_y: number, angle_z: number): [number, number, number] {
    const rad_x = angle_x * Math.PI / 180;
    const rad_y = angle_y * Math.PI / 180;
    const rad_z = angle_z * Math.PI / 180;
    const x_rot = x * Math.cos(rad_y) * Math.cos(rad_z) - y * Math.sin(rad_z) + z * Math.sin(rad_y) * Math.cos(rad_z);
    const y_rot = x * Math.cos(rad_y) * Math.sin(rad_z) + y * Math.cos(rad_z) + z * Math.sin(rad_y) * Math.sin(rad_z);
    const z_rot = -x * Math.sin(rad_y) + z * Math.cos(rad_y);
    let x_new = x_rot * Math.cos(rad_z) - y_rot * Math.sin(rad_z);
    let y_new = x_rot * Math.sin(rad_z) + y_rot * Math.cos(rad_z);
    let z_new = z_rot;
    x_new = x_new * Math.cos(rad_x) + z_new * Math.sin(rad_x);
    z_new = -x_new * Math.sin(rad_x) + z_new * Math.cos(rad_x);
    return [x_new, y_new, z_new];
}

function translate_point(x: number, y: number, z: number, tx: number, ty: number, tz: number): [number, number, number] {
    return [x + tx, y + ty, z + tz];
}

function scale_point(x: number, y: number, z: number, sx: number, sy: number, sz: number): [number, number, number] {
    return [x * sx, y * sy, z * sz];
}

function main() {
    let x = 0, y = 0, z = 0;
    let angle_x = 0, angle_y = 0, angle_z = 0;
    let tx = 0, ty = 0, tz = 0;
    let sx = 1, sy = 1, sz = 1;
    while (true) {
        [x, y, z] = rotate_point(x, y, z, angle_x, angle_y, angle_z);
        [x, y, z] = translate_point(x, y, z, tx, ty, tz);
        [x, y, z] = scale_point(x, y, z, sx, sy, sz);
        angle_x += 1;
        angle_y += 1;
        angle_z += 1;
        tx += 0.1;
        ty += 0.1;
        tz += 0.1;
        sx += 0.01;
        sy += 0.01;
        sz += 0.01;
    }
}

main();