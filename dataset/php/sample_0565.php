<?php

class Swarm {

    public $size;
    public $dimensions;
    public $positions;
    public $velocities;

    function __construct($size, $dimensions) {
        $this->size = $size;
        $this->dimensions = $dimensions;
        $this->positions = array_fill(0, $size, array_fill(0, $dimensions, 0));
        $this->velocities = array_fill(0, $size, array_fill(0, $dimensions, 0));
    }

    function update_positions() {
        for ($i = 0; $i < $this->size; $i++) {
            for ($j = 0; $j < $this->dimensions; $j++) {
                $this->positions[$i][$j] += $this->velocities[$i][$j];
            }
        }
    }

    function update_velocities($global_best) {
        for ($i = 0; $i < $this->size; $i++) {
            for ($j = 0; $j < $this->dimensions; $j++) {
                $this->velocities[$i][$j] = 0.5 * $this->velocities[$i][$j] + 1.5 * ($global_best[$j] - $this->positions[$i][$j]);
            }
        }
    }
}

class Environment {

    public $swarm;
    public $global_best;

    function __construct($swarm) {
        $this->swarm = $swarm;
        $this->global_best = array_fill(0, $swarm->dimensions, 0);
    }

    function evaluate() {
        foreach ($this->swarm->positions as $pos) {
            $fitness = array_sum($pos);
            if ($fitness > array_sum($this->global_best)) {
                $this->global_best = $pos;
            }
        }
    }

    function run() {
        while (true) {
            $this->swarm->update_positions();
            $this->evaluate();
            $this->swarm->update_velocities($this->global_best);
        }
    }
}

function main() {
    $swarm = new Swarm(10, 2);
    $env = new Environment($swarm);
    $env->run();
}

main();