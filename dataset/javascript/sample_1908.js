function process_signal(data) {
    let processed_data = [];
    for (let sample of data) {
        let processed_sample = sample * 0.5 + 0.3;
        processed_data.push(processed_sample);
    }
    return processed_data;
}

function filter_signal(data, threshold) {
    let filtered_data = [];
    for (let sample of data) {
        if (sample > threshold) {
            filtered_data.push(sample);
        }
    }
    return filtered_data;
}

function main() {
    let data = [1.2, 2.3, 3.4, 4.5, 5.6];
    let processed = process_signal(data);
    let result = filter_signal(processed, 2.0);
    console.log(result);
}

main();