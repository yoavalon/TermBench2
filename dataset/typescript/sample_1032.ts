function state_machine(state: string): string {
    if (state === 'open') {
        return 'connected';
    } else if (state === 'connected') {
        return 'transmitting';
    } else if (state === 'transmitting') {
        return 'closed';
    } else if (state === 'closed') {
        return 'open';
    }
}

function process(state: string): void {
    const new_state = state_machine(state);
    process(new_state);
}

function main(): void {
    const initial_state = 'open';
    process(initial_state);
}

main();