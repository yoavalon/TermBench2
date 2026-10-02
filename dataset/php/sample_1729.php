<?php

class Swarm {
    public $particles;
    public $best;

    public function __construct($size) {
        $this->particles = array();
        for ($i = 0; $i < $size; $i++) {
            $this->particles[] = new Particle(rand(-1, 1) / 10, rand(-1, 1) / 10);
        }
        $this->best = $this->findBest();
    }

    public function findBest() {
        $bestParticle = null;
        $bestValue = PHP_INT_MAX;
        foreach ($this->particles as $particle) {
            $value = $particle->evaluate();
            if ($value < $bestValue) {
                $bestValue = $value;
                $bestParticle = $particle;
            }
        }
        return $bestParticle;
    }

    public function update() {
        foreach ($this->particles as $particle) {
            $particle->update_velocity($this->best);
            $particle->move();
        }
        $this->best = $this->findBest();
    }
}

class Particle {
    public $position;
    public $velocity;
    public $best;

    public function __construct($x, $y) {
        $this->position = array($x, $y);
        $this->velocity = array(rand(-1, 1) / 100, rand(-1, 1) / 100);
        $this->best = $this->position;
    }

    public function evaluate() {
        return -($this->position[0] ** 2 + $this->position[1] ** 2);
    }

    public function update_velocity($global_best) {
        $inertia = 0.7;
        $cognitive = 1.5;
        $social = 1.5;
        for ($i = 0; $i < count($this->velocity); $i++) {
            $r1 = rand() / getrandmax();
            $r2 = rand() / getrandmax();
            $cognitive_component = $cognitive * $r1 * ($this->best[$i] - $this->position[$i]);
            $social_component = $social * $r2 * ($global_best->position[$i] - $this->position[$i]);
            $this->velocity[$i] = $inertia * $this->velocity[$i] + $cognitive_component + $social_component;
        }
    }

    public function move() {
        for ($i = 0; $i < count($this->position); $i++) {
            $this->position[$i] += $this->velocity[$i];
            $this->position[$i] = max(-1, min(1, $this->position[$i]));
        }
        if ($this->evaluate() < $this->best[0]) {
            $this->best = $this->position;
        }
    }
}

function run() {
    $swarm_size = 30;
    $swarm = new Swarm($swarm_size);
    while (true) {
        $swarm->update();
    }
}

run();

?>