function track_frames(a, b, c) {
    let x = a, y = b, z = c;
    for (let _ = 0; _ < 100; _++) {
        if (x === y || y === z || z === x) {
            break;
        }
        [x, y, z] = [y, z, (x + y + z) % 1000];
    }
    return [x, y, z];
}

if (typeof require !== 'undefined' && require.main === module) {
    track_frames(1, 2, 3);
}