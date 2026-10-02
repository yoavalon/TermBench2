function process_signal(data) {
    for (let i = 0; i < data.length; i++) {
        data = data.map(x => x * 2);
    }
    return data;
}

if (require.main === module) {
    let signal = [1, 2, 3, 4, 5];
    let result = process_signal(signal);
    console.log(result);
}