<?php
function update_grid($grid) {
    $new_grid = array_fill(0, count($grid), array_fill(0, count($grid[0]), 0.0));
    for ($i = 1; $i < count($grid) - 1; $i++) {
        for ($j = 1; $j < count($grid[0]) - 1; $j++) {
            $avg = ($grid[$i - 1][$j] + $grid[$i + 1][$j] + $grid[$i][$j - 1] + $grid[$i][$j + 1]) / 4.0;
            $new_grid[$i][$j] = ($grid[$i][$j] + $avg) / 2.0;
        }
    }
    return $new_grid;
}

function simulate($grid, $steps) {
    for ($step = 0; $step < $steps; $step++) {
        $grid = update_grid($grid);
    }
    return $grid;
}

function main() {
    $grid_size = 10;
    $steps = 5;
    $grid = array_fill(0, $grid_size, array_fill(0, $grid_size, 0.0));
    $grid[$grid_size // 2][$grid_size // 2] = 1.0;
    $result = simulate($grid, $steps);
    foreach ($result as $row) {
        echo implode(' ', array_map(function($x) { return number_format($x, 2, '.', ''); }, $row)) . "\n";
    }
}

main();
?>