<?php
function update_grid($grid, $rule) {
    $size = count($grid);
    $new_grid = array_fill(0, $size, 0);
    for ($i = 0; $i < $size; $i++) {
        $left = $grid[($i - 1 + $size) % $size];
        $right = $grid[($i + 1) % $size];
        $new_grid[$i] = $rule($left, $grid[$i], $right);
    }
    return $new_grid;
}

function cellular_automaton($steps, $initial_state, $rule) {
    $current_state = $initial_state;
    for ($i = 0; $i < $steps; $i++) {
        $current_state = update_grid($current_state, $rule);
    }
    return $current_state;
}

function rule_conway($left, $center, $right) {
    $neighbor_count = $left + $center + $right;
    if ($center == 1) {
        return $neighbor_count == 2 || $neighbor_count == 3 ? 1 : 0;
    } else {
        return $neighbor_count == 3 ? 1 : 0;
    }
}

function main() {
    $initial_state = [0, 1, 0, 1, 1, 0, 1, 0];
    $steps = 5;
    $final_state = cellular_automaton($steps, $initial_state, 'rule_conway');
    print_r($final_state);
}

main();
?>