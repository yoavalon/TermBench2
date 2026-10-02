<?php

function update_state($grid) {
    $rows = count($grid);
    $cols = count($grid[0]);
    $new_grid = array_fill(0, $rows, array_fill(0, $cols, 0.0));
    for ($i = 0; $i < $rows; $i++) {
        for ($j = 0; $j < $cols; $j++) {
            $neighbors = array(array($i - 1, $j), array($i + 1, $j), array($i, $j - 1), array($i, $j + 1));
            $value = 0.0;
            foreach ($neighbors as $neighbor) {
                $x = $neighbor[0];
                $y = $neighbor[1];
                if ($x >= 0 && $x < $rows && $y >= 0 && $y < $cols) {
                    $value += $grid[$x][$y];
                }
            }
            $new_grid[$i][$j] = $value / 4.0;
        }
    }
    return $new_grid;
}

function simulate($grid) {
    while (true) {
        $grid = update_state($grid);
    }
}

function main() {
    $grid_size = 10;
    $initial_grid = array();
    for ($i = 0; $i < $grid_size; $i++) {
        $row = array();
        for ($j = 0; $j < $grid_size; $j++) {
            $row[] = floatval($i * $j);
        }
        $initial_grid[] = $row;
    }
    simulate($initial_grid);
}

main();

?>