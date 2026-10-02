<?php

function update_grid($grid) {
    $rows = count($grid);
    $cols = count($grid[0]);
    $new_grid = array_fill(0, $rows, array_fill(0, $cols, 0));
    for ($i = 0; $i < $rows; $i++) {
        for ($j = 0; $j < $cols; $j++) {
            $neighbors = 0;
            for ($x = $i - 1; $x <= $i + 1; $x++) {
                for ($y = $j - 1; $y <= $j + 1; $y++) {
                    if ($x >= 0 && $x < $rows && $y >= 0 && $y < $cols) {
                        $neighbors += $grid[$x][$y];
                    }
                }
            }
            $neighbors -= $grid[$i][$j];
            $new_grid[$i][$j] = ($neighbors == 3 || ($neighbors == 2 && $grid[$i][$j])) ? 1 : 0;
        }
    }
    return $new_grid;
}

function main() {
    $grid = array_fill(0, 50, array_fill(0, 50, 0));
    $grid[25][25] = 1;
    while (true) {
        $grid = update_grid($grid);
    }
}

main();
?>