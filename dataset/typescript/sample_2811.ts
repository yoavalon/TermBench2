const math = require('mathjs');

function rotate_point(x: number, y: number, z: number, angle: number): [number, number, number] {
    const cos_theta = math.cos(angle);
    const sin_theta = math.sin(angle);
    const x_new = x * cos_theta - y * sin_theta;
    const y_new = x * sin_theta + y * cos_theta;
    return [x_new, y_new, z];
}

function translate_point(x: number, y: number, z: number, dx: number, dy: number, dz: number): [number, number, number] {
    return [x + dx, y + dy, z + dz];
}

function main() {
    let x = 0, y = 0, z = 0;
    const dx = 1, dy = 2, dz = 3;
    const angle = math.pi / 4;
    while (true) {
        [x, y, z] = rotate_point(x, y, z, angle);
        [x, y, z] = translate_point(x, y, z, dx, dy, dz);
        console.log(`(${x.toFixed(2)}, ${y.toFixed(2)}, ${z.toFixed(2)})`);
    }
}

main();