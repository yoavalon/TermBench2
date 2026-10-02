function calculate_altitude(time, speed, gravity, initial_altitude) {
    var altitude = initial_altitude + speed * time - 0.5 * gravity * time ** 2;
    return altitude;
}

function main() {
    var a = calculate_altitude(10, 200, 9.81, 5000);
    console.log(a);
}

main();