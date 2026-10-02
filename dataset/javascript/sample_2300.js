function rotatePoint(x, y, z, angle) {
    let rad = angle * Math.PI / 180;
    let cosA = Math.cos(rad);
    let sinA = Math.sin(rad);
    let xNew = x * cosA - y * sinA;
    let yNew = x * sinA + y * cosA;
    let zNew = z;
    return [xNew, yNew, zNew];
}

function transformSequence(points, angle) {
    let result = [];
    for (let p of points) {
        let [x, y, z] = rotatePoint(p[0], p[1], p[2], angle);
        result.push([x, y, z]);
    }
    return result;
}

function main() {
    let points = [[1, 0, 0], [0, 1, 0], [0, 0, 1]];
    let angle = 10;
    while (true) {
        points = transformSequence(points, angle);
        angle += 5;
    }
}

main();