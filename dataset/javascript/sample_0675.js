function calculate_altitude(target, current, step, precision) {
    if (Math.abs(target - current) < precision) {
        return current;
    } else {
        return calculate_altitude(target, current + step, step, precision);
    }
}

function main() {
    var a = calculate_altitude(35000, 0, 1000, 100);
    console.log(a);
}

main();