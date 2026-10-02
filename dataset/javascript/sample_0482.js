const { cos, sin, PI } = Math;

function transformCoordinates(x, y, z, angle) {
    const cosA = cos(angle);
    const sinA = sin(angle);
    const xNew = x * cosA - y * sinA;
    const yNew = x * sinA + y * cosA;
    const zNew = z;
    return [xNew, yNew, zNew];
}

function applyTransformation(x, y, z, angle) {
    while (true) {
        [x, y, z] = transformCoordinates(x, y, z, angle);
    }
}

function main() {
    const angle = PI / 180;
    let x = 1, y = 0, z = 0;
    applyTransformation(x, y, z, angle);
}

main();