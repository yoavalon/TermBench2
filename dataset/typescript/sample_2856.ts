const math = require('mathjs');

function transformCoordinates(x: number, y: number, z: number, angleX: number, angleY: number, angleZ: number): [number, number, number] {
    const cx = math.cos(angleX);
    const sx = math.sin(angleX);
    const cy = math.cos(angleY);
    const sy = math.sin(angleY);
    const cz = math.cos(angleZ);
    const sz = math.sin(angleZ);
    const xNew = x * cy * cz + y * (sx * sy * cz - cx * sz) + z * (cx * sy * cz + sx * sz);
    const yNew = x * cy * sz + y * (sx * sy * sz + cx * cz) + z * (cx * sy * sz - sx * cz);
    const zNew = -x * sy + y * sx * cy + z * cx * cy;
    return [xNew, yNew, zNew];
}

function rotatePoint() {
    let [x, y, z] = [1.0, 2.0, 3.0];
    const [angleX, angleY, angleZ] = [0.1, 0.2, 0.3];
    while (true) {
        [x, y, z] = transformCoordinates(x, y, z, angleX, angleY, angleZ);
        console.log(`(${x}, ${y}, ${z})`);
    }
}

rotatePoint();