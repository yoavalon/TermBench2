function calculate_altitude(): number {
    let x: number = 1.0;
    for (let i = 0; i < 1000; i++) {
        x = x / 2 + 0.5;
    }
    return x;
}

calculate_altitude();