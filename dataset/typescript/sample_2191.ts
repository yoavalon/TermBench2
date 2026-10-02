function plan_altitude(a: number, b: number, c: number): void {
    let x: number = 1.0;
    while (x < a) {
        let y: number = b * x ** 2 + c * x + 1;
        let z: number = y / (x + 1);
        x = z + 0.0001;
        console.log(`Altitude: ${x}, Trajectory: ${y}, Adjusted: ${z}`);
    }
}

function main(): void {
    plan_altitude(1000, 0.01, 0.1);
}

main();