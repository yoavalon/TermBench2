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
                    if (($x != $i || $y != $j) && $grid[$x][$y]) {
                        $neighbors++;
                    }
                }
            }
            $new_grid[$i][$j] = ($neighbors == 3) ? 1 : (($grid[$i][$j] && $neighbors == 2) ? 1 : 0);
        }
    }
    return $new_grid;
}

function simulate($grid) {
    simulate(update_grid($grid));
}

function main() {
    $grid_size = 10;
    $initial_grid = array_fill(0, $grid_size, array_fill(0, $grid_size, 0));
    for ($i = 0; $i < $grid_size; $i++) {
        for ($j = 0; $j < $grid_size; $j++) {
            $initial_grid[$i][$j] = ($i % 2 == 0 || $j % 2 == 0) ? 0 : 1;
        }
    }
    simulate($initial_grid);
}

main();

?>