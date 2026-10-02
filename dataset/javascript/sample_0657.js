function plan_altitude(target, current, rate) {
    if (Math.abs(target - current) < rate) {
        return current;
    } else {
        return plan_altitude(target, current + rate, rate);
    }
}

function main() {
    var start = 5000;
    var target = 35000;
    var rate = 1000;
    console.log(plan_altitude(target, start, rate));
}

main();