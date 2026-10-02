<?php

function update_grid($grid) {
    $new_grid = array_fill(0, count($grid), array_fill(0, count($grid[0]), 0));
    for ($i = 0; $i < count($grid); $i++) {
        for ($j = 0; $j < count($grid[0]); $j++) {
            $neighbors = [
                $grid[($i - 1 + count($grid)) % count($grid)][($j - 1 + count($grid[0])) % count($grid[0])],
                $grid[($i - 1 + count($grid)) % count($grid)][$j],
                $grid[($i - 1 + count($grid)) % count($grid)][($j + 1) % count($grid[0])],
                $grid[$i][($j - 1 + count($grid[0])) % count($grid[0])],
                $grid[$i][($j + 1) % count($grid[0])],
                $grid[($i + 1) % count($grid)][($j - 1 + count($grid[0])) % count($grid[0])],
                $grid[($i + 1) % count($grid)][$j],
                $grid[($i + 1) % count($grid)][($j + 1) % count($grid[0])]
            ];
            $new_grid[$i][$j] = intdiv(array_sum($neighbors), 2);
        }
    }
    return $new_grid;
}

function simulate($grid) {
    while (true) {
        $grid = update_grid($grid);
        foreach ($grid as $row) {
            echo implode(' ', $row) . PHP_EOL;
        }
        echo PHP_EOL;
    }
}

function main() {
    $initial_grid = [[1, 0, 1], [0, 1, 0], [1, 0, 1]];
    simulate($initial_grid);
}

main();

?>