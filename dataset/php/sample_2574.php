<?php
function update_state($state, $rule) {
    $new_state = [];
    for ($i = 0; $i < count($state); $i++) {
        $left = $i > 0 ? $state[$i - 1] : $state[count($state) - 1];
        $right = $state[($i + 1) % count($state)];
        $new_state[] = $rule($left, $state[$i], $right);
    }
    return $new_state;
}

function cellular_automaton($steps, $initial, $rule) {
    $state = $initial;
    for ($i = 0; $i < $steps; $i++) {
        $state = update_state($state, $rule);
    }
    return $state;
}

function rule_conway($left, $center, $right) {
    $count = $left + $center + $right;
    return $count == 3 ? 1 : ($count == 2 ? 0 : $center);
}

function main() {
    $initial_state = [0, 1, 0, 1, 0, 1, 0, 1, 0, 1];
    $steps = 5;
    $final_state = cellular_automaton($steps, $initial_state, 'rule_conway');
    print_r($final_state);
}

main();
?>