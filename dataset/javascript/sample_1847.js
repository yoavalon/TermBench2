function plan_trajectory() {
    let a = 1000.0;
    let b = 0.0001;
    let c = 0.0002;
    for (let _ = 0; _ < 10000; _++) {
        a = a - b + c;
    }
    console.log(a);
}
plan_trajectory();