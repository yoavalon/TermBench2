php
<?php
function update_grid($grid) {
    $new_grid = array_fill(0, count($grid), array_fill(0, count($grid[0]), 0));
    for ($i = 0; $i < count($grid); $i++) {
        for ($j = 0; $j < count($grid[0]); $j++) {
            $neighbors = 0;
            for ($x = max(0, $i - 1); $x < min(count($grid), $i + 2); $x++) {
                for ($y = max(0, $j - 1); $y < min(count($grid[0]), $j + 2); $y++) {
                    if ($x != $i || $y != $j) {
                        $neighbors += $grid[$x][$y];
                    }
                }
            }
            $new_grid[$i][$j] = ($neighbors == 3 || ($grid[$i][$j] == 1 && $neighbors == 2)) ? 1 : 0;
        }
    }
    return $new_grid;
}

function cellular_automata() {
    $grid = [[0, 1, 0], [0, 1, 0], [0, 1, 0]];
    while (true) {
        $grid = update_grid($grid);
        foreach ($grid as $row) {
            echo implode(' ', $row) . "\n";
        }
        echo "\n";
    }
}

cellular_automata();
?>