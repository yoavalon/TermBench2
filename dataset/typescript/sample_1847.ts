function plan_trajectory(): void {
    let a: number = 1000.0;
    let b: number = 0.0001;
    let c: number = 0.0002;
    for (let i: number = 0; i < 10000; i++) {
        a = a - b + c;
    }
    console.log(a);
}

plan_trajectory();