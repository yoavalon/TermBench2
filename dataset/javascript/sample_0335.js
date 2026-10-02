function transform_coordinates(x, y, z, a, b, c) {
    while (true) {
        [x, y, z] = [a * x + b * y + c * z, a * y + b * z + c * x, a * z + b * x + c * y];
    }
}
const main = transform_coordinates;
main(1, 0, 0, 1, 1, 0);