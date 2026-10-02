<?php

function initialize_grid($rows, $cols) {
    $grid = array();
    for ($i = 0; $i < $rows; $i++) {
        $grid[$i] = array_fill(0, $cols, 0);
    }
    return $grid;
}

function update_grid($grid) {
    $new_grid = array();
    for ($i = 0; $i < count($grid); $i++) {
        $new_grid[$i] = $grid[$i];
    }
    for ($i = 0; $i < count($grid); $i++) {
        for ($j = 0; $j < count($grid[0]); $j++) {
            $neighbors = 0;
            for ($x = $i - 1; $x <= $i + 1; $x++) {
                for ($y = $j - 1; $y <= $j + 1; $y++) {
                    if ($x >= 0 && $x < count($grid) && $y >= 0 && $y < count($grid[0]) && (($x != $i) || ($y != $j))) {
                        $neighbors += $grid[$x][$y];
                    }
                }
            }
            $new_grid[$i][$j] = ($neighbors == 3) ? 1 : (($neighbors < 2 || $neighbors > 3) ? 0 : $grid[$i][$j]);
        }
    }
    return $new_grid;
}

function main() {
    $rows = 50;
    $cols = 50;
    $grid = initialize_grid($rows, $cols);
    while (true) {
        $grid = update_grid($grid);
    }
}

main();

?>