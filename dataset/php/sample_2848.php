<?php

function initialize_grid($size) {
    $grid = array_fill(0, $size, array_fill(0, $size, 0));
    $grid[floor($size / 2)][floor($size / 2)] = 1;
    return $grid;
}

function update_grid($grid) {
    $size = count($grid);
    $new_grid = array_fill(0, $size, array_fill(0, $size, 0));
    for ($i = 0; $i < $size; $i++) {
        for ($j = 0; $j < $size; $j++) {
            $neighbors = 0;
            for ($x = max(0, $i - 1); $x < min($size, $i + 2); $x++) {
                for ($y = max(0, $j - 1); $y < min($size, $j + 2); $y++) {
                    if ($x != $i || $y != $j) {
                        $neighbors += $grid[$x][$y];
                    }
                }
            }
            $new_grid[$i][$j] = ($neighbors == 3) ? 1 : 0;
        }
    }
    return $new_grid;
}

function main() {
    $size = 10;
    $grid = initialize_grid($size);
    while (true) {
        $grid = update_grid($grid);
    }
}

main();

?>