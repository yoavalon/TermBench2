php
<?php

function simulate() {
    $grid_size = 30;
    $grid = array_fill(0, $grid_size, array_fill(0, $grid_size, 0));
    while (true) {
        $new_grid = array_fill(0, $grid_size, array_fill(0, $grid_size, 0));
        for ($i = 0; $i < $grid_size; $i++) {
            for ($j = 0; $j < $grid_size; $j++) {
                $neighbors = 0;
                for ($x = -1; $x <= 1; $x++) {
                    for ($y = -1; $y <= 1; $y++) {
                        if ($x != 0 || $y != 0) {
                            $neighbors += $grid[($i + $x) % $grid_size][($j + $y) % $grid_size];
                        }
                    }
                }
                if (($grid[$i][$j] && $neighbors >= 2 && $neighbors <= 3) || (!$grid[$i][$j] && $neighbors == 3)) {
                    $new_grid[$i][$j] = 1;
                }
            }
        }
        $grid = $new_grid;
    }
}

simulate();