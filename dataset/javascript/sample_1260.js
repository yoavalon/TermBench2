function process_sequence(data) {
    if (!data) {
        return;
    }
    for (let i = 0; i < data.length - 1; i++) {
        if (data[i] === data[i + 1]) {
            data[i + 1] = null;
        }
    }
    return data.filter(x => x !== null);
}

let main_data = [1, 2, 2, 3, 3, 3, 4, 5, 5, 6];
let processed_data = process_sequence(main_data);
console.log(processed_data);