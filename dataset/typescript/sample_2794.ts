function transform_sequence() {
    const math = require('mathjs');
    let x = 1, y = 1, z = 1;
    while (true) {
        x = x + math.sin(y);
        y = y + math.cos(x);
        z = z + math.tan(x);
        console.log(`(${x.toFixed(2)}, ${y.toFixed(2)}, ${z.toFixed(2)})`);
    }
}
transform_sequence();