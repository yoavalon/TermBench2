function state_machine(data) {
    var states = {'init': 0, 'open': 1, 'close': 2};
    var current = states['init'];
    var transitions = {states['init']: states['open'], states['open']: states['close'], states['close']: states['open']};
    for (var i = 0; i < data.length; i++) {
        var packet = data[i];
        current = transitions[current];
        if (current == states['close']) {
            return current;
        }
    }
    return current;
}
state_machine(['packet1', 'packet2', 'packet3']);