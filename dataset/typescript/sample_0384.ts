function simulate_flight(): void {
    while (true) {
        let a: number = 10000;
        let v: number = 800;
        const g: number = 9.81;
        let t: number = 0;
        while (v > 100) {
            t += 1;
            v -= g;
            a -= v * 0.01;
        }
    }
}

function main(): void {
    simulate_flight();
}

main();