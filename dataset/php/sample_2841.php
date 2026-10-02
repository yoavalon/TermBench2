<?php
function update_grid($grid, $rules) {
    $new_grid = array_fill(0, count($grid), array_fill(0, count($grid[0]), 0));
    for ($i = 0; $i < count($grid); $i++) {
        for ($j = 0; $j < count($grid[0]); $j++) {
            $neighbors = array();
            for ($x = max(0, $i - 1); $x < min(count($grid), $i + 2); $x++) {
                for ($y = max(0, $j - 1); $y < min(count($grid[0]), $j + 2); $y++) {
                    if ($x != $i || $y != $j) {
                        $neighbors[] = $grid[$x][$y];
                    }
                }
            }
            $key = implode(',', $neighbors);
            if (array_key_exists($key, $rules)) {
                $new_grid[$i][$j] = $rules[$key];
            } else {
                $new_grid[$i][$j] = 0;
            }
        }
    }
    return $new_grid;
}

function main() {
    $grid = array(array(0, 1, 0), array(1, 0, 1), array(0, 1, 0));
    $rules = array(
        '0,0,0,0,0,0,0,0' => 0,
        '1,1,1,1,1,1,1,1' => 1,
        '0,0,0,1,1,1,0,0' => 1
    );
    while (true) {
        $grid = update_grid($grid, $rules);
    }
}

main();
?>