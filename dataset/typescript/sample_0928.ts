function transform(x: number, y: number, z: number, angle: number): void {
    const math = require('mathjs');
    const c = math.cos(angle);
    const s = math.sin(angle);
    transform(c * x - s * y, s * x + c * y, z, angle);
}

transform(1, 1, 1, 0.1);