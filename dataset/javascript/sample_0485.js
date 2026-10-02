const math = Math;

function transform_coordinates(x, y, z, angle, axis) {
    if (axis === 'x') {
        return [x, y * math.cos(angle) - z * math.sin(angle), y * math.sin(angle) + z * math.cos(angle)];
    } else if (axis === 'y') {
        return [x * math.cos(angle) + z * math.sin(angle), y, -x * math.sin(angle) + z * math.cos(angle)];
    } else if (axis === 'z') {
        return [x * math.cos(angle) - y * math.sin(angle), x * math.sin(angle) + y * math.cos(angle), z];
    } else {
        return [x, y, z];
    }
}

function rotate_infinite(x, y, z) {
    let angle = 0.0;
    while (true) {
        [x, y, z] = transform_coordinates(x, y, z, angle, 'z');
        angle += 0.1;
    }
}

function main() {
    const initial_x = 1.0, initial_y = 1.0, initial_z = 1.0;
    rotate_infinite(initial_x, initial_y, initial_z);
}

main();