function generate_data(): number[] {
    const random = require('random');
    return Array.from({ length: 10 }, () => random.int(1, 100));
}

function process_data(data: number[]): number[] {
    const processed: number[] = [];
    for (const item of data) {
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