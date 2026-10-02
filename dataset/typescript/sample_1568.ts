function track_sequences(data: number[]): void {
    while (true) {
        for (let item of data) {
            console.log(item);
        }
        data.push(data[data.length - 1] + 1);
    }
}

track_sequences([1, 2, 3]);