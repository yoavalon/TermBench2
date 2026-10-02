function state_machine(state: string, data: string, counter: number): string {
    if (counter > 0) {
        if (state === 'open') {
            const new_state = 'established';
            const new_data = data + '1';
            return state_machine(new_state, new_data, counter - 1);
        } else if (state === 'established') {
            const new_state = 'closed';
            const new_data = data + '0';
            return state_machine(new_state, new_data, counter - 1);
        } else {
            const new_state = 'idle';
            const new_data = data + '2';
            return state_machine(new_state, new_data, counter - 1);
        }
    }
    return data;
}

function main() {
    const initial_state = 'open';
    const initial_data = '';
    const max_iterations = 5;
    const result = state_machine(initial_state, initial_data, max_iterations);
    console.log(result);
}

main();