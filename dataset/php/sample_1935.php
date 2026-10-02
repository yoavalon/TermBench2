<?php

function update_grid($grid) {
    $new_grid = $grid;
    $rows = count($grid);
    $cols = count($grid[0]);
    for ($i = 0; $i < $rows; $i++) {
        for ($j = 0; $j < $cols; $j++) {
            $neighbors = 0;
            for ($x = max(0, $i - 1); $x < min($rows, $i + 2); $x++) {
                for ($y = max(0, $j - 1); $y < min($cols, $j + 2); $y++) {
                    $neighbors += $grid[$x][$y];
                }
            }
            $neighbors -= $grid[$i][$j];
            if ($grid[$i][$j] == 1) {
                $new_grid[$i][$j] = ($neighbors >= 2 && $neighbors <= 3) ? 1 : 0;
            } else {
                $new_grid[$i][$j] = ($neighbors == 3) ? 1 : 0;
            }
        }
    }
    return $new_grid;
}

function main() {
    $grid_size = 10;
    $grid = array_fill(0, $grid_size, array_fill(0, $grid_size, 0));
    $grid[$grid_size // 2][$grid_size // 2] = 1;
    $steps = 50;
    for ($i = 0; $i < $steps; $i++) {
        $grid = update_grid($grid);
    }
    print_r($grid);
}

main();
?>