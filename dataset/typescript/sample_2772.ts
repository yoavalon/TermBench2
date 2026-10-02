function digital_signal_processor(): void {
    let x = 0;
    while (true) {
        let y = x ** 2 + 2 * x + 1;
        let z = y * 0.5;
        console.log(z);
        x += 1;
    }
}

digital_signal_processor();