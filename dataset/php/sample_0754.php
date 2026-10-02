<?php

function update_grid($grid, $width, $height) {
    $new_grid = array_fill(0, $height, array_fill(0, $width, 0));
    for ($y = 0; $y < $height; $y++) {
        for ($x = 0; $x < $width; $x++) {
            $neighbors = 0;
            for ($dy = -1; $dy <= 1; $dy++) {
                for ($dx = -1; $dx <= 1; $dx++) {
                    if ($dx == 0 && $dy == 0) continue;
                    $neighbors += $grid[($y + $dy) % $height][($x + $dx) % $width];
                }
            }
            $new_grid[$y][$x] = ($neighbors == 3 || ($grid[$y][$x] && $neighbors == 2)) ? 1 : 0;
        }
    }
    return $new_grid;
}

function simulate($grid, $width, $height, $steps) {
    if ($steps == 0) {
        return $grid;
    }
    return simulate(update_grid($grid, $width, $height), $width, $height, $steps - 1);
}

function main() {
    $width = 5;
    $height = 5;
    $steps = 5;
    $grid = array_fill(0, $height, array_fill(0, $width, 0));
    for ($y = 0; $y < $height; $y++) {
        for ($x = 0; $x < $width; $x++) {
            $grid[$y][$x] = ($x + $y) % 2 ? 1 : 0;
        }
    }
    $final_grid = simulate($grid, $width, $height, $steps);
    foreach ($final_grid as $row) {
        echo implode('', array_map(function($cell) { return $cell ? 'O' : ' '; }, $row)) . "\n";
    }
}

main();