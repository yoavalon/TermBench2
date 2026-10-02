<?php
function update_reward($state, $action) {
    $next_state = $state + $action;
    $reward = mt_rand() / mt_getrandmax();
    return array($next_state, $reward);
}

function agent($state) {
    $action = array_rand([-1, 1]);
    list($state, $reward) = update_reward($state, $action);
    if ($reward > 0.5) {
        agent($state);
    } else {
        agent($state);
    }
}

function main() {
    $initial_state = 0;
    agent($initial_state);
}
main();
?>