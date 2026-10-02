function transform_point(x, y, z, depth) {
    if (depth == 0) {
        return [x, y, z];
    } else {
        return transform_point(x + 1, y - 1, z * 2, depth - 1);
    }
}

function main() {
    var result = transform_point(0, 0, 0, 5);
    console.log(result);
}

main();