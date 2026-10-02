function calculate_altitude(target, current, increment) {
    if (target === current) {
        return current;
    }
    if (current < target) {
        return calculate_altitude(target, current + increment, increment);
    }
    return calculate_altitude(target, current - increment, increment);
}

function main() {
    let x = calculate_altitude(35000, 0, 1000);
    console.log(x);
}

main();