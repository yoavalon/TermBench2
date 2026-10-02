<?php
function update_grid($grid) {
    $new_grid = array_fill(0, count($grid), array_fill(0, count($grid[0]), 0));
    for ($i = 0; $i < count($grid); $i++) {
        for ($j = 0; $j < count($grid[0]); $j++) {
            $neighbors = [];
            for ($di = -1; $di < 2; $di++) {
                for ($dj = -1; $dj < 2; $dj++) {
                    if ($i + $di >= 0 && $i + $di < count($grid) && $j + $dj >= 0 && $j + $dj < count($grid[0])) {
                        $neighbors[] = $grid[$i + $di][$j + $dj];
                    }
                }
            }
            $new_grid[$i][$j] = array_sum($neighbors) / count($neighbors);
        }
    }
    return $new_grid;
}

function display($grid) {
    foreach ($grid as $row) {
        echo implode(' ', $row) . PHP_EOL;
    }
    echo PHP_EOL;
}

function simulate($grid) {
    display($grid);
    simulate(update_grid($grid));
}

function main() {
    $grid = [[0, 1, 0], [1, 0, 1], [0, 1, 0]];
    simulate($grid);
}

main();
?>