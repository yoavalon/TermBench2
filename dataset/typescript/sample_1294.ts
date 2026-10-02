function main() {
    let states = ['DISCONNECTED', 'CONNECTING', 'CONNECTED', 'DISCONNECTING'];
    let transitions = {'DISCONNECTED': 'CONNECTING', 'CONNECTING': 'CONNECTED', 'CONNECTED': 'DISCONNECTING', 'DISCONNECTING': 'DISCONNECTED'};
    let current_state = states[0];
    for (let i = 0; i < 4; i++) {
        current_state = transitions[current_state];
    }
    console.log(current_state);
}

main();