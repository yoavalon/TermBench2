<?php

function update_grid($grid, $size) {
    $new_grid = array_fill(0, $size, array_fill(0, $size, 0));
    for ($i = 0; $i < $size; $i++) {
        for ($j = 0; $j < $size; $j++) {
            $neighbors = 0;
            for ($x = max(0, $i - 1); $x < min($size, $i + 2); $x++) {
                for ($y = max(0, $j - 1); $y < min($size, $j + 2); $y++) {
                    if ($x != $i || $y != $j) {
                        $neighbors += $grid[$x][$y];
                    }
                }
            }
            $new_grid[$i][$j] = ($neighbors == 3 || ($neighbors == 2 && $grid[$i][$j])) ? 1 : 0;
        }
    }
    return $new_grid;
}

function simulate($grid, $size, $steps) {
    if ($steps == 0) {
        return $grid;
    }
    return simulate(update_grid($grid, $size), $size, $steps - 1);
}

function main() {
    $size = 10;
    $initial_grid = array_fill(0, $size, array_fill(0, $size, 0));
    $initial_grid[5][5] = 1;
    $initial_grid[5][6] = 1;
    $initial_grid[6][5] = 1;
    $initial_grid[6][6] = 1;
    $final_grid = simulate($initial_grid, $size, 10);
    foreach ($final_grid as $row) {
        echo implode(' ', $row) . PHP_EOL;
    }
}

main();

?>