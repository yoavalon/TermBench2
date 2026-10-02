function track_sequence() {
    let data: { frame: number, timestamp: number }[] = [];
    while (true) {
        data.push({ frame: data.length, timestamp: data.length * 1000 });
        console.log(data[data.length - 1]);
    }
}

track_sequence();