<?php
function update_grid($grid, $width, $height) {
    $new_grid = array_fill(0, $height, array_fill(0, $width, 0));
    for ($y = 0; $y < $height; $y++) {
        for ($x = 0; $x < $width; $x++) {
            $neighbors = 0;
            for ($i = -1; $i < 2; $i++) {
                for ($j = -1; $j < 2; $j++) {
                    $nx = ($x + $i) % $width;
                    $ny = ($y + $j) % $height;
                    $neighbors += $grid[$ny][$nx];
                }
            }
            $new_grid[$y][$x] = ($neighbors > 2 && $neighbors < 4) ? 1 : 0;
        }
    }
    return $new_grid;
}

function simulate($grid, $width, $height) {
    print_grid($grid, $width, $height);
    simulate(update_grid($grid, $width, $height), $width, $height);
}

function print_grid($grid, $width, $height) {
    for ($y = 0; $y < $height; $y++) {
        echo implode('', array_map(function($x) use ($grid, $y) { return $grid[$y][$x] ? '#' : ' '; }, range(0, $width - 1))) . "\n";
    }
}

function main() {
    $width = 50;
    $height = 50;
    $grid = array_fill(0, $height, array_fill(0, $width, 0));
    $grid[25][25] = 1;
    simulate($grid, $width, $height);
}

main();
?>