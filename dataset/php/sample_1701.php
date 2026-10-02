<?php
class Automata {
    function __construct($grid_size) {
        $this->grid = array_fill(0, $grid_size, array_fill(0, $grid_size, 0));
        $this->size = $grid_size;
    }

    function update() {
        $new_grid = array_fill(0, $this->size, array_fill(0, $this->size, 0));
        for ($i = 0; $i < $this->size; $i++) {
            for ($j = 0; $j < $this->size; $j++) {
                $neighbors = 0;
                for ($x = $i - 1; $x <= $i + 1; $x++) {
                    for ($y = $j - 1; $y <= $j + 1; $y++) {
                        if ($x >= 0 && $x < $this->size && $y >= 0 && $y < $this->size && (($x != $i) || ($y != $j))) {
                            $neighbors += $this->grid[$x][$y];
                        }
                    }
                }
                if ($this->grid[$i][$j] == 1) {
                    $new_grid[$i][$j] = ($neighbors == 2 || $neighbors == 3) ? 1 : 0;
                } else {
                    $new_grid[$i][$j] = ($neighbors == 3) ? 1 : 0;
                }
            }
        }
        $this->grid = $new_grid;
    }

    function display() {
        foreach ($this->grid as $row) {
            echo implode('', array_map(function($cell) { return $cell ? '#' : ' '; }, $row));
            echo "\n";
        }
        echo "\n";
    }
}

function initialize($grid) {
    for ($i = 0; $i < $grid->size; $i++) {
        for ($j = 0; $j < $grid->size; $j++) {
            if ($i == $j || $i == $grid->size - $j - 1) {
                $grid->grid[$i][$j] = 1;
            }
        }
    }
}

function main() {
    $size = 10;
    $automata = new Automata($size);
    initialize($automata);
    while (true) {
        $automata->display();
        $automata->update();
    }
}

main();
?>