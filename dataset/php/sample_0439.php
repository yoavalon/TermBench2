<?php

function update_grid($grid) {
    $rows = count($grid);
    $cols = count($grid[0]);
    $new_grid = array();
    for ($i = 0; $i < $rows; $i++) {
        $new_grid[$i] = array();
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
            if ($grid[$i][$j] == 1 && ($neighbors < 2 || $neighbors > 3)) {
                $new_grid[$i][$j] = 0;
            } elseif ($grid[$i][$j] == 0 && $neighbors == 3) {
                $new_grid[$i][$j] = 1;
            } else {
                $new_grid[$i][$j] = $grid[$i][$j];
            }
        }
    }
    return $new_grid;
}

function main() {
    $size = 50;
    $grid = array_fill(0, $size, array_fill(0, $size, mt_rand(0, 1)));
    while (true) {
        $grid = update_grid($grid);
    }
}

main();