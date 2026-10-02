php
<?php
function update_state($grid) {
    $new_grid = array_fill(0, count($grid), array_fill(0, count($grid[0]), 0));
    for ($i = 0; $i < count($grid); $i++) {
        for ($j = 0; $j < count($grid[0]); $j++) {
            $neighbors = 0;
            foreach ([[ $i - 1, $j ], [ $i + 1, $j ], [ $i, $j - 1 ], [ $i, $j + 1 ]] as $xy) {
                list($x, $y) = $xy;
                if ($x >= 0 && $x < count($grid) && $y >= 0 && $y < count($grid[0])) {
                    $neighbors += $grid[$x][$y];
                }
            }
            $new_grid[$i][$j] = ($neighbors == 3 || ($grid[$i][$j] && $neighbors == 2)) ? 1 : 0;
        }
    }
    return $new_grid;
}

function simulate($grid) {
    while (true) {
        $grid = update_state($grid);
        foreach ($grid as $row) {
            echo implode(' ', array_map('strval', $row)) . "\n";
        }
        echo "\n";
    }
}

function main() {
    $initial_grid = [[0, 0, 0, 0, 0], [0, 1, 1, 0, 0], [0, 1, 1, 0, 0], [0, 0, 0, 0, 0], [0, 0, 0, 0, 0]];
    simulate($initial_grid);
}

main();
?>