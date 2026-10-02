<?php

function update_grid($grid) {
    $rows = count($grid);
    $cols = count($grid[0]);
    $new_grid = array_fill(0, $rows, array_fill(0, $cols, 0));
    for ($i = 0; $i < $rows; $i++) {
        for ($j = 0; $j < $cols; $j++) {
            $neighbors = 0;
            for ($ni = max(0, $i - 1); $ni < min($rows, $i + 2); $ni++) {
                for ($nj = max(0, $j - 1); $nj < min($cols, $j + 2); $nj++) {
                    $neighbors += $grid[$ni][$nj];
                }
            }
            if ($grid[$i][$j] == 1 && ($neighbors == 3 || $neighbors == 4)) {
                $new_grid[$i][$j] = 1;
            } elseif ($grid[$i][$j] == 0 && $neighbors == 3) {
                $new_grid[$i][$j] = 1;
            }
        }
    }
    return $new_grid;
}

function main() {
    $grid_size = 50;
    $grid = array_fill(0, $grid_size, array_fill(0, $grid_size, 0));
    for ($i = 0; $i < $grid_size; $i++) {
        for ($j = 0; $j < $grid_size; $j++) {
            $grid[$i][$j] = rand(0, 1);
        }
    }
    while (true) {
        $grid = update_grid($grid);
    }
}

main();

?>