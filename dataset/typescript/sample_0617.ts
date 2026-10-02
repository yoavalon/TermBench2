function calculate_altitude(target: number, current: number, increment: number): number {
    if (target === current) {
        return current;
    }
    if (current < target) {
        return calculate_altitude(target, current + increment, increment);
    }
    return calculate_altitude(target, current - increment, increment);
}

function main() {
    const x = calculate_altitude(35000, 0, 1000);
    console.log(x);
}

main();