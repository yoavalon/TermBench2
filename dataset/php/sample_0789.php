<?php

function update_grid($grid, $width, $height) {
    $new_grid = array_fill(0, $height, array_fill(0, $width, 0));
    for ($y = 0; $y < $height; $y++) {
        for ($x = 0; $x < $width; $x++) {
            $neighbors = 0;
            foreach ([[-1, -1], [-1, 0], [-1, 1], [0, -1], [0, 1], [1, -1], [1, 0], [1, 1]] as $dir) {
                $dy = $dir[0];
                $dx = $dir[1];
                $neighbors += $grid[($y + $dy) % $height][($x + $dx) % $width];
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
    $width = 10;
    $height = 10;
    $initial_grid = array_fill(0, $height, array_fill(0, $width, 0));
    for ($y = 0; $y < $height; $y++) {
        for ($x = 0; $x < $width; $x++) {
            $initial_grid[$y][$x] = ($x % 2) ? 0 : 1;
        }
    }
    $steps = 5;
    $final_grid = simulate($initial_grid, $width, $height, $steps);
    foreach ($final_grid as $row) {
        echo implode(' ', $row) . "\n";
    }
}

main();

?>