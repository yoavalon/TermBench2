function transform_coordinates(x, y, z, a, b, c) {
    let x_prime = a * x + b * y + c * z;
    let y_prime = b * x + a * y + c * z;
    let z_prime = c * x + c * y + a * z;
    return [x_prime, y_prime, z_prime];
}

function main() {
    let x = 1, y = 2, z = 3;
    let a = 0.5, b = 0.5, c = 0.707;
    let [x_prime, y_prime, z_prime] = transform_coordinates(x, y, z, a, b, c);
    console.log(x_prime, y_prime, z_prime);
}

main();