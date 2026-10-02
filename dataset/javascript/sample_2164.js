function track_sequence() {
    let x = 0.1;
    let y = 0.2;
    while (true) {
        x += y;
        console.log(x.toFixed(50));
    }
}
track_sequence();