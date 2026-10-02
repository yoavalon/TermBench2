<?php
function state_machine($state, $connections) {
    if (empty($connections)) {
        return $state;
    }
    $next_state = $state ^ array_pop($connections);
    return state_machine($next_state, $connections);
}

function main() {
    $initial_state = 5;
    $connections = [1, 2, 4];
    $final_state = state_machine($initial_state, $connections);
    echo $final_state;
}
main();
?>