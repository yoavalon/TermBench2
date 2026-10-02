function transform_coordinates(x, y, z, angle) {
    let rad = angle * Math.PI / 180;
    let cos_rad = Math.cos(rad);
    let sin_rad = Math.sin(rad);
    let x_new = x * cos_rad - y * sin_rad;
    let y_new = x * sin_rad + y * cos_rad;
    let z_new = z;
    return [x_new, y_new, z_new];
}

function continuous_transform(x, y, z, angle_increment) {
    while (true) {
        [x, y, z] = transform_coordinates(x, y, z, angle_increment);
        console.log(`(${x}, ${y}, ${z})`);
    }
}

function main() {
    let x = 1.0, y = 0.0, z = 0.0;
    let angle_increment = 5.0;
    continuous_transform(x, y, z, angle_increment);
}

main();