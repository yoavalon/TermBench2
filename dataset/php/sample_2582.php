<?php

function initialize_grid($size) {
    $grid = [];
    for ($i = 0; $i < $size; $i++) {
        $row = [];
        for ($j = 0; $j < $size; $j++) {
            $row[] = rand(0, 1);
        }
        $grid[] = $row;
    }
    return $grid;
}

function update_grid($grid) {
    $size = count($grid);
    $new_grid = array_fill(0, $size, array_fill(0, $size, 0));
    for ($i = 0; $i < $size; $i++) {
        for ($j = 0; $j < $size; $j++) {
            $neighbors = 0;
            for ($di = -1; $di <= 1; $di++) {
                for ($dj = -1; $dj <= 1; $dj++) {
                    if ($di == 0 && $dj == 0) continue;
                    $neighbors += $grid[($i + $di) % $size][($j + $dj) % $size];
                }
            }
            $new_grid[$i][$j] = ($neighbors == 3 || ($grid[$i][$j] && $neighbors == 2)) ? 1 : 0;
        }
    }
    return $new_grid;
}

function simulate($steps, $size) {
    $grid = initialize_grid($size);
    for ($step = 0; $step < $steps; $step++) {
        $grid = update_grid($grid);
    }
    return $grid;
}

function main() {
    $steps = 10;
    $size = 5;
    $result = simulate($steps, $size);
    foreach ($result as $row) {
        echo implode(' ', $row) . PHP_EOL;
    }
}

main();

?>