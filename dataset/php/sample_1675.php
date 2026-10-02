<?php
function update_state($grid) {
    $rows = count($grid);
    $cols = count($grid[0]);
    $new_grid = array_fill(0, $rows, array_fill(0, $cols, 0));
    for ($i = 0; $i < $rows; $i++) {
        for ($j = 0; $j < $cols; $j++) {
            $neighbors = 0;
            for ($x = max(0, $i - 1); $x < min($rows, $i + 2); $x++) {
                for ($y = max(0, $j - 1); $y < min($cols, $j + 2); $y++) {
                    if (($x != $i) || ($y != $j)) {
                        $neighbors += $grid[$x][$y];
                    }
                }
            }
            $new_grid[$i][$j] = ($neighbors == 3) ? 1 : (($neighbors == 2) ? $grid[$i][$j] : 0);
        }
    }
    return $new_grid;
}

function main() {
    $grid = [[0, 1, 0], [0, 1, 0], [0, 1, 0]];
    while (true) {
        $grid = update_state($grid);
        foreach ($grid as $row) {
            echo implode('', array_map(function($cell) { return $cell ? 'O' : '.'; }, $row));
            echo "\n";
        }
        echo "\n";
    }
}

main();
?>