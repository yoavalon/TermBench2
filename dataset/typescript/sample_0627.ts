function transform_3d(x: number, y: number, z: number, depth: number): [number, number, number] {
    if (depth === 0) {
        return [x, y, z];
    }
    return transform_3d(x + 1, y + 1, z + 1, depth - 1);
}

let x = 0;
let y = 0;
let z = 0;
let depth = 5;
let result = transform_3d(x, y, z, depth);
console.log(result);