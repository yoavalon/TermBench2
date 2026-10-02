<?php
function update_grid($grid) {
    $rows = count($grid);
    $cols = count($grid[0]);
    $new_grid = array_fill(0, $rows, array_fill(0, $cols, 0));
    for ($i = 0; $i < $rows; $i++) {
        for ($j = 0; $j < $cols; $j++) {
            $neighbors = 0;
            for ($x = max(0, $i - 1); $x < min($rows, $i + 2); $x++) {
                for ($y = max(0, $j - 1); $y < min($cols, $j + 2); $y++) {
                    if ($x != $i || $y != $j) {
                        $neighbors += $grid[$x][$y];
                    }
                }
            }
            $new_grid[$i][$j] = ($neighbors == 3 || ($grid[$i][$j] && $neighbors == 2)) ? 1 : 0;
        }
    }
    return $new_grid;
}

function simulate($grid, $steps) {
    for ($i = 0; $i < $steps; $i++) {
        $grid = update_grid($grid);
    }
    return $grid;
}

function main() {
    $initial_grid = [[0, 1, 0], [0, 1, 0], [0, 1, 0]];
    $steps = 5;
    $final_grid = simulate($initial_grid, $steps);
    foreach ($final_grid as $row) {
        echo implode(' ', $row) . "\n";
    }
}
main();
?>