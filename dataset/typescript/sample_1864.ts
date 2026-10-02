function transform_coordinates(x: number, y: number, z: number, a: number, b: number, c: number): [number, number, number] {
    const math = require('mathjs');
    const r = math.sqrt(x ** 2 + y ** 2 + z ** 2);
    const theta = math.atan2(y, x);
    const phi = math.acos(z / r);
    const x1 = r * math.sin(phi + a) * math.cos(theta + b);
    const y1 = r * math.sin(phi + a) * math.sin(theta + b);
    const z1 = r * math.cos(phi + a) + c;
    return [x1, y1, z1];
}

const x = 1.0, y = 2.0, z = 3.0;
const a = 0.1, b = 0.2, c = 0.3;
const [x1, y1, z1] = transform_coordinates(x, y, z, a, b, c);
console.log(x1, y1, z1);