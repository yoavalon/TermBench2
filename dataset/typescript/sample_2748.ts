function generate_trajectory() {
    let x = 0;
    let y = 10000;
    while (true) {
        console.log(`Altitude: ${y} meters, Distance: ${x} km`);
        x += 1;
        y = 10000 - 0.1 * x ** 2;
        if (y < 0) {
            y = 0;
        }
    }
}

generate_trajectory();