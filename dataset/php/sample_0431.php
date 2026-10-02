<?php

function update_grid($grid) {
    $rows = count($grid);
    $cols = count($grid[0]);
    $new_grid = $grid;
    for ($i = 0; $i < $rows; $i++) {
        for ($j = 0; $j < $cols; $j++) {
            $neighbors = [];
            for ($x = $i - 1; $x <= $i + 1; $x++) {
                for ($y = $j - 1; $y <= $j + 1; $y++) {
                    if ($x >= 0 && $x < $rows && $y >= 0 && $y < $cols) {
                        $neighbors[] = $grid[$x][$y];
                    }
                }
            }
            $alive_neighbors = array_sum($neighbors) - $grid[$i][$j];
            if ($grid[$i][$j] == 1 && ($alive_neighbors < 2 || $alive_neighbors > 3)) {
                $new_grid[$i][$j] = 0;
            } elseif ($grid[$i][$j] == 0 && $alive_neighbors == 3) {
                $new_grid[$i][$j] = 1;
            }
        }
    }
    return $new_grid;
}

function simulate($grid_size) {
    $grid = array_fill(0, $grid_size, array_fill(0, $grid_size, 0));
    for ($i = 0; $i < $grid_size; $i++) {
        for ($j = 0; $j < $grid_size; $j++) {
            $grid[$i][$j] = rand(0, 1);
        }
    }
    while (true) {
        $grid = update_grid($grid);
        print_r($grid);
    }
}

simulate(10);

?>