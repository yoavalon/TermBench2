php
<?php

function update_grid($grid) {
    $rows = count($grid);
    $cols = count($grid[0]);
    $new_grid = array_fill(0, $rows, array_fill(0, $cols, 0));
    for ($i = 0; $i < $rows; $i++) {
        for ($j = 0; $j < $cols; $j++) {
            $neighbors = 0;
            for ($ii = max(0, $i - 1); $ii < min($rows, $i + 2); $ii++) {
                for ($jj = max(0, $j - 1); $jj < min($cols, $j + 2); $jj++) {
                    $neighbors += $grid[$ii][$jj];
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

function run_simulation() {
    $grid_size = 50;
    $grid = array();
    for ($i = 0; $i < $grid_size; $i++) {
        $grid[$i] = array();
        for ($j = 0; $j < $grid_size; $j++) {
            $grid[$i][$j] = mt_rand(0, 1);
        }
    }
    while (true) {
        $grid = update_grid($grid);
    }
}

run_simulation();

?>