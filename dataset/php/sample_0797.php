<?php
function update_grid($grid) {
    $new_grid = array_fill(0, count($grid), array_fill(0, count($grid[0]), 0));
    for ($i = 0; $i < count($grid); $i++) {
        for ($j = 0; $j < count($grid[0]); $j++) {
            $count = 0;
            for ($x = $i - 1; $x <= $i + 1; $x++) {
                for ($y = $j - 1; $y <= $j + 1; $y++) {
                    if ($x >= 0 && $x < count($grid) && $y >= 0 && $y < count($grid[0]) && ($x != $i || $y != $j)) {
                        $count += $grid[$x][$y];
                    }
                }
            }
            $new_grid[$i][$j] = ($grid[$i][$j] && ($count == 2 || $count == 3)) || $count == 3;
        }
    }
    return $new_grid;
}

function simulate($grid, $steps) {
    for ($i = 0; $i < $steps; $i++) {
        $grid = update_grid($grid);
    }
    return $grid;
}

function main() {
    $initial_grid = [[0, 0, 0, 0, 0], [0, 1, 1, 1, 0], [0, 0, 0, 0, 0], [0, 0, 1, 0, 0], [0, 0, 0, 0, 0]];
    $final_grid = simulate($initial_grid, 10);
    foreach ($final_grid as $row) {
        echo implode(" ", $row) . "\n";
    }
}

main();
?>