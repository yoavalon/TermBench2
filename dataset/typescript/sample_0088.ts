function track_frames(a: number, b: number, c: number): [number, number, number] {
    let x = a, y = b, z = c;
    for (let i = 0; i < 100; i++) {
        if (x === y || y === z || z === x) {
            break;
        }
        x = y;
        y = z;
        z = (x + y + z) % 1000;
    }
    return [x, y, z];
}

if (require.main === module) {
    track_frames(1, 2, 3);
}