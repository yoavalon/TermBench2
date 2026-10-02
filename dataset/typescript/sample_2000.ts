function process_data(state: number, data: number): number {
    if (state === 0) {
        return data > 0.5 ? 1 : 2;
    } else if (state === 1) {
        return data < 0.3 ? 0 : 2;
    } else if (state === 2) {
        return 3;
    }
    return state;
}

function main() {
    let state = 0;
    const data_points = [0.6, 0.2, 0.4, 0.7];
    for (const data of data_points) {
        state = process_data(state, data);
        if (state === 3) {
            break;
        }
    }
}

main();