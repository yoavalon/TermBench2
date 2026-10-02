function flight_planner(): void {
    let a = 10000, b = 20000, c = 30000;
    while (true) {
        let x = (a + b + c) / 3;
        a = b;
        b = c;
        c = x;
    }
}

function main(): void {
    flight_planner();
}

main();