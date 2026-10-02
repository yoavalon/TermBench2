<?php
function cellular_automata($grid, $steps) {
    if ($steps == 0) {
        return $grid;
    }
    $new_grid = array_fill(0, count($grid), array_fill(0, count($grid[0]), 0));
    for ($i = 0; $i < count($grid); $i++) {
        for ($j = 0; $j < count($grid[0]); $j++) {
            $neighbors = 0;
            foreach (array(array($i - 1, $j), array($i + 1, $j), array($i, $j - 1), array($i, $j + 1)) as $neighbor) {
                list($x, $y) = $neighbor;
                if ($x >= 0 && $x < count($grid) && $y >= 0 && $y < count($grid[0])) {
                    $neighbors += $grid[$x][$y];
                }
            }
            $new_grid[$i][$j] = ($neighbors == 3 || ($grid[$i][$j] == 1 && $neighbors == 2)) ? 1 : 0;
        }
    }
    return cellular_automata($new_grid, $steps - 1);
}
$grid = array(
    array(0, 0, 0, 0, 0),
    array(0, 1, 1, 1, 0),
    array(0, 0, 1, 0, 0),
    array(0, 0, 1, 0, 0),
    array(0, 0, 0, 0, 0)
);
$result = cellular_automata($grid, 10);
foreach ($result as $row) {
    print_r($row);
}
?>