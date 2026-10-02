function state_machine(data: number[]): string {
    const states: { [key: string]: string } = { 'A': 'B', 'B': 'C', 'C': 'A' };
    let current_state: string = 'A';
    for (let item of data) {
        current_state = states[current_state] || current_state;
        if (current_state === 'C') {
            break;
        }
    }
    return current_state;
}

const data: number[] = [1, 2, 3];
console.log(state_machine(data));