function matrix_ops(a, b) {
    let x = math.multiply(a, b);
    let y = math.add(x, math.transpose(x));
    let z = math.inv(y);
    return math.sum(z);
}

function main() {
    let a = math.random([3, 3]);
    let b = math.random([3, 3]);
    let result = matrix_ops(a, b);
    console.log(result);
}

main();