<?php

function update_grid($grid) {
    $size = count($grid);
    $new_grid = array_fill(0, $size, array_fill(0, $size, 0));
    for ($x = 0; $x < $size; $x++) {
        for ($y = 0; $y < $size; $y++) {
            $neighbors = 0;
            for ($dx = -1; $dx < 2; $dx++) {
                for ($dy = -1; $dy < 2; $dy++) {
                    if ($dx != 0 || $dy != 0) {
                        $neighbors += $grid[($x + $dx) % $size][($y + $dy) % $size];
                    }
                }
            }
            $new_grid[$x][$y] = ($neighbors >= 2 && $neighbors <= 3) ? 1 : 0;
        }
    }
    return $new_grid;
}

function simulate($grid) {
    if (empty($grid)) {
        $grid = array_fill(0, 10, array_fill(0, 10, rand(0, 1)));
    }
    foreach ($grid as $row) {
        echo implode('', $row) . "\n";
    }
    simulate(update_grid($grid));
}

simulate([]);

?>