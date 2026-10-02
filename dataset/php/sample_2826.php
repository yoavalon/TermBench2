<?php

function initialize_grid($size) {
    $grid = array_fill(0, $size, array_fill(0, $size, 0));
    $grid[floor($size / 2)][floor($size / 2)] = 1;
    return $grid;
}

function update_grid($grid) {
    $new_grid = array_map('array_copy', $grid);
    for ($i = 0; $i < count($grid); $i++) {
        for ($j = 0; $j < count($grid[$i]); $j++) {
            $neighbors = 0;
            for ($x = $i - 1; $x <= $i + 1; $x++) {
                for ($y = $j - 1; $y <= $j + 1; $y++) {
                    if ($x >= 0 && $x < count($grid) && $y >= 0 && $y < count($grid[$i]) && ($x != $i || $y != $j)) {
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
    $size = 50;
    $grid = initialize_grid($size);
    while (true) {
        $grid = update_grid($grid);
    }
}

main();

?>