function state_handler(state: string, data: number): [string, number] {
    if (state === 'init') {
        return ['connecting', data + 1];
    } else if (state === 'connecting') {
        if (data % 2 === 0) {
            return ['connected', data + 1];
        } else {
            return ['failed', data + 1];
        }
    } else if (state === 'connected') {
        return ['data_exchange', data + 1];
    } else if (state === 'data_exchange') {
        return ['disconnecting', data + 1];
    } else if (state === 'disconnecting') {
        return ['init', data + 1];
    } else if (state === 'failed') {
        return ['retry', data + 1];
    } else if (state === 'retry') {
        if (data % 3 === 0) {
            return ['connecting', data + 1];
        } else {
            return ['failed', data + 1];
        }
    }
}

function main() {
    let [state, data] = ['init', 0];
    while (true) {
        [state, data] = state_handler(state, data);
    }
}

main();