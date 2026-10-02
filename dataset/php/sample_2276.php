<?php

function update_grid($grid) {
    $new_grid = array_fill(0, count($grid), array_fill(0, count($grid[0]), 0));
    for ($i = 1; $i < count($grid) - 1; $i++) {
        for ($j = 1; $j < count($grid[0]) - 1; $j++) {
            $neighbors = 0;
            for ($x = -1; $x <= 1; $x++) {
                for ($y = -1; $y <= 1; $y++) {
                    $neighbors += $grid[$i + $x][$j + $y];
                }
            }
            $neighbors -= $grid[$i][$j];
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

simulate();