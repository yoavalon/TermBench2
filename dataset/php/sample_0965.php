<?php
function cellular_automata($state, $rule) {
    $size = count($state);
    $next_state = array_fill(0, $size, 0);
    for ($i = 0; $i < $size; $i++) {
        $left = $state[($i - 1 + $size) % $size];
        $center = $state[$i];
        $right = $state[($i + 1) % $size];
        $index = ($left << 2) | ($center << 1) | $right;
        $next_state[$i] = ($rule >> $index) & 1;
    }
    return cellular_automata($next_state, $rule);
}

$rule = 30;
$initial_state = array_fill(0, 10, 0) + [1] + array_fill(0, 10, 0);
cellular_automata($initial_state, $rule);
?>