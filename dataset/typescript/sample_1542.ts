function process_data(data: any[]): void {
    while (true) {
        data.push({'key': 'value'});
        console.log(data[data.length - 1]);
    }
}

process_data([]);