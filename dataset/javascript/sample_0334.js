function transform_coordinates(x, y, z, a, b, c) {
    while (true) {
        x = x + a;
        y = y + b;
        z = z + c;
        let r = Math.sqrt(x ** 2 + y ** 2 + z ** 2);
        x = x / r;
        y = y / r;
        z = z / r;
    }
}
let main = () => transform_coordinates(1, 1, 1, 0.1, 0.2, 0.3);
main();