<?php
function cellular_automata($grid, $rule) {
    $new_grid = array_fill(0, count($grid), array_fill(0, count($grid[0]), 0));
    for ($i = 0; $i < count($grid); $i++) {
        for ($j = 0; $j < count($grid[0]); $j++) {
            $neighbors = [];
            for ($x = -1; $x <= 1; $x++) {
                for ($y = -1; $y <= 1; $y++) {
                    if ($x != 0 || $y != 0) {
                        $neighbors[] = $grid[($i + $x) % count($grid)][$j + $y) % count($grid[0])];
                    }
                }
            }
            sort($neighbors);
            $new_grid[$i][$j] = $rule($neighbors);
        }
    }
    return cellular_automata($new_grid, $rule);
}

function main() {
    $initial_grid = array_fill(0, 10, array_fill(0, 10, 0));
    for ($i = 0; $i < 10; $i++) {
        $initial_grid[$i][$i] = 1;
    }
    $rule = function($n) {
        return array_sum($n) == 3 ? 1 : 0;
    };
    cellular_automata($initial_grid, $rule);
}
main();
?>