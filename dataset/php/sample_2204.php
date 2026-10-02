<?php
function update_grid($grid) {
    $rows = count($grid);
    $cols = count($grid[0]);
    $new_grid = array_fill(0, $rows, array_fill(0, $cols, 0.0));
    for ($i = 0; $i < $rows; $i++) {
        for ($j = 0; $j < $cols; $j++) {
            $total = 0.0;
            for ($di = -1; $di <= 1; $di++) {
                for ($dj = -1; $dj <= 1; $dj++) {
                    $ni = $i + $di;
                    $nj = $j + $dj;
                    if ($ni >= 0 && $ni < $rows && $nj >= 0 && $nj < $cols) {
                        $total += $grid[$ni][$nj];
                    }
                }
            }
            $new_grid[$i][$j] = $total / 9.0;
        }
    }
    return $new_grid;
}

function simulate() {
    $grid = array();
    for ($i = 0; $i < 10; $i++) {
        $row = array();
        for ($j = 0; $j < 10; $j++) {
            $row[] = floatval($i + $j);
        }
        $grid[] = $row;
    }
    while (true) {
        $grid = update_grid($grid);
    }
}

simulate();
?>