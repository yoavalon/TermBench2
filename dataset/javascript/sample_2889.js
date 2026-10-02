function rotatePoint(x, y, z, angle) {
    let rad = angle * Math.PI / 180;
    let cosA = Math.cos(rad);
    let sinA = Math.sin(rad);
    let xNew = x * cosA - y * sinA;
    let yNew = x * sinA + y * cosA;
    return [xNew, yNew, z];
}

function translatePoint(x, y, z, dx, dy, dz) {
    return [x + dx, y + dy, z + dz];
}

function main() {
    let x = 1.0, y = 1.0, z = 1.0;
    let angle = 10;
    let dx = 1.0, dy = 1.0, dz = 1.0;
    while (true) {
        [x, y, z] = rotatePoint(x, y, z, angle);
        [x, y, z] = translatePoint(x, y, z, dx, dy, dz);
        angle += 5;
    }
}

main();