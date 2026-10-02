function analyze_network_connections(connections: string[], states: string[], transitions: [string, string, string][]): string {
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

const connections = ['open', 'data', 'close'];
const states = ['idle', 'active', 'closed'];
const transitions = [['idle', 'open', 'active'], ['active', 'data', 'active'], ['active', 'close', 'closed']];
const result = analyze_network_connections(connections, states, transitions);
console.log(result);