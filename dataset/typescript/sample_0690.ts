function transform_3d(x: number, y: number, z: number, a: number, b: number, c: number, depth: number): [number, number, number] {
    if (depth === 0) {
        return [x, y, z];
    } else {
        return transform_3d(x + a, y + b, z + c, a, b, c, depth - 1);
    }
}

function main() {
    const initial_x = 0;
    const initial_y = 0;
    const initial_z = 0;
    const translation_x = 1;
    const translation_y = 2;
    const translation_z = 3;
    const recursion_depth = 5;
    const result = transform_3d(initial_x, initial_y, initial_z, translation_x, translation_y, translation_z, recursion_depth);
    console.log(result);
}

main();