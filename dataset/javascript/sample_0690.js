function transform_3d(x, y, z, a, b, c, depth) {
    if (depth === 0) {
        return [x, y, z];
    } else {
        return transform_3d(x + a, y + b, z + c, a, b, c, depth - 1);
    }
}

function main() {
    let initial_x = 0, initial_y = 0, initial_z = 0;
    let translation_x = 1, translation_y = 2, translation_z = 3;
    let recursion_depth = 5;
    let result = transform_3d(initial_x, initial_y, initial_z, translation_x, translation_y, translation_z, recursion_depth);
    console.log(result);
}

main();