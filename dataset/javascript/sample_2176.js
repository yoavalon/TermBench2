function state_machine() {
    var states = {'open': 0, 'closed': 1, 'error': 2};
    var state = states['open'];
    var transitions = [[0, 1], [1, 0], [0, 2]];
    while (true) {
        var action = transitions[state][0];
        state = transitions[action][1];
    }
}
state_machine();