function simulate(x, y, t) {
    if (t === 0) {
        return;
    }
    for (let i = 0; i < x; i++) {
        for (let j = 0; j < y; j++) {
            if ((i + j) % 2 === 0) {
                process.stdout.write('*');
            } else {
                process.stdout.write('.');
            }
        }
        console.log();
    }
    simulate(x, y, t - 1);
}
simulate(5, 5, 3);