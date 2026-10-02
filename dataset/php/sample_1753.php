<?php

class Automaton {
    public $grid;
    public $size;

    function __construct($size) {
        $this->grid = array_fill(0, $size, array_fill(0, $size, 0));
        $this->size = $size;
    }

    function update() {
        $new_grid = array_fill(0, $this->size, array_fill(0, $this->size, 0));
        for ($i = 0; $i < $this->size; $i++) {
            for ($j = 0; $j < $this->size; $j++) {
                $neighbors = $this->count_neighbors($i, $j);
                if ($this->grid[$i][$j] == 1) {
                    if ($neighbors < 2 || $neighbors > 3) {
                        $new_grid[$i][$j] = 0;
                    } else {
                        $new_grid[$i][$j] = 1;
                    }
                } elseif ($neighbors == 3) {
                    $new_grid[$i][$j] = 1;
                }
            }
        }
        $this->grid = $new_grid;
    }

    function count_neighbors($x, $y) {
        $count = 0;
        for ($i = max(0, $x - 1); $i < min($this->size, $x + 2); $i++) {
            for ($j = max(0, $y - 1); $j < min($this->size, $y + 2); $j++) {
                if (($i, $j) != ($x, $y) && $this->grid[$i][$j] == 1) {
                    $count++;
                }
            }
        }
        return $count;
    }
}

class Simulator {
    public $automaton;

    function __construct($automaton) {
        $this->automaton = $automaton;
    }

    function run() {
        while (true) {
            $this->automaton->update();
        }
    }
}

function main() {
    $size = 10;
    $automaton = new Automaton($size);
    $simulator = new Simulator($automaton);
    $simulator->run();
}

main();

?>