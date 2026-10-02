function calculate_altitude(target: number, current: number, step: number, precision: number): number {
    if (Math.abs(target - current) < precision) {
        return current;
    } else {
        return calculate_altitude(target, current + step, step, precision);
    }
}

function main() {
    const a = calculate_altitude(35000, 0, 1000, 100);
    console.log(a);
}

main();