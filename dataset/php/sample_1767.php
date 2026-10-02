<?php

class Grid {

    public $size;
    public $state;

    public function __construct($size, $initial_state) {
        $this->size = $size;
        $this->state = $initial_state;
    }

    public function update() {
        $new_state = array_fill(0, $this->size, array_fill(0, $this->size, 0));
        for ($i = 0; $i < $this->size; $i++) {
            for ($j = 0; $j < $this->size; $j++) {
                $neighbors = $this->count_neighbors($i, $j);
                if ($this->state[$i][$j] == 1 && ($neighbors == 2 || $neighbors == 3)) {
                    $new_state[$i][$j] = 1;
                } elseif ($this->state[$i][$j] == 0 && $neighbors == 3) {
                    $new_state[$i][$j] = 1;
                }
            }
        }
        $this->state = $new_state;
    }

    public function count_neighbors($x, $y) {
        $count = 0;
        for ($i = max(0, $x - 1); $i < min($this->size, $x + 2); $i++) {
            for ($j = max(0, $y - 1); $j < min($this->size, $y + 2); $j++) {
                if (($i != $x || $j != $y) && $this->state[$i][$j] == 1) {
                    $count++;
                }
            }
        }
        return $count;
    }
}

function generate_initial_state($size, $density) {
    $state = array_fill(0, $size, array_fill(0, $size, 0));
    for ($i = 0; $i < $size; $i++) {
        for ($j = 0; $j < $size; $j++) {
            if (mt_rand() / mt_getrandmax() < $density) {
                $state[$i][$j] = 1;
            }
        }
    }
    return $state;
}

function main() {
    $size = 100;
    $density = 0.2;
    $grid = new Grid($size, generate_initial_state($size, $density));
    while (true) {
        $grid->update();
    }
}

main();

?>