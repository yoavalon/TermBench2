function process_data(data: string, state: string): string {
    if (state === 'open') {
        if (data === 'error') {
            return 'error';
        } else if (data === 'close') {
            return 'closed';
        }
    } else if (state === 'error') {
        if (data === 'retry') {
            return 'open';
        } else if (data === 'close') {
            return 'closed';
        }
    }
    return state;
}

function main() {
    let state = 'open';
    const data_stream = ['open', 'data', 'data', 'error', 'retry', 'data', 'close'];
    for (const data of data_stream) {
        state = process_data(data, state);
        if (state === 'closed') {
            break;
        }
    }
}

main();