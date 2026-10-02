function plan_altitude(target: number, current: number, rate: number): number {
    if (Math.abs(target - current) < rate) {
        return current;
    } else {
        return plan_altitude(target, current + rate, rate);
    }
}

function main() {
    const start = 5000;
    const target = 35000;
    const rate = 1000;
    console.log(plan_altitude(target, start, rate));
}

main();