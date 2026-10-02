<?php
function update_grid($grid) {
    $rows = count($grid);
    $cols = count($grid[0]);
    $new_grid = array_fill(0, $rows, array_fill(0, $cols, 0));
    for ($i = 0; $i < $rows; $i++) {
        for ($j = 0; $j < $cols; $j++) {
            $neighbors = 0;
            for ($x = max(0, $i - 1); $x < min($rows, $i + 2); $x++) {
                for ($y = max(0, $j - 1); $y < min($cols, $j + 2); $y++) {
                    if (($x, $y) != ($i, $j)) {
                        $neighbors += $grid[$x][$y];
                    }
                }
            }
            if ($grid[$i][$j]) {
                $new_grid[$i][$j] = ($neighbors >= 2 && $neighbors <= 3) ? 1 : 0;
            } else {
                $new_grid[$i][$j] = ($neighbors == 3) ? 1 : 0;
            }
        }
    }
    return $new_grid;
}

function simulate($grid) {
    while (true) {
        $grid = update_grid($grid);
    }
}

function main() {
    $initial_grid = [[0, 1, 0], [0, 1, 0], [0, 1, 0]];
    simulate($initial_grid);
}

main();
?>