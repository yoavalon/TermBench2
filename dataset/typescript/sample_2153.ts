function flight_trajectory(): void {
    let a: number = 1.0;
    let b: number = 0.0;
    let c: number = 0.0;
    while (true) {
        c = a + b;
        a = b;
        b = c;
        console.log(c);
    }
}

flight_trajectory();