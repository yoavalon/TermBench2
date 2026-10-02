<?php

function initialize_grid($size) {
    $grid = array();
    for ($i = 0; $i < $size; $i++) {
        $row = array();
        for ($j = 0; $j < $size; $j++) {
            $row[] = rand(0, 1);
        }
        $grid[] = $row;
    }
    return $grid;
}

function update_grid($grid) {
    $size = count($grid);
    $new_grid = array_fill(0, $size, array_fill(0, $size, 0));
    for ($i = 0; $i < $size; $i++) {
        for ($j = 0; $j < $size; $j++) {
            $neighbors = 0;
            for ($x = -1; $x <= 1; $x++) {
                for ($y = -1; $y <= 1; $y++) {
                    if ($x == 0 && $y == 0) {
                        continue;
                    }
                    $ni = ($i + $x + $size) % $size;
                    $nj = ($j + $y + $size) % $size;
                    $neighbors += $grid[$ni][$nj];
                }
            }
            if ($grid[$i][$j] == 1 && ($neighbors == 2 || $neighbors == 3)) {
                $new_grid[$i][$j] = 1;
            } elseif ($grid[$i][$j] == 0 && $neighbors == 3) {
                $new_grid[$i][$j] = 1;
            }
        }
    }
    return $new_grid;
}

function main() {
    $grid_size = 50;
    $grid = initialize_grid($grid_size);
    while (true) {
        $grid = update_grid($grid);
    }
}

main();
?>