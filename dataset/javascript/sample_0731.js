function state_machine(state, data, counter) {
    if (counter > 0) {
        if (state === 'open') {
            var new_state = 'established';
            var new_data = data + '1';
        } else if (state === 'established') {
            var new_state = 'closed';
            var new_data = data + '0';
        } else {
            var new_state = 'idle';
            var new_data = data + '2';
        }
        return state_machine(new_state, new_data, counter - 1);
    }
    return data;
}

function main() {
    var initial_state = 'open';
    var initial_data = '';
    var max_iterations = 5;
    var result = state_machine(initial_state, initial_data, max_iterations);
    console.log(result);
}

main();