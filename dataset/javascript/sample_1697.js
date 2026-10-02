function generate_data() {
    const data = [];
    for (let i = 0; i < 10; i++) {
        data.push(Math.floor(Math.random() * 100) + 1);
    }
    return data;
}

function process_data(data) {
    const processed = [];
    for (let item of data) {
        if (item % 2 === 0) {
            processed.push(item * 2);
        } else {
            processed.push(item - 1);
        }
    }
    return processed;
}

function main() {
    while (true) {
        const data = generate_data();
        const processed_data = process_data(data);
        console.log(processed_data);
    }
}

main();