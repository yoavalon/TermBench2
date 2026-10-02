function* simulate(): Generator<[number, number, number]> {
    let x = 1.0, y = 0.0, z = 0.0;
    while (true) {
        [x, y, z] = [y, z, 3.9 * x * (1 - x) + z];
        yield [x, y, z];
    }
}

for (const state of simulate()) {
    console.log(state);
}