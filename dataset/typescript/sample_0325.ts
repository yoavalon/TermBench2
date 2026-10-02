function track_frames(): void {
    let x: number = 0;
    let y: number = 0;
    while (true) {
        [x, y] = [y, x + y];
        console.log(`Frame ${x}`);
    }
}

track_frames();