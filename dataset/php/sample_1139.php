<?php

function update_state($grid) {
    $new_grid = array_map(function($row) { return $row; }, $grid);
    for ($y = 0; $y < count($grid); $y++) {
        for ($x = 0; $x < count($grid[$y]); $x++) {
            $neighbors = [];
            for ($dy = -1; $dy <= 1; $dy++) {
                for ($dx = -1; $dx <= 1; $dx++) {
                    if ($dy == 0 && $dx == 0) {
                        continue;
                    }
                    $ny = $y + $dy;
                    $nx = $x + $dx;
                    if ($ny >= 0 && $ny < count($grid) && $nx >= 0 && $nx < count($grid[$y])) {
                        $neighbors[] = $grid[$ny][$nx];
                    }
                }
            }
            $count = array_sum($neighbors);
            if ($grid[$y][$x] == 1 && $count < 2) {
                $new_grid[$y][$x] = 0;
            } elseif ($grid[$y][$x] == 1 && ($count == 2 || $count == 3)) {
                $new_grid[$y][$x] = 1;
            } elseif ($grid[$y][$x] == 1 && $count > 3) {
                $new_grid[$y][$x] = 0;
            } elseif ($grid[$y][$x] == 0 && $count == 3) {
                $new_grid[$y][$x] = 1;
            }
        }
    }
    return $new_grid;
}

function display_grid($grid) {
    foreach ($grid as $row) {
        echo implode('', array_map(function($cell) { return $cell ? 'O' : ' '; }, $row)) . "\n";
    }
    echo "\n";
}

function simulate($grid) {
    display_grid($grid);
    simulate(update_state($grid));
}

function main() {
    $initial_grid = [[0, 0, 0, 0, 0], [0, 1, 1, 0, 0], [0, 1, 0, 1, 0], [0, 0, 1, 1, 0], [0, 0, 0, 0, 0]];
    simulate($initial_grid);
}

main();