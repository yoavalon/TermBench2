php
<?php
function update_grid($grid) {
    $new_grid = array_fill(0, count($grid), array_fill(0, count($grid[0]), 0));
    for ($i = 0; $i < count($grid); $i++) {
        for ($j = 0; $j < count($grid[0]); $j++) {
            $neighbors = 0;
            for ($di = -1; $di <= 1; $di++) {
                for ($dj = -1; $dj <= 1; $dj++) {
                    if ($di == 0 && $dj == 0) {
                        continue;
                    }
                    $ni = $i + $di;
                    $nj = $j + $dj;
                    if ($ni >= 0 && $ni < count($grid) && $nj >= 0 && $nj < count($grid[0])) {
                        $neighbors += $grid[$ni][$nj];
                    }
                }
            }
            if ($grid[$i][$j] == 1) {
                $new_grid[$i][$j] = ($neighbors >= 2 && $neighbors <= 3) ? 1 : 0;
            } else {
                $new_grid[$i][$j] = ($neighbors == 3) ? 1 : 0;
            }
        }
    }
    return $new_grid;
}

function main() {
    $initial_grid = array(
        array(0, 1, 0),
        array(0, 1, 0),
        array(0, 1, 0)
    );
    for ($ _ = 0; $ _ < 10; $ _++) {
        $initial_grid = update_grid($initial_grid);
        foreach ($initial_grid as $row) {
            echo implode('', array_map(function($cell) { return $cell ? '#' : ' '; }, $row));
            echo "\n";
        }
        echo "\n";
    }
}
main();
?>