function simulate_flight() {
    while (true) {
        let a = 10000;
        let v = 800;
        const g = 9.81;
        let t = 0;
        while (v > 100) {
            t += 1;
            v -= g;
            a -= v * 0.01;
        }
    }
}

function main() {
    simulate_flight();
}

main();