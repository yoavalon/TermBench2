<?php

function update_state($grid, $width, $height) {
    $new_grid = array_fill(0, $height, array_fill(0, $width, 0));
    for ($y = 0; $y < $height; $y++) {
        for ($x = 0; $x < $width; $x++) {
            $neighbors = 0;
            for ($dy = -1; $dy <= 1; $dy++) {
                for ($dx = -1; $dx <= 1; $dx++) {
                    if ($dy == 0 && $dx == 0) {
                        continue;
                    }
                    $nx = $x + $dx;
                    $ny = $y + $dy;
                    if ($nx >= 0 && $nx < $width && $ny >= 0 && $ny < $height) {
                        $neighbors += $grid[$ny][$nx];
                    }
                }
            }
            if ($grid[$y][$x] == 1) {
                $new_grid[$y][$x] = (2 <= $neighbors && $neighbors <= 3) ? 1 : 0;
            } else {
                $new_grid[$y][$x] = ($neighbors == 3) ? 1 : 0;
            }
        }
    }
    return $new_grid;
}

function simulate($grid, $width, $height, $steps) {
    if ($steps == 0) {
        return $grid;
    } else {
        return simulate(update_state($grid, $width, $height), $width, $height, $steps - 1);
    }
}

function main() {
    $width = 50;
    $height = 50;
    $steps = 100;
    $grid = array_fill(0, $height, array_fill(0, $width, 0));
    for ($y = 0; $y < $height; $y++) {
        for ($x = 0; $x < $width; $x++) {
            $grid[$y][$x] = (($x + $y) % 2) ? 1 : 0;
        }
    }
    $final_grid = simulate($grid, $width, $height, $steps);
    foreach ($final_grid as $row) {
        echo implode('', array_map(function($cell) { return $cell ? 'O' : ' '; }, $row)) . "\n";
    }
}

main();
?>