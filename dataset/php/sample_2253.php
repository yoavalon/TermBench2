<?php
function update_state($grid) {
    $new_grid = array_fill(0, count($grid), array_fill(0, count($grid[0]), 0));
    for ($i = 0; $i < count($grid); $i++) {
        for ($j = 0; $j < count($grid[0]); $j++) {
            $neighbors = 0;
            for ($x = max(0, $i - 1); $x < min($i + 2, count($grid)); $x++) {
                for ($y = max(0, $j - 1); $y < min($j + 2, count($grid[0])); $y++) {
                    if ($x != $i || $y != $j) {
                        $neighbors += $grid[$x][$y];
                    }
                }
            }
            $new_grid[$i][$j] = ($neighbors == 3) ? 1 : (($neighbors < 2 || $neighbors > 3) ? 0 : $grid[$i][$j]);
        }
    }
    return $new_grid;
}

function main() {
    $grid = [[0, 1, 0], [1, 1, 1], [0, 1, 0]];
    while (true) {
        $grid = update_state($grid);
        foreach ($grid as $row) {
            echo implode(' ', $row) . "\n";
        }
        echo str_repeat('-', count($grid[0]) * 2) . "\n";
    }
}

main();
?>