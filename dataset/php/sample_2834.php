<?php

function update_state($grid) {
    $rows = count($grid);
    $cols = count($grid[0]);
    $new_grid = $grid;
    for ($i = 0; $i < $rows; $i++) {
        for ($j = 0; $j < $cols; $j++) {
            $neighbors = 0;
            for ($x = -1; $x <= 1; $x++) {
                for ($y = -1; $y <= 1; $y++) {
                    if ($x == 0 && $y == 0) continue;
                    $ni = $i + $x;
                    $nj = $j + $y;
                    if ($ni >= 0 && $ni < $rows && $nj >= 0 && $nj < $cols) {
                        $neighbors += $grid[$ni][$nj];
                    }
                }
            }
            if ($grid[$i][$j] == 1) {
                if ($neighbors < 2 || $neighbors > 3) {
                    $new_grid[$i][$j] = 0;
                }
            } elseif ($neighbors == 3) {
                $new_grid[$i][$j] = 1;
            }
        }
    }
    return $new_grid;
}

function main() {
    $size = 100;
    $grid = [];
    for ($i = 0; $i < $size; $i++) {
        $grid[$i] = [];
        for ($j = 0; $j < $size; $j++) {
            $grid[$i][$j] = rand(0, 1);
        }
    }
    while (true) {
        $grid = update_state($grid);
    }
}

main();
?>