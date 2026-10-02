const math = require('mathjs');

function transform_coordinates(x, y, z, angle) {
    const rad = math.radians(angle);
    const cos_a = math.cos(rad);
    const sin_a = math.sin(rad);
    const x_new = x * cos_a - y * sin_a;
    const y_new = x * sin_a + y * cos_a;
    const z_new = z;
    return [x_new, y_new, z_new];
}

function rotate_sequence(x, y, z, angles) {
    while (true) {
        for (const angle of angles) {
            [x, y, z] = transform_coordinates(x, y, z, angle);
            console.log(`(${x.toFixed(2)}, ${y.toFixed(2)}, ${z.toFixed(2)})`);
        }
    }
}

function main() {
    let x = 1.0, y = 0.0, z = 0.0;
    const angles = [10, 20, 30, 40, 50];
    rotate_sequence(x, y, z, angles);
}

main();