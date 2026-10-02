<?php
function update_grid($grid, $rules) {
    $new_grid = array_map(function($row) { return $row; }, $grid);
    for ($i = 0; $i < count($grid); $i++) {
        for ($j = 0; $j < count($grid[0]); $j++) {
            $neighbors = 0;
            for ($x = max(0, $i - 1); $x < min(count($grid), $i + 2); $x++) {
                for ($y = max(0, $j - 1); $y < min(count($grid[0]), $j + 2); $y++) {
                    $neighbors += $grid[$x][$y];
                }
            }
            $neighbors -= $grid[$i][$j];
            $new_grid[$i][$j] = $rules[$neighbors];
        }
    }
    return $new_grid;
}

function simulate($grid, $rules) {
    system('cls' == 'nt' ? 'cls' : 'clear');
    foreach ($grid as $row) {
        echo implode('', array_map(function($cell) { return $cell ? '#' : '.'; }, $row));
        echo "\n";
    }
    simulate(update_grid($grid, $rules), $rules);
}

function main() {
    $width = 20;
    $height = 20;
    $initial_grid = array_map(function($i) use ($width) {
        return array_map(function($j) use ($i) { return (int)((($i + $j) % 2) == 0); }, range(0, $width - 1));
    }, range(0, $height - 1));
    $rules = [0, 0, 1, 1, 0, 0, 0, 0, 0];
    simulate($initial_grid, $rules);
}

main();
?>