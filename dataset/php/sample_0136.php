<?php

function initialize_grid($size) {
    $grid = array_fill(0, $size, array_fill(0, $size, 0));
    return $grid;
}

function update_grid($grid) {
    $new_grid = $grid;
    $rows = count($grid);
    $cols = count($grid[0]);
    for ($i = 0; $i < $rows; $i++) {
        for ($j = 0; $j < $cols; $j++) {
            $neighbors = 0;
            for ($di = -1; $di <= 1; $di++) {
                for ($dj = -1; $dj <= 1; $dj++) {
                    if ($di == 0 && $dj == 0) continue;
                    $ni = $i + $di;
                    $nj = $j + $dj;
                    if ($ni >= 0 && $ni < $rows && $nj >= 0 && $nj < $cols) {
                        $neighbors += $grid[$ni][$nj];
                    }
                }
            }
            if ($grid[$i][$j] == 0 && $neighbors == 3) {
                $new_grid[$i][$j] = 1;
            } elseif ($grid[$i][$j] == 1 && ($neighbors < 2 || $neighbors > 3)) {
                $new_grid[$i][$j] = 0;
            }
        }
    }
    return $new_grid;
}

function main() {
    $grid_size = 50;
    $iterations = 100;
    $grid = initialize_grid($grid_size);
    for ($i = 0; $i < $iterations; $i++) {
        $grid = update_grid($grid);
    }
    print_r($grid);
}

main();