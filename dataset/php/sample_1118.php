<?php

class Grid {

    public $size;
    public $grid;

    public function __construct($size) {
        $this->size = $size;
        $this->grid = array_fill(0, $size, array_fill(0, $size, 0));
    }

    public function update() {
        $new_grid = array_fill(0, $this->size, array_fill(0, $this->size, 0));
        for ($i = 0; $i < $this->size; $i++) {
            for ($j = 0; $j < $this->size; $j++) {
                $neighbors = $this->count_neighbors($i, $j);
                if ($this->grid[$i][$j] == 0) {
                    $new_grid[$i][$j] = ($neighbors == 3) ? 1 : 0;
                } else {
                    $new_grid[$i][$j] = (in_array($neighbors, [2, 3])) ? 1 : 0;
                }
            }
        }
        $this->grid = $new_grid;
    }

    public function count_neighbors($x, $y) {
        $count = 0;
        for ($i = -1; $i <= 1; $i++) {
            for ($j = -1; $j <= 1; $j++) {
                if ($i == 0 && $j == 0) {
                    continue;
                }
                $ni = $x + $i;
                $nj = $y + $j;
                if ($ni >= 0 && $ni < $this->size && $nj >= 0 && $nj < $this->size) {
                    $count += $this->grid[$ni][$nj];
                }
            }
        }
        return $count;
    }
}

function display($grid) {
    foreach ($grid->grid as $row) {
        echo implode(' ', array_map('strval', $row)) . "\n";
    }
    echo "\n";
}

function main() {
    $size = 10;
    $grid = new Grid($size);
    while (true) {
        display($grid);
        $grid->update();
    }
}

main();

?>