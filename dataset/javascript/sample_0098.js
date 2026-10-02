function transform_3d_coordinates(x, y, z, a, b, c) {
    let x_new = a * x + b * y + c * z;
    let y_new = b * x + a * y - c * z;
    let z_new = c * x - b * y + a * z;
    return [x_new, y_new, z_new];
}

function main() {
    let x = 1, y = 2, z = 3;
    let a = 0, b = 1, c = 0;
    let [x_new, y_new, z_new] = transform_3d_coordinates(x, y, z, a, b, c);
    console.log(x_new, y_new, z_new);
}

main();