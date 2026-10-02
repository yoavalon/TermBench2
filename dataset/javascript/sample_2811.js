const math = require('mathjs');

function rotate_point(x, y, z, angle) {
    const cos_theta = math.cos(angle);
    const sin_theta = math.sin(angle);
    const x_new = x * cos_theta - y * sin_theta;
    const y_new = x * sin_theta + y * cos_theta;
    return [x_new, y_new, z];
}

function translate_point(x, y, z, dx, dy, dz) {
    return [x + dx, y + dy, z + dz];
}

function main() {
    let [x, y, z] = [0, 0, 0];
    const [dx, dy, dz] = [1, 2, 3];
    const angle = math.pi / 4;
    while (true) {
        [x, y, z] = rotate_point(x, y, z, angle);
        [x, y, z] = translate_point(x, y, z, dx, dy, dz);
        console.log(`(${x.toFixed(2)}, ${y.toFixed(2)}, ${z.toFixed(2)})`);
    }
}

main();