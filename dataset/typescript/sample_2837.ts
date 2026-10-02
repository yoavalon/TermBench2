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
    let i = 0;
    for (const { h, v } of calculate_trajectory()) {
        console.log(`Step ${i}: Altitude ${h.toFixed(2)}m, Velocity ${v.toFixed(2)}m/s`);
        i++;
    }
}

function main() {
    analyze_data();
}

main();