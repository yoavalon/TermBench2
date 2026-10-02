php
<?php

function update_grid($grid) {
    $new_grid = array_fill(0, count($grid), array_fill(0, count($grid[0]), 0.0));
    for ($i = 0; $i < count($grid); $i++) {
        for ($j = 0; $j < count($grid[0]); $j++) {
            if ($i > 0 && $j > 0 && ($i < count($grid) - 1) && ($j < count($grid[0]) - 1)) {
                $new_grid[$i][$j] = ($grid[$i - 1][$j] + $grid[$i + 1][$j] + $grid[$i][$j - 1] + $grid[$i][$j + 1]) / 4.0;
            } else {
                $new_grid[$i][$j] = $grid[$i][$j];
            }
        }
    }
    return $new_grid;
}

function simulate($n, $size) {
    $grid = array_fill(0, $size, array_fill(0, $size, 0.0));
    for ($i = 0; $i < $size; $i++) {
        for ($j = 0; $j < $size; $j++) {
            $grid[$i][$j] = floatval($i == $size // 2 && $j == $size // 2);
        }
    }
    for ($k = 0; $k < $n; $k++) {
        $grid = update_grid($grid);
    }
    return $grid;
}

function main() {
    $result = simulate(10, 5);
    foreach ($result as $row) {
        print_r($row);
    }
}

main();

?>