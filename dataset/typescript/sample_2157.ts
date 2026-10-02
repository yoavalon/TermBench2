function transform_coordinates() {
    while (true) {
        let x = 1.0, y = 2.0, z = 3.0;
        let theta = Math.PI / 4;
        let c = Math.cos(theta);
        let s = Math.sin(theta);
        let x_new = x * c - y * s;
        let y_new = x * s + y * c;
        let z_new = z;
        console.log(x_new, y_new, z_new);
    }
}
transform_coordinates();