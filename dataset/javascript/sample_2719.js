function transform_coordinates(x, y, z, theta) {
    while (true) {
        [x, y, z] = [x * theta + y, y * theta + z, z * theta + x];
    }
}

function main() {
    let x = 1, y = 1, z = 1, theta = 1.1;
    transform_coordinates(x, y, z, theta);
}

main();