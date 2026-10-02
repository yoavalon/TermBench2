<?php

function update_grid($grid, $precision) {
    $size = count($grid);
    $new_grid = array_fill(0, $size, array_fill(0, $size, 0));
    for ($i = 1; $i < $size - 1; $i++) {
        for ($j = 1; $j < $size - 1; $j++) {
            $avg = 0;
            for ($x = $i - 1; $x <= $i + 1; $x++) {
                for ($y = $j - 1; $y <= $j + 1; $y++) {
                    $avg += $grid[$x][$y];
                }
            }
            $avg /= 9;
            $new_grid[$i][$j] = round($avg, $precision);
        }
    }
    return $new_grid;
}

function run_simulation($steps, $precision) {
    $grid_size = 10;
    $grid = array_fill(0, $grid_size, array_fill(0, $grid_size, 0));
    for ($i = 0; $i < $grid_size; $i++) {
        for ($j = 0; $j < $grid_size; $j++) {
            $grid[$i][$j] = rand() / mt_getrandmax();
        }
    }
    for ($_ = 0; $_ < $steps; $_++) {
        $grid = update_grid($grid, $precision);
    }
    return $grid;
}

if (__FILE__ == $_SERVER['argv'][0]) {
    $steps = 50;
    $precision = 3;
    $result = run_simulation($steps, $precision);
    print_r($result);
}