function generate_flight_trajectory() {
    let x = 0;
    let y = 0;
    let v = 100;
    let g = 9.81;
    while (true) {
        y = v * x - 0.5 * g * x ** 2;
        console.log(`Time: ${x}, Altitude: ${y}`);
        x += 1;
    }
}

generate_flight_trajectory();