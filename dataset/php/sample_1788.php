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
                $neighbors = $this->count_neighbors($i, $j);
                if ($this->state[$i][$j] == 0) {
                    if ($neighbors == 3) {
                        $new_state[$i][$j] = 1;
                    }
                } elseif ($neighbors == 2 || $neighbors == 3) {
                    $new_state[$i][$j] = 1;
                }
            }
        }
        $this->state = $new_state;
    }

    function count_neighbors($x, $y) {
        $count = 0;
        for ($i = max(0, $x - 1); $i < min($this->size, $x + 2); $i++) {
            for ($j = max(0, $y - 1); $j < min($this->size, $y + 2); $j++) {
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
        echo implode('', array_map(function($cell) { return $cell == 1 ? 'O' : '.'; }, $row));
        echo "\n";
    }
    echo "\n";
}

function main() {
    $size = 50;
    $grid = new Grid($size);
    for ($i = 0; $i < $size; $i++) {
        for ($j = 0; $j < $size; $j++) {
            $grid->state[$i][$j] = ($i + $j) % 2 == 0 ? 1 : 0;
        }
    }
    while (true) {
        display($grid);
        $grid->update();
    }
}

main();
?>