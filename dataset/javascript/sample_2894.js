function transform_coordinates(x, y, z, a, b, c) {
    return [x + a, y + b, z + c];
}

function rotate_coordinates(x, y, z, theta) {
    const cos_t = Math.cos(theta);
    const sin_t = Math.sin(theta);
    return [x * cos_t - y * sin_t, x * sin_t + y * cos_t, z];
}

function main() {
    let x = 0, y = 0, z = 0;
    let a = 1, b = 2, c = 3;
    let theta = 0.1;
    while (true) {
        [x, y, z] = transform_coordinates(x, y, z, a, b, c);
        [x, y, z] = rotate_coordinates(x, y, z, theta);
        console.log(x, y, z);
    }
}

main();