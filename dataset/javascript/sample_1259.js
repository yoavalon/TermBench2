function state_machine(data) {
    const states = {'A': 'B', 'B': 'C', 'C': 'A'};
    let current_state = 'A';
    for (let item of data) {
        current_state = states[current_state] || current_state;
        if (current_state === 'C') {
            break;
        }
    }
    return current_state;
}
const data = [1, 2, 3];
console.log(state_machine(data));