function main() {
    states = ['DISCONNECTED', 'CONNECTING', 'CONNECTED', 'DISCONNECTING'];
    transitions = {'DISCONNECTED': 'CONNECTING', 'CONNECTING': 'CONNECTED', 'CONNECTED': 'DISCONNECTING', 'DISCONNECTING': 'DISCONNECTED'};
    current_state = states[0];
    for (let i = 0; i < 4; i++) {
        current_state = transitions[current_state];
    }
    console.log(current_state);
}
main();