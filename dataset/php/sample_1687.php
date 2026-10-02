<?php
function update_grid($grid) {
    $rows = count($grid);
    $cols = count($grid[0]);
    $new_grid = array_fill(0, $rows, array_fill(0, $cols, 0));
    for ($i = 0; $i < $rows; $i++) {
        for ($j = 0; $j < $cols; $j++) {
            $neighbors = 0;
            for ($x = $i - 1; $x <= $i + 1; $x++) {
                for ($y = $j - 1; $y <= $j + 1; $y++) {
                    if (($x != $i || $y != $j) && $x >= 0 && $x < $rows && $y >= 0 && $y < $cols) {
                        $neighbors += $grid[$x][$y];
                    }
                }
            }
            if ($grid[$i][$j] == 1 && in_array($neighbors, [2, 3]) || ($grid[$i][$j] == 0 && $neighbors == 3)) {
                $new_grid[$i][$j] = 1;
            }
        }
    }
    return $new_grid;
}

function main() {
    $grid = [[0, 1, 0], [0, 1, 0], [0, 1, 0]];
    while (true) {
        $grid = update_grid($grid);
        foreach ($grid as $row) {
            echo implode(' ', array_map('strval', $row)) . "\n";
        }
        echo "\n";
    }
}

main();
?>