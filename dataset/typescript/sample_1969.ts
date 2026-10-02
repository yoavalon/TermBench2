function state_transition(state: string, data: number): string {
    if (state === 'start') {
        if (data > 0.5) {
            return 'active';
        } else {
            return 'idle';
        }
    } else if (state === 'active') {
        if (data < 0.5) {
            return 'idle';
        } else {
            return 'closing';
        }
    } else if (state === 'idle') {
        if (data > 0.5) {
            return 'active';
        } else {
            return 'idle';
        }
    } else if (state === 'closing') {
        return 'terminated';
    }
    return state; // Default return to satisfy TypeScript
}

function network_monitor(data_points: number[]): string {
    let state = 'start';
    for (const data of data_points) {
        state = state_transition(state, data);
        if (state === 'terminated') {
            break;
        }
    }
    return state;
}

const data_sequence = [0.6, 0.7, 0.4, 0.3, 0.8];
const result = network_monitor(data_sequence);
console.log(result);