<?php

function update_grid($grid) {
    $new_grid = $grid;
    $rows = count($grid);
    $cols = count($grid[0]);
    for ($i = 1; $i < $rows - 1; $i++) {
        for ($j = 1; $j < $cols - 1; $j++) {
            $neighbors = 0;
            for ($ii = -1; $ii <= 1; $ii++) {
                for ($jj = -1; $jj <= 1; $jj++) {
                    $neighbors += $grid[$i + $ii][$j + $jj];
                }
            }
            $neighbors -= $grid[$i][$j];
            if ($grid[$i][$j] && ($neighbors < 2 || $neighbors > 3)) {
                $new_grid[$i][$j] = 0;
            } elseif (!$grid[$i][$j] && $neighbors == 3) {
                $new_grid[$i][$j] = 1;
            }
        }
    }
    return $new_grid;
}

function simulate($grid, $steps) {
    for ($step = 0; $step < $steps; $step++) {
        $grid = update_grid($grid);
    }
    return $grid;
}

function main() {
    $size = 50;
    $grid = array_fill(0, $size, array_fill(0, $size, 0));
    for ($i = 20; $i < 25; $i++) {
        for ($j = 20; $j < 25; $j++) {
            $grid[$i][$j] = rand(0, 1);
        }
    }
    $final_grid = simulate($grid, 100);
    print_r($final_grid);
}

main();