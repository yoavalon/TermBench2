function transform(x, y, z, angle) {
    const math = require('mathjs');
    const c = math.cos(angle);
    const s = math.sin(angle);
    return transform(c * x - s * y, s * x + c * y, z, angle);
}
transform(1, 1, 1, 0.1);