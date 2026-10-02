<?php

function update_grid($grid, $width, $height) {
    $new_grid = array_fill(0, $height, array_fill(0, $width, 0.0));
    for ($y = 0; $y < $height; $y++) {
        for ($x = 0; $x < $width; $x++) {
            $neighbors = 0.0;
            for ($dy = -1; $dy < 2; $dy++) {
                for ($dx = -1; $dx < 2; $dx++) {
                    if ($dx == 0 && $dy == 0) {
                        continue;
                    }
                    $nx = $x + $dx;
                    $ny = $y + $dy;
                    if ($nx >= 0 && $nx < $width && $ny >= 0 && $ny < $height) {
                        $neighbors += $grid[$ny][$nx];
                    }
                }
            }
            $new_grid[$y][$x] = $grid[$y][$x] + 0.1 * ($neighbors - 2.0 * $grid[$y][$x]);
        }
    }
    return $new_grid;
}

function main() {
    $width = 10;
    $height = 10;
    $grid = array_fill(0, $height, array_fill(0, $width, 0.0));
    for ($y = 0; $y < $height; $y++) {
        for ($x = 0; $x < $width; $x++) {
            if ($x == $y) {
                $grid[$y][$x] = 0.0;
            } else {
                $grid[$y][$x] = 1.0;
            }
        }
    }
    for ($i = 0; $i < 100; $i++) {
        $grid = update_grid($grid, $width, $height);
    }
    print_r($grid);
}

main();

?>