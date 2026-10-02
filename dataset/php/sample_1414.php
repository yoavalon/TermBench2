<?php

class Swarm {

    public $size;
    public $dimensions;
    public $positions;
    public $velocities;
    public $best_positions;
    public $best_score;

    function __construct($size, $dimensions) {
        $this->size = $size;
        $this->dimensions = $dimensions;
        $this->positions = array_fill(0, $size, array_fill(0, $dimensions, rand() / getrandmax()));
        $this->velocities = array_fill(0, $size, array_fill(0, $dimensions, rand() / getrandmax()));
        $this->best_positions = array_map('array_copy', $this->positions);
        $this->best_score = INF;
    }

    function update_personal_best($score) {
        if ($score < $this->best_score) {
            $this->best_score = $score;
            $this->best_positions = array_map('array_copy', $this->positions);
        }
    }

    function update_velocity($global_best) {
        $inertia = 0.5;
        $cognitive = 1.5;
        $social = 1.5;
        for ($i = 0; $i < $this->size; $i++) {
            for ($j = 0; $j < $this->dimensions; $j++) {
                $r1 = rand() / getrandmax();
                $r2 = rand() / getrandmax();
                $this->velocities[$i][$j] = $inertia * $this->velocities[$i][$j] + $cognitive * $r1 * ($this->best_positions[$i][$j] - $this->positions[$i][$j]) + $social * $r2 * ($global_best[$j] - $this->positions[$i][$j]);
            }
        }
    }

    function update_position() {
        for ($i = 0; $i < $this->size; $i++) {
            for ($j = 0; $j < $this->dimensions; $j++) {
                $this->positions[$i][$j] += $this->velocities[$i][$j];
            }
        }
    }
}

class Environment {

    public $swarm;

    function __construct($swarm) {
        $this->swarm = $swarm;
    }

    function evaluate() {
        $scores = array();
        foreach ($this->swarm->positions as $position) {
            $score = 0;
            foreach ($position as $x) {
                $score += pow($x, 2);
            }
            $scores[] = $score;
        }
        return $scores;
    }

    function find_global_best($scores) {
        $global_best_index = array_search(min($scores), $scores);
        return $this->swarm->positions[$global_best_index];
    }
}

function main() {
    $swarm = new Swarm(10, 3);
    $environment = new Environment($swarm);
    $iterations = 50;
    for ($i = 0; $i < $iterations; $i++) {
        $scores = $environment->evaluate();
        $global_best = $environment->find_global_best($scores);
        $swarm->update_personal_best(min($scores));
        $swarm->update_velocity($global_best);
        $swarm->update_position();
    }
    echo 'Best score: ' . $swarm->best_score . PHP_EOL;
}

main();