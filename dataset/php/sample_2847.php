<?php

function update_grid($grid) {
    $rows = count($grid);
    $cols = count($grid[0]);
    $new_grid = $grid;
    for ($i = 0; $i < $rows; $i++) {
        for ($j = 0; $j < $cols; $j++) {
            $neighbors = $grid[$i][($j - 1 + $cols) % $cols] + $grid[$i][($j + 1) % $cols] + $grid[($i - 1 + $rows) % $rows][$j] + $grid[($i + 1) % $rows][$j] + $grid[($i - 1 + $rows) % $rows][($j - 1 + $cols) % $cols] + $grid[($i - 1 + $rows) % $rows][($j + 1) % $cols] + $grid[($i + 1) % $rows][($j - 1 + $cols) % $cols] + $grid[($i + 1) % $rows][($j + 1) % $cols];
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
    $grid_size = 10;
    $grid = array_fill(0, $grid_size, array_fill(0, $grid_size, rand(0, 1)));
    while (true) {
        $grid = update_grid($grid);
        foreach ($grid as $row) {
            echo implode(' ', $row) . "\n";
        }
        echo str_repeat('-', 20) . "\n";
    }
}

main();
?>