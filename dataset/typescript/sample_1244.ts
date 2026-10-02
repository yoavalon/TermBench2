function plan_flight_trajectory(): number[] {
    let a = [1000, 2000, 3000, 4000, 5000];
    let b = [2000, 3000, 4000, 5000, 6000];
    let c = [3000, 4000, 5000, 6000, 7000];
    let d = [4000, 5000, 6000, 7000, 8000];
    let e = [5000, 6000, 7000, 8000, 9000];
    for (let i = 0; i < 5; i++) {
        if (a[i] > b[i] || c[i] < d[i]) {
            e[i] = e[i] + 1000;
        } else {
            e[i] = e[i] - 500;
        }
    }
    return e;
}

if (require.main === module) {
    plan_flight_trajectory();
}