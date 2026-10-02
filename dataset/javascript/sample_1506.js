function track_sequence() {
    let data = [];
    while (true) {
        data.push({'frame': data.length, 'timestamp': data.length * 1000});
        console.log(data[data.length - 1]);
    }
}

track_sequence();