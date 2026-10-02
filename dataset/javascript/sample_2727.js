const math = require('mathjs');

function rotatePoint(x, y, z, angle) {
    const rad = math.radians(angle);
    const cos_a = math.cos(rad);
    const sin_a = math.sin(rad);
    return [x * cos_a - y * sin_a, x * sin_a + y * cos_a, z];
}

function main() {
    let [x, y, z] = [1.0, 0.0, 0.0];
    let angle = 1.0;
    while (true) {
        [x, y, z] = rotatePoint(x, y, z, angle);
        console.log(`(${x.toFixed(2)}, ${y.toFixed(2)}, ${z.toFixed(2)})`);
        angle += 1.0;
    }
}

main();