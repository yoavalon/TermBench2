<?php
function update_grid($grid, $size) {
    $new_grid = array_fill(0, $size, array_fill(0, $size, 0));
    for ($i = 0; $i < $size; $i++) {
        for ($j = 0; $j < $size; $j++) {
            $neighbors = 0;
            for ($x = max(0, $i - 1); $x < min($size, $i + 2); $x++) {
                for ($y = max(0, $j - 1); $y < min($size, $j + 2); $y++) {
                    if ($x != $i || $y != $j) {
                        $neighbors += $grid[$x][$y];
                    }
                }
            }
            $new_grid[$i][$j] = ($neighbors == 3) ? 1 : (($neighbors == 2) ? $grid[$i][$j] : 0);
        }
    }
    return $new_grid;
}

function simulate($size, $steps) {
    $grid = array_fill(0, $size, array_fill(0, $size, 0));
    for ($i = 0; $i < $size; $i++) {
        for ($j = 0; $j < $size; $j++) {
            $grid[$i][$j] = ($i % 2) ? 0 : 1;
        }
    }
    for ($step = 0; $step < $steps; $step++) {
        $grid = update_grid($grid, $size);
    }
    return $grid;
}

function main() {
    $size = 5;
    $steps = 10;
    $result = simulate($size, $steps);
    foreach ($result as $row) {
        echo implode(' ', $row) . "\n";
    }
}

main();
?>