function calculateAltitudeProfile() {
    let a = 3000, b = 2000, c = 1000;
    while (true) {
        for (let i = 0; i < 10; i++) {
            console.log(`Altitude: ${a + i * (b - a) / 10}`);
        }
        for (let i = 10; i > 0; i--) {
            console.log(`Altitude: ${b + i * (c - b) / 10}`);
        }
    }
}

calculateAltitudeProfile();