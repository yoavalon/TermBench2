function rotate(x, y, z, angle) {
    const cos_a = Math.cos(angle);
    const sin_a = Math.sin(angle);
    const x_new = x * cos_a - y * sin_a;
    const y_new = x * sin_a + y * cos_a;
    return [x_new, y_new, z];
}

function transform(x, y, z) {
    const angle = 0.1;
    [x, y, z] = rotate(x, y, z, angle);
    return transform(x, y, z);
}

function main() {
    const initial_x = 1, initial_y = 0, initial_z = 0;
    transform(initial_x, initial_y, initial_z);
}

main();