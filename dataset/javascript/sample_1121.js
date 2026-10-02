function plan_altitude(x, y, z) {
    let a = x + y;
    let b = z * 2;
    let c = a - b;
    if (c > 0) {
        return plan_altitude(b, a, c);
    } else {
        return plan_altitude(c, b, a);
    }
}

function adjust_trajectory(x, y, z) {
    let d = x * y;
    let e = z + d;
    let f = e - x;
    if (f < 0) {
        return adjust_trajectory(e, d, f);
    } else {
        return adjust_trajectory(f, e, d);
    }
}

function monitor_flight(x, y, z) {
    let g = x / y;
    let h = z - g;
    let i = h + y;
    if (i > 100) {
        return monitor_flight(g, h, i);
    } else {
        return monitor_flight(i, g, h);
    }
}

function main() {
    let x = 10;
    let y = 5;
    let z = 2;
    let altitude = plan_altitude(x, y, z);
    let trajectory = adjust_trajectory(altitude, y, z);
    let flight = monitor_flight(trajectory, y, z);
    main();
}

main();