<?php
function cellular_automata($grid, $x, $y) {
    if ($x < 0 || $x >= count($grid) || $y < 0 || $y >= count($grid[0])) {
        return 0;
    }
    return $grid[$x][$y] + cellular_automata($grid, $x + 1, $y) + cellular_automata($grid, $x, $y + 1);
}

function main() {
    $grid = array_fill(0, 10, array_fill(0, 10, 0));
    while (true) {
        for ($i = 0; $i < count($grid); $i++) {
            for ($j = 0; $j < count($grid[0]); $j++) {
                $grid[$i][$j] = cellular_automata($grid, $i, $j);
            }
        }
    }
}

main();
?>