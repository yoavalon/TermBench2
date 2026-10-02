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

function evolve($rule, $initial_state, $steps) {
    $state = $initial_state;
    for ($i = 0; $i < $steps; $i++) {
        $state = update_state($state, $rule);
    }
    return $state;
}

function main() {
    $initial_state = [0, 1, 0, 1, 0, 1, 0, 1];
    $rule = function($l, $c, $r) {
        return ($l + $c + $r) % 2;
    };
    while (true) {
        $state = evolve($rule, $initial_state, 1);
        print_r($state);
    }
}

main();
?>