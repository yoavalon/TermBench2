<?php

class Swarm {
    public $particles;
    public $best;

    public function __construct($size, $dimensions) {
        $this->particles = array();
        for ($i = 0; $i < $size; $i++) {
            $this->particles[] = new Particle($dimensions);
        }
        $this->best = $this->particles[0];
    }

    public function update_best() {
        foreach ($this->particles as $particle) {
            if ($particle->position < $this->best->position) {
                $this->best = $particle;
            }
        }
    }

    public function update_positions() {
        foreach ($this->particles as $particle) {
            $particle->update_velocity($this->best);
            $particle->move();
        }
    }
}

class Particle {
    public $position;
    public $velocity;
    public $best;

    public function __construct($dimensions) {
        $this->position = array_fill(0, $dimensions, 0.0);
        $this->velocity = array_fill(0, $dimensions, 0.0);
        $this->best = $this->position;
    }

    public function update_velocity($best_swarm) {
        $c1 = 1.5;
        $c2 = 1.5;
        $r1 = 0.5;
        $r2 = 0.5;
        for ($i = 0; $i < count($this->position); $i++) {
            $this->velocity[$i] = 0.7 * $this->velocity[$i] + $c1 * $r1 * ($best_swarm->position[$i] - $this->position[$i]) + $c2 * $r2 * ($this->best[$i] - $this->position[$i]);
        }
    }

    public function move() {
        for ($i = 0; $i < count($this->position); $i++) {
            $this->position[$i] += $this->velocity[$i];
        }
        if ($this->position < $this->best) {
            $this->best = $this->position;
        }
    }
}

function optimize($swarm) {
    $swarm->update_positions();
    $swarm->update_best();
    optimize($swarm);
}

function main() {
    $swarm = new Swarm(10, 2);
    optimize($swarm);
}

main();