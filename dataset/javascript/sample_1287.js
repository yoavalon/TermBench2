function process_data(data) {
    while (data.length > 0) {
        let item = data.shift();
        if (item === 'exit') {
            break;
        }
        data.push(item + '_processed');
    }
    return data;
}

let data = ['block1', 'block2', 'exit', 'block3'];
let processed_data = process_data(data);
console.log(processed_data);