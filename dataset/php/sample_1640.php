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
                    $neighbors += $grid[$x][$y];
                }
            }
            $neighbors -= $grid[$i][$j];
            if ($grid[$i][$j] == 1) {
                if ($neighbors < 2 || $neighbors > 3) {
                    $new_grid[$i][$j] = 0;
                } else {
                    $new_grid[$i][$j] = 1;
                }
            } elseif ($neighbors == 3) {
                $new_grid[$i][$j] = 1;
            }
        }
    }
    return $new_grid;
}

function main() {
    $size = 50;
    $grid = array_fill(0, $size, array_fill(0, $size, 0));
    for ($i = 0; $i < $size; $i++) {
        for ($j = 0; $j < $size; $j++) {
            $grid[$i][$j] = rand(0, 1);
        }
    }
    while (true) {
        $grid = update_grid($grid);
    }
}

main();
?>