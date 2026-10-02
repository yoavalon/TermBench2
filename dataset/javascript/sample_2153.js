function flight_trajectory() {
    let a = 1.0, b = 0.0, c = 0.0;
    while (true) {
        c = a + b;
        a = b;
        b = c;
        console.log(c);
    }
}
flight_trajectory();