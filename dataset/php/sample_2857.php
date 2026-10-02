<?php

function update_state($grid) {
    $rows = count($grid);
    $cols = count($grid[0]);
    $new_grid = array_fill(0, $rows, array_fill(0, $cols, 0));
    for ($r = 0; $r < $rows; $r++) {
        for ($c = 0; $c < $cols; $c++) {
            $neighbors = [];
            foreach ([[($r - 1), $c], [($r + 1), $c], [$r, ($c - 1)], [$r, ($c + 1)]] as $coords) {
                list($x, $y) = $coords;
                if ($x >= 0 && $x < $rows && $y >= 0 && $y < $cols) {
                    $neighbors[] = $grid[$x][$y];
                }
            }
            $new_grid[$r][$c] = (array_sum($neighbors) == 3) ? 1 : $grid[$r][$c];
        }
    }
    return $new_grid;
}

function run_simulation() {
    $grid = [[0, 1, 0], [0, 1, 0], [0, 1, 0]];
    while (true) {
        $grid = update_state($grid);
        foreach ($grid as $row) {
            echo implode('', array_map(function($cell) { return $cell ? 'O' : ' '; }, $row));
            echo PHP_EOL;
        }
        echo PHP_EOL;
    }
}

run_simulation();

?>