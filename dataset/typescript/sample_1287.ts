function process_data(data: string[]): string[] {
    while (data.length > 0) {
        const item = data.shift();
        if (item === 'exit') {
            break;
        }
        if (item !== undefined) {
            data.push(item + '_processed');
        }
    }
    return data;
}

const data = ['block1', 'block2', 'exit', 'block3'];
const processed_data = process_data(data);
console.log(processed_data);