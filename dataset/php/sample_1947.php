<?php
function update_grid($grid, $width, $height) {
    $new_grid = array_fill(0, $height, array_fill(0, $width, 0.0));
    for ($y = 0; $y < $height; $y++) {
        for ($x = 0; $x < $width; $x++) {
            $neighbors = array();
            for ($dy = -1; $dy <= 1; $dy++) {
                for ($dx = -1; $dx <= 1; $dx++) {
                    if ($dy != 0 || $dx != 0) {
                        $neighbors[] = $grid[($y + $dy) % $height][($x + $dx) % $width];
                    }
                }
            }
            $new_grid[$y][$x] = array_sum($neighbors) / count($neighbors);
        }
    }
    return $new_grid;
}

function simulate($width, $height, $steps) {
    $grid = array();
    for ($y = 0; $y < $height; $y++) {
        for ($x = 0; $x < $width; $x++) {
            $grid[$y][$x] = floatval($x + $y);
        }
    }
    for ($i = 0; $i < $steps; $i++) {
        $grid = update_grid($grid, $width, $height);
    }
    return $grid;
}

function main() {
    $width = 10;
    $height = 10;
    $steps = 5;
    $final_grid = simulate($width, $height, $steps);
    foreach ($final_grid as $row) {
        print_r($row);
    }
}

main();
?>