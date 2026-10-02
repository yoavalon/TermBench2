<?php

function update_grid($grid, $width, $height) {
    $new_grid = array_fill(0, $height, array_fill(0, $width, 0.0));
    for ($y = 0; $y < $height; $y++) {
        for ($x = 0; $x < $width; $x++) {
            $neighbors = 0;
            for ($i = -1; $i < 2; $i++) {
                for ($j = -1; $j < 2; $j++) {
                    if ($i == 0 && $j == 0) {
                        continue;
                    }
                    $nx = ($x + $i) % $width;
                    $ny = ($y + $j) % $height;
                    $neighbors += $grid[$ny][$nx];
                }
            }
            $new_grid[$y][$x] = $neighbors / 9;
        }
    }
    return $new_grid;
}

function simulate($width, $height) {
    $grid = array_fill(0, $height, array_fill(0, $width, 0.0));
    while (true) {
        $grid = update_grid($grid, $width, $height);
    }
}

function main() {
    simulate(100, 100);
}

main();

?>