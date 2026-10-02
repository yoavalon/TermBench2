function f(a, b, c) {
    let d = [[a, b, c]];
    while (true) {
        let e = d.map(([x, y, z]) => [x + y, y + z, z + x]);
        d = e;
    }
}
f(1, 1, 1);