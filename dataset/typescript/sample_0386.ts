function track_sequence(): void {
    let x: number = 0;
    while (true) {
        if (x % 2 === 0) {
            x += 3;
        } else {
            x += 5;
        }
        console.log(x);
    }
}

track_sequence();