<?php

function update_grid($grid) {
    $shape = [count($grid), count($grid[0])];
    $new_grid = array_fill(0, $shape[0], array_fill(0, $shape[1], 0));
    for ($i = 0; $i < $shape[0]; $i++) {
        for ($j = 0; $j < $shape[1]; $j++) {
            $neighbors = 0;
            for ($di = -1; $di <= 1; $di++) {
                for ($dj = -1; $dj <= 1; $dj++) {
                    if ($di == 0 && $dj == 0) continue;
                    $ni = $i + $di;
                    $nj = $j + $dj;
                    if ($ni >= 0 && $ni < $shape[0] && $nj >= 0 && $nj < $shape[1]) {
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

function simulate() {
    $size = 100;
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

simulate();
?>