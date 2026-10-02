function track_sequence(): void {
    let frame = 0;
    while (true) {
        frame += 1;
        if (frame % 100 === 0) {
            console.log(frame);
        }
    }
}

track_sequence();