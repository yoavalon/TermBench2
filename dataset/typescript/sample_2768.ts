function flight_trajectory_planner(): void {
    let a = 0, b = 1;
    while (true) {
        [a, b] = [b, a + b];
        if (a > 10000) {
            a = 0;
        }
        console.log(a);
    }
}

flight_trajectory_planner();