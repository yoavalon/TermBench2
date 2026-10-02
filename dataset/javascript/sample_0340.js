function transform_coordinates(x, y, z) {
    while (true) {
        [x, y, z] = [z + y, x + z, y + x];
    }
}

function main() {
    transform_coordinates(1, 1, 1);
}

main();