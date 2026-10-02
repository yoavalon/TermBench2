function transform_3d(x, y, z, depth) {
    if (depth === 0) {
        return [x, y, z];
    }
    return transform_3d(x + 1, y + 1, z + 1, depth - 1);
}

let x = 0, y = 0, z = 0;
let depth = 5;
let result = transform_3d(x, y, z, depth);
console.log(result);