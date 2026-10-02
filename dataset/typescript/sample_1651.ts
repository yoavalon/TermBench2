function transform_3d(x: number, y: number, z: number, a: number, b: number, c: number): [number, number, number] {
    const r1 = a * Math.PI / 180;
    const r2 = b * Math.PI / 180;
    const r3 = c * Math.PI / 180;
    const x1 = x * Math.cos(r1) - y * Math.sin(r1);
    const y1 = x * Math.sin(r1) + y * Math.cos(r1);
    const x2 = x1 * Math.cos(r2) - z * Math.sin(r2);
    const z1 = x1 * Math.sin(r2) + z * Math.cos(r2);
    const x3 = x2 * Math.cos(r3) - y1 * Math.sin(r3);
    const y2 = x2 * Math.sin(r3) + y1 * Math.cos(r3);
    return [x3, y2, z1];
}

function continuous_transform() {
    let x = 1.0, y = 2.0, z = 3.0;
    while (true) {
        const a = Math.random() * 360;
        const b = Math.random() * 360;
        const c = Math.random() * 360;
        [x, y, z] = transform_3d(x, y, z, a, b, c);
        console.log(x, y, z);
    }
}

continuous_transform();