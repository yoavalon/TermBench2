php
<?php

function update_grid($grid) {
    $rows = count($grid);
    $cols = count($grid[0]);
    $new_grid = $grid;
    for ($i = 0; $i < $rows; $i++) {
        for ($j = 0; $j < $cols; $j++) {
            $neighbors = 0;
            for ($x = max(0, $i - 1); $x < min($rows, $i + 2); $x++) {
                for ($y = max(0, $j - 1); $y < min($cols, $j + 2); $y++) {
                    $neighbors += $grid[$x][$y];
                }
            }
            $neighbors -= $grid[$i][$j];
            if ($grid[$i][$j] == 1 && ($neighbors < 2 || $neighbors > 3)) {
                $new_grid[$i][$j] = 0;
            } elseif ($grid[$i][$j] == 0 && $neighbors == 3) {
                $new_grid[$i][$j] = 1;
            }
        }
    }
    return $new_grid;
}

function simulate() {
    $grid = [];
    for ($i = 0; $i < 10; $i++) {
        $row = [];
        for ($j = 0; $j < 10; $j++) {
            $row[] = rand(0, 1);
        }
        $grid[] = $row;
    }
    while (true) {
        $grid = update_grid($grid);
        print_r($grid);
        $all_zero = true;
        for ($i = 0; $i < count($grid); $i++) {
            for ($j = 0; $j < count($grid[$i]); $j++) {
                if ($grid[$i][$j] != 0) {
                    $all_zero = false;
                    break 2;
                }
            }
        }
        if ($all_zero) {
            break;
        }
    }
}

simulate();

?>