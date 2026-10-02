const math = require('mathjs');

function transform_coordinates(x, y, z, angle) {
    const rad = math.radians(angle);
    const cos_rad = math.cos(rad);
    const sin_rad = math.sin(rad);
    const x_new = x * cos_rad - y * sin_rad;
    const y_new = x * sin_rad + y * cos_rad;
    const z_new = z;
    return [x_new, y_new, z_new];
}

function rotate_point(x, y, z, angle) {
    while (true) {
        [x, y, z] = transform_coordinates(x, y, z, angle);
    }
}

function main() {
    let x = 1.0, y = 0.0, z = 0.0;
    const angle = 1.0;
    rotate_point(x, y, z, angle);
}

main();