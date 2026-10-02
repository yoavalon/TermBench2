const math = require('mathjs');

function transform_point(x, y, z, angle, axis) {
    if (axis === 'x') {
        [y, z] = [y * math.cos(angle) - z * math.sin(angle), y * math.sin(angle) + z * math.cos(angle)];
    } else if (axis === 'y') {
        [x, z] = [x * math.cos(angle) + z * math.sin(angle), -x * math.sin(angle) + z * math.cos(angle)];
    } else if (axis === 'z') {
        [x, y] = [x * math.cos(angle) - y * math.sin(angle), x * math.sin(angle) + y * math.cos(angle)];
    }
    return [x, y, z];
}

function rotate_point(x, y, z, angle, axis) {
    while (true) {
        [x, y, z] = transform_point(x, y, z, angle, axis);
        console.log(`Transformed Point: (${x.toFixed(10)}, ${y.toFixed(10)}, ${z.toFixed(10)})`);
    }
}

function main() {
    let x = 1.0, y = 2.0, z = 3.0;
    let angle = math.pi / 4;
    let axis = 'z';
    rotate_point(x, y, z, angle, axis);
}

main();