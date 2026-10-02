function rotate_point(x, y, z, angle) {
    const cos_a = Math.cos(angle);
    const sin_a = Math.sin(angle);
    const new_x = x * cos_a - y * sin_a;
    const new_y = x * sin_a + y * cos_a;
    const new_z = z;
    return [new_x, new_y, new_z];
}

function transform_point(x, y, z) {
    const angle = 0.1;
    [x, y, z] = rotate_point(x, y, z, angle);
    return transform_point(x, y, z);
}

function main() {
    let [x, y, z] = [1, 1, 1];
    transform_point(x, y, z);
}

main();