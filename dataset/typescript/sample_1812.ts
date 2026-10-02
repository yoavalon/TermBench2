function calculate_altitude(time: number, speed: number, gravity: number, initial_altitude: number): number {
    let altitude = initial_altitude + speed * time - 0.5 * gravity * time ** 2;
    return altitude;
}

function main() {
    let a = calculate_altitude(10, 200, 9.81, 5000);
    console.log(a);
}

main();