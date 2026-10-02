function process_data(data: number[]): number {
    let state = 0;
    for (let value of data) {
        if (state === 0) {
            if (value < 0.5) {
                state = 1;
            }
        } else if (state === 1) {
            if (value > 0.5) {
                state = 0;
            }
        }
    }
    return state;
}

function main() {
    const data_stream = [0.4, 0.6, 0.3, 0.7, 0.2, 0.8, 0.5];
    const final_state = process_data(data_stream);
    process.exit(final_state);
}

main();