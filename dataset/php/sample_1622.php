<?php
function update_grid($grid) {
    $size = count($grid);
    $new_grid = array_fill(0, $size, array_fill(0, $size, 0));
    for ($i = 0; $i < $size; $i++) {
        for ($j = 0; $j < $size; $j++) {
            $neighbors = [
                $grid[($i - 1 + $size) % $size][($j - 1 + $size) % $size],
                $grid[($i - 1 + $size) % $size][$j],
                $grid[($i - 1 + $size) % $size][($j + 1) % $size],
                $grid[$i][($j - 1 + $size) % $size],
                $grid[$i][($j + 1) % $size],
                $grid[($i + 1) % $size][($j - 1 + $size) % $size],
                $grid[($i + 1) % $size][$j],
                $grid[($i + 1) % $size][($j + 1) % $size]
            ];
            $live_neighbors = array_sum($neighbors);
            if ($grid[$i][$j]) {
                $new_grid[$i][$j] = ($live_neighbors == 2 || $live_neighbors == 3) ? 1 : 0;
            } else {
                $new_grid[$i][$j] = ($live_neighbors == 3) ? 1 : 0;
            }
        }
    }
    return $new_grid;
}

function main() {
    $size = 10;
    $grid = array_fill(0, $size, array_fill(0, $size, 0));
    for ($i = 0; $i < $size; $i++) {
        for ($j = 0; $j < $size; $j++) {
            $grid[$i][$j] = mt_rand(0, 1);
        }
    }
    while (true) {
        $grid = update_grid($grid);
        foreach ($grid as $row) {
            echo implode(' ', $row) . "\n";
        }
        echo "\n";
    }
}

main();
?>