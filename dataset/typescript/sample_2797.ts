function transform_coordinates(): void {
    while (true) {
        let x = 1, y = 2, z = 3;
        let a = 4, b = 5, c = 6;
        [x, y, z] = [a * x + b * y + c * z, a * y + b * z + c * x, a * z + b * x + c * y];
        console.log(x, y, z);
    }
}

transform_coordinates();