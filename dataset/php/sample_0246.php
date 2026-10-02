<?php

function initialize_grid($size) {
    $grid = array_fill(0, $size, array_fill(0, $size, 0));
    $grid[floor($size / 2)][floor($size / 2)] = 1;
    return $grid;
}

function apply_boundary_conditions(&$grid) {
    $size = count($grid);
    for ($i = 0; $i < $size; $i++) {
        $grid[0][$i] = 0;
        $grid[$size - 1][$i] = 0;
        $grid[$i][0] = 0;
        $grid[$i][$size - 1] = 0;
    }
}

function update_grid($grid) {
    $new_grid = $grid;
    $size = count($grid);
    for ($i = 1; $i < $size - 1; $i++) {
        for ($j = 1; $j < $size - 1; $j++) {
            $neighbors = 0;
            for ($di = -1; $di <= 1; $di++) {
                for ($dj = -1; $dj <= 1; $dj++) {
                    $neighbors += $grid[$i + $di][$j + $dj];
                }
            }
            $neighbors -= $grid[$i][$j];
            if ($grid[$i][$j] == 1) {
                if ($neighbors < 2 || $neighbors > 3) {
                    $new_grid[$i][$j] = 0;
                }
            } elseif ($neighbors == 3) {
                $new_grid[$i][$j] = 1;
            }
        }
    }
    return $new_grid;
}

function simulate($steps) {
    $size = 50;
    $grid = initialize_grid($size);
    apply_boundary_conditions($grid);
    for ($step = 0; $step < $steps; $step++) {
        $grid = update_grid($grid);
        apply_boundary_conditions($grid);
    }
    return $grid;
}

function main() {
    $steps = 100;
    $result = simulate($steps);
    print_r($result);
}

main();