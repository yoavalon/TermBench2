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
            $new_grid[$y][$x] = ($neighbors == 3) ? 1 : $grid[$y][$x];
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
    $steps = 5;
    $initial_grid = array_fill(0, $height, array_fill(0, $width, 0));
    for ($y = 0; $y < $height; $y++) {
        for ($x = 0; $x < $width; $x++) {
            $initial_grid[$y][$x] = ($x == $y) ? 1 : 0;
        }
    }
    $final_grid = simulate($initial_grid, $width, $height, $steps);
    foreach ($final_grid as $row) {
        echo implode(' ', $row) . "\n";
    }
}

main();
?>