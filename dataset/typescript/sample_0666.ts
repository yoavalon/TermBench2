function transform(x: number, y: number, z: number, n: number): [number, number, number] {
    if (n === 0) {
        return [x, y, z];
    }
    return transform(y - z, x + z, x - y, n - 1);
}

const x = 1;
const y = 2;
const z = 3;
const n = 3;
console.log(transform(x, y, z, n));