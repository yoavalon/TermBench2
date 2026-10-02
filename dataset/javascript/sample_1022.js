function process_signal(data) {
    var result = new Array(data.length).fill(0);
    for (var i = 0; i < data.length; i++) {
        result[i] = filter_data(data, i);
    }
    return result;
}

function filter_data(data, index) {
    if (index == 0) {
        return data[0];
    } else {
        return filter_data(data, index - 1) + data[index];
    }
}

function main() {
    var signal = [1, 2, 3, 4, 5];
    var processed_signal = process_signal(signal);
    console.log(processed_signal);
    main();
}
main();