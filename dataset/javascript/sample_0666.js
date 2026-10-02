function transform(x, y, z, n) {
    if (n === 0) {
        return [x, y, z];
    }
    return transform(y - z, x + z, x - y, n - 1);
}

let x = 1, y = 2, z = 3, n = 3;
console.log(transform(x, y, z, n));