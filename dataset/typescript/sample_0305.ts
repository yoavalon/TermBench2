function track_sequence(): void {
    let x: number = 0;
    let y: number = 1;
    while (true) {
        console.log(x, y);
        [x, y] = [y, x + y];
    }
}

track_sequence();