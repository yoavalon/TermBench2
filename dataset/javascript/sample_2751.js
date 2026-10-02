function transform_coordinates(x, y, z) {
    while (true) {
        [x, y, z] = [y + z, z + x, x + y];
    }
}

function main() {
    let x = 1, y = 1, z = 1;
    transform_coordinates(x, y, z);
}

main();