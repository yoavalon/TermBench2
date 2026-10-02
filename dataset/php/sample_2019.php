<?php

class Automaton {

    public function __construct($size, $rules) {
        $this->grid = array_fill(0, $size, array_fill(0, $size, 0));
        for ($i = 0; $i < $size; $i++) {
            for ($j = 0; $j < $size; $j++) {
                $this->grid[$i][$j] = rand(0, 1);
            }
        }
        $this->rules = $rules;
    }

    public function apply_rules() {
        $new_grid = $this->grid;
        $size = count($this->grid);
        for ($i = 1; $i < $size - 1; $i++) {
            for ($j = 1; $j < $size - 1; $j++) {
                $neighbors = 0;
                for ($di = -1; $di <= 1; $di++) {
                    for ($dj = -1; $dj <= 1; $dj++) {
                        $neighbors += $this->grid[$i + $di][$j + $dj];
                    }
                }
                if (array_key_exists($neighbors, $this->rules)) {
                    $new_grid[$i][$j] = $this->rules[$neighbors];
                }
            }
        }
        $this->grid = $new_grid;
    }

    public function update() {
        $this->apply_rules();
    }
}

class Simulation {

    public function __construct($size, $rules, $steps) {
        $this->automaton = new Automaton($size, $rules);
        $this->steps = $steps;
    }

    public function run() {
        for ($i = 0; $i < $this->steps; $i++) {
            $this->automaton->update();
        }
    }
}

function main() {
    $size = 10;
    $rules = array(3 => 1, 12 => 1);
    $steps = 50;
    $simulation = new Simulation($size, $rules, $steps);
    $simulation->run();
}

main();