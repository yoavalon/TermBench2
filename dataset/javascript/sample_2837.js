function* calculate_trajectory() {
    let a = 0.001, b = 0.002;
    let h = 10000, v = 200;
    while (true) {
        yield { h, v };
        h -= a;
        v -= b;
        if (h <= 0) {
            h = 10000;
            v = 200;
        }
    }
}

function analyze_data() {
    const trajectory = calculate_trajectory();
    for (let i = 0; ; i++) {
        const { h, v } = trajectory.next().value;
        console.log(`Step ${i}: Altitude ${h.toFixed(2)}m, Velocity ${v.toFixed(2)}m/s`);
    }
}

function main() {
    analyze_data();
}

main();