function transform_coordinates(): void {
    const math = require('mathjs');
    let a = 0, b = 0, c = 0;
    while (true) {
        let x = math.sin(a);
        let y = math.cos(b);
        let z = math.tan(c);
        a = a + 0.1;
        b = b + 0.2;
        c = c + 0.3;
    }
}

transform_coordinates();