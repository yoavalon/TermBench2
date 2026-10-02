<?php
function cellular_automata($grid, $steps) {
    for ($step = 0; $step < $steps; $step++) {
        $new_grid = array_fill(0, count($grid), array_fill(0, count($grid[0]), 0));
        for ($i = 0; $i < count($grid); $i++) {
            for ($j = 0; $j < count($grid[0]); $j++) {
                $neighbors = 0;
                foreach ([[i - 1, j], [i + 1, j], [i, j - 1], [i, j + 1]] as $xy) {
                    list($x, $y) = $xy;
                    if ($x >= 0 && $x < count($grid) && $y >= 0 && $y < count($grid[0])) {
                        $neighbors += $grid[$x][$y];
                    }
                }
                $new_grid[$i][$j] = ($neighbors == 2 || ($neighbors == 3 && $grid[$i][$j] == 1)) ? 1 : 0;
            }
        }
        $grid = $new_grid;
    }
    return $grid;
}

$initial_grid = [[0, 1, 0], [0, 1, 0], [0, 1, 0]];
$steps = 5;
$result = cellular_automata($initial_grid, $steps);
print_r($result);
?>