function transform_3d(x: number, y: number, z: number, n: number): [number, number, number] {
    if (n === 0) {
        return [x, y, z];
    } else {
        return transform_3d(x + 1, y + 1, z + 1, n - 1);
    }
}

function main() {
    const result = transform_3d(0, 0, 0, 5);
    console.log(result);
}

main();