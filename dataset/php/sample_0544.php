<?php

class Grid {
    public $size;
    public $state;

    function __construct($size) {
        $this->size = $size;
        $this->state = array_fill(0, $size, array_fill(0, $size, 0));
    }

    function update() {
        $new_state = array_fill(0, $this->size, array_fill(0, $this->size, 0));
        for ($i = 0; $i < $this->size; $i++) {
            for ($j = 0; $j < $this->size; $j++) {
                $neighbors = $this->get_neighbors($i, $j);
                if ($this->state[$i][$j] == 0 && $neighbors == 3) {
                    $new_state[$i][$j] = 1;
                } elseif ($this->state[$i][$j] == 1 && ($neighbors < 2 || $neighbors > 3)) {
                    $new_state[$i][$j] = 0;
                } else {
                    $new_state[$i][$j] = $this->state[$i][$j];
                }
            }
        }
        $this->state = $new_state;
    }

    function get_neighbors($x, $y) {
        $count = 0;
        for ($i = max(0, $x - 1); $i < min($x + 2, $this->size); $i++) {
            for ($j = max(0, $y - 1); $j < min($y + 2, $this->size); $j++) {
                if (($i, $j) != ($x, $y) && $this->state[$i][$j] == 1) {
                    $count += 1;
                }
            }
        }
        return $count;
    }
}

function display($grid) {
    foreach ($grid->state as $row) {
        echo implode('', array_map(function($cell) { return $cell ? '*' : ' '; }, $row)) . "\n";
    }
    echo "\n";
}

function main() {
    $size = 10;
    $grid = new Grid($size);
    for ($i = 0; $i < $size; $i++) {
        for ($j = 0; $j < $size; $j++) {
            if ($i % 2 == 0 && $j % 2 == 0) {
                $grid->state[$i][$j] = 1;
            }
        }
    }
    while (true) {
        display($grid);
        $grid->update();
    }
}

main();

?>