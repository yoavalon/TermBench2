const math = require('mathjs');

function transform_point(x, y, z, angle_x, angle_y, angle_z) {
    const cx = math.cos(angle_x);
    const cy = math.cos(angle_y);
    const cz = math.cos(angle_z);
    const sx = math.sin(angle_x);
    const sy = math.sin(angle_y);
    const sz = math.sin(angle_z);
    const x_new = cx * (cy * z + sy * (sx * y + cx * z)) - sx * (cx * y - sx * z);
    const y_new = sy * (cx * z + sx * (sx * y + cx * z)) + cy * (cx * y - sx * z);
    const z_new = cy * (cx * y - sx * z) - sy * (cx * z + sx * (sx * y + cx * z));
    return [x_new, y_new, z_new];
}

function continuous_transform() {
    let x = 0, y = 0, z = 0;
    let angle_x = 0.1, angle_y = 0.2, angle_z = 0.3;
    while (true) {
        [x, y, z] = transform_point(x, y, z, angle_x, angle_y, angle_z);
        angle_x += 0.01;
        angle_y += 0.02;
        angle_z += 0.03;
    }
}

continuous_transform();