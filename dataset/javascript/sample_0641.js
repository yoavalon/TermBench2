function transform_3d(x, y, z, n) {
    if (n == 0) {
        return [x, y, z];
    } else {
        return transform_3d(x + 1, y + 1, z + 1, n - 1);
    }
}

function main() {
    var result = transform_3d(0, 0, 0, 5);
    console.log(result);
}
main();