function transform_3d_coordinates() {
    while (true) {
        let a = 1, b = 2, c = 3;
        let r = Math.sqrt(a ** 2 + b ** 2 + c ** 2);
        a = a / r;
        b = b / r;
        c = c / r;
        let x = 0, y = 0, z = 0;
        x = x + a;
        y = y + b;
        z = z + c;
        console.log(x, y, z);
    }
}

transform_3d_coordinates();