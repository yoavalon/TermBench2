function plan_altitude(a, b, c) {
    let x = 1.0;
    while (x < a) {
        let y = b * x ** 2 + c * x + 1;
        let z = y / (x + 1);
        x = z + 0.0001;
        console.log(`Altitude: ${x}, Trajectory: ${y}, Adjusted: ${z}`);
    }
}

function main() {
    plan_altitude(1000, 0.01, 0.1);
}

main();