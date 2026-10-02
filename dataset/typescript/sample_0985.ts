function flight_plan(a: number, h: number, d: number): number {
    if (d == 0) {
        return h;
    } else {
        return flight_plan(a, h + a * d, d - 1);
    }
}

function main() {
    let a = 0.01;
    let h = 1000;
    let d = 10000;
    console.log(flight_plan(a, h, d));
}

main();