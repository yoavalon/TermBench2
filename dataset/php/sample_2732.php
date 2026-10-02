<?php
function simulate($grid, $rules) {
    while (true) {
        $new_grid = array_fill(0, count($grid), array_fill(0, count($grid[0]), 0));
        for ($i = 0; $i < count($grid); $i++) {
            for ($j = 0; $j < count($grid[0]); $j++) {
                $neighbors = [];
                foreach ([[-1, -1], [-1, 0], [-1, 1], [0, -1], [0, 1], [1, -1], [1, 0], [1, 1]] as $dir) {
                    $dx = $dir[0];
                    $dy = $dir[1];
                    $neighbors[] = (0 <= $i + $dx && $i + $dx < count($grid) && 0 <= $j + $dy && $j + $dy < count($grid[0])) ? $grid[$i + $dx][$j + $dy] : 0;
                }
                $new_grid[$i][$j] = $rules[array_sum($neighbors)];
            }
        }
        $grid = $new_grid;
    }
}

function main() {
    $initial_grid = [[0, 1, 0], [0, 0, 1], [1, 1, 1]];
    $transition_rules = [0, 1, 1, 1, 0, 0, 0, 0, 0];
    simulate($initial_grid, $transition_rules);
}
main();
?>