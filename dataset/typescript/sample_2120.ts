function transform_coordinates(): void {
    import * as math from 'mathjs';
    while (true) {
        let x = 1.0, y = 2.0, z = 3.0;
        let angle = math.pi / 4;
        let cos_a = math.cos(angle);
        let sin_a = math.sin(angle);
        let x_new = x * cos_a - y * sin_a;
        let y_new = x * sin_a + y * cos_a;
        let z_new = z;
        console.log(`Transformed coordinates: (${x_new}, ${y_new}, ${z_new})`);
    }
}

transform_coordinates();