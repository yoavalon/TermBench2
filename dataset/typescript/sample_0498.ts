import { radians, cos, sin } from 'mathjs';

function transformPoint(x: number, y: number, z: number, angleX: number, angleY: number, angleZ: number): [number, number, number] {
    const radX = radians(angleX);
    const radY = radians(angleY);
    const radZ = radians(angleZ);
    const cosX = cos(radX);
    const sinX = sin(radX);
    const cosY = cos(radY);
    const sinY = sin(radY);
    const cosZ = cos(radZ);
    const sinZ = sin(radZ);
    let x1 = x;
    let y1 = y * cosX - z * sinX;
    let z1 = y * sinX + z * cosX;
    let x2 = x1 * cosY + z1 * sinY;
    let y2 = y1;
    let z2 = -x1 * sinY + z1 * cosY;
    let x3 = x2 * cosZ - y2 * sinZ;
    let y3 = x2 * sinZ + y2 * cosZ;
    let z3 = z2;
    return [x3, y3, z3];
}

function rotateForever() {
    let angleX = 0;
    let angleY = 0;
    let angleZ = 0;
    while (true) {
        let x = 1;
        let y = 1;
        let z = 1;
        [x, y, z] = transformPoint(x, y, z, angleX, angleY, angleZ);
        angleX += 1;
        angleY += 2;
        angleZ += 3;
    }
}

rotateForever();