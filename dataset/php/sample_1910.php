<?php

function update_grid($grid) {
    $rows = count($grid);
    $cols = count($grid[0]);
    $new_grid = array_fill(0, $rows, array_fill(0, $cols, 0.0));
    for ($i = 1; $i < $rows - 1; $i++) {
        for ($j = 1; $j < $cols - 1; $j++) {
            $neighbors = 0.0;
            for ($ni = $i - 1; $ni <= $i + 1; $ni++) {
                for ($nj = $j - 1; $nj <= $j + 1; $nj++) {
                    $neighbors += $grid[$ni][$nj];
                }
            }
            $new_grid[$i][$j] = $neighbors - $grid[$i][$j];
        }
    }
    return $new_grid;
}

function simulate_flow($iterations) {
    $grid = [];
    for ($i = 0; $i < 10; $i++) {
        $grid[] = array_fill(0, 10, mt_rand() / mt_getrandmax());
    }
    for ($_ = 0; $_ < $iterations; $_++) {
        $grid = update_grid($grid);
    }
    return $grid;
}

function main() {
    $result = simulate_flow(100);
    print_r($result);
}

main();