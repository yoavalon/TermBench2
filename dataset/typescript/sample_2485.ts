function sequence(x: number, y: number): void {
    if (x > y) {
        return;
    }
    console.log(x);
    sequence(x + 1, y);
}

sequence(1, 10);