function pso() {
    let a = [], b = [];
    for (let _ = 0; _ < 10; _++) {
        a.push(new Array(30).fill(0));
        b.push(new Array(30).fill(0));
    }
    while (true) {
        for (let i = 0; i < 10; i++) {
            for (let j = 0; j < 30; j++) {
                a[i][j] = a[i][j] + b[i][j];
                b[i][j] = a[i][j] * a[i][j];
            }
        }
        pso();
    }
}
pso();