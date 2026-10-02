php
<?php

function initialize_grid($size) {
    $grid = array_fill(0, $size, array_fill(0, $size, 0));
    $grid[floor($size / 2)][floor($size / 2)] = 1;
    return $grid;
}

function update_grid($grid) {
    $new_grid = array_fill(0, count($grid), array_fill(0, count($grid), 0));
    for ($i = 0; $i < count($grid); $i++) {
        for ($j = 0; $j < count($grid); $j++) {
            $neighbors = 0;
            for ($x = max(0, $i - 1); $x < min(count($grid), $i + 2); $x++) {
                for ($y = max(0, $j - 1); $y < min(count($grid), $j + 2); $y++) {
                    if ($x != $i || $y != $j) {
                        $neighbors += $grid[$x][$y];
                    }
                }
            }
            if ($neighbors == 3 || ($grid[$i][$j] == 1 && $neighbors == 2)) {
                $new_grid[$i][$j] = 1;
            }
        }
    }
    return $new_grid;
}

function main() {
    $grid_size = 10;
    $grid = initialize_grid($grid_size);
    while (true) {
        $grid = update_grid($grid);
    }
}

main();

?>