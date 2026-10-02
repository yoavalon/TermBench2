<?php
function update_cells($state) {
    $new_state = array_fill(0, count($state), array_fill(0, count($state[0]), 0));
    for ($i = 0; $i < count($state); $i++) {
        for ($j = 0; $j < count($state[0]); $j++) {
            $neighbors = 0;
            for ($x = max(0, $i - 1); $x < min(count($state), $i + 2); $x++) {
                for ($y = max(0, $j - 1); $y < min(count($state[0]), $j + 2); $y++) {
                    if ($x != $i || $y != $j) {
                        $neighbors += $state[$x][$y];
                    }
                }
            }
            $new_state[$i][$j] = ($neighbors == 3 || ($neighbors == 2 && $state[$i][$j])) ? 1 : 0;
        }
    }
    return $new_state;
}

function simulate($state) {
    while (true) {
        $state = update_cells($state);
        foreach ($state as $row) {
            echo implode('', array_map(function($cell) { return $cell ? '█' : ' '; }, $row));
            echo "\n";
        }
        echo "\n";
    }
}

function main() {
    $initial_state = [
        [0, 0, 0, 0, 0],
        [0, 1, 1, 1, 0],
        [0, 0, 1, 0, 0],
        [0, 0, 1, 0, 0],
        [0, 0, 0, 0, 0]
    ];
    simulate($initial_state);
}

main();
?>