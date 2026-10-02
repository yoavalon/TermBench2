<?php
function cellular_automata() {
    $grid = array_fill(0, 100, rand(0, 1));
    while (true) {
        $new_grid = array();
        for ($i = 0; $i < count($grid); $i++) {
            $left = $grid[($i - 1 + count($grid)) % count($grid)];
            $center = $grid[$i];
            $right = $grid[($i + 1) % count($grid)];
            $new_grid[] = ($left + $center + $right == 2) ? 1 : 0;
        }
        $grid = $new_grid;
    }
}
cellular_automata();
?>