function calculate_altitude(): number {
    let a = 30000;
    let b = 200;
    let c = 1000;
    for (let i = 0; i < 5; i++) {
        a += b;
        b -= c;
        if (b <= 0) {
            break;
        }
    }
    return a;
}

calculate_altitude();