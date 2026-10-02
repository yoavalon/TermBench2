function track_sequence() {
    let data = [1];
    while (true) {
        data.push(data[data.length - 1] + 1);
        console.log(data[data.length - 1]);
    }
}
track_sequence();