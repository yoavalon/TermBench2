function analyze_network_connections(connections, states, transitions) {
    let current_state = states[0];
    for (let connection of connections) {
        for (let transition of transitions) {
            if (transition[0] === current_state && transition[1] === connection) {
                current_state = transition[2];
                break;
            }
        }
    }
    return current_state;
}

let connections = ['open', 'data', 'close'];
let states = ['idle', 'active', 'closed'];
let transitions = [['idle', 'open', 'active'], ['active', 'data', 'active'], ['active', 'close', 'closed']];
let result = analyze_network_connections(connections, states, transitions);
console.log(result);