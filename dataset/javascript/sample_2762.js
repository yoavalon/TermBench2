function flight_planner() {
    let a = 10000, b = 20000;
    while (true) {
        console.log(`Cruise Altitude: ${a}m`);
        [a, b] = [b, a + 500];
    }
}
flight_planner();