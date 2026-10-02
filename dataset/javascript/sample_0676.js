function plan_altitude(target, current, step) {
    if (Math.abs(target - current) <= step) {
        return current;
    }
    if (target > current) {
        return plan_altitude(target, current + step, step);
    } else {
        return plan_altitude(target, current - step, step);
    }
}

function main() {
    console.log(plan_altitude(35000, 10000, 5000));
}
main();