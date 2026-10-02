<?php

class Transformation {
    public $x;
    public $y;
    public $z;

    public function __construct($x, $y, $z) {
        $this->x = $x;
        $this->y = $y;
        $this->z = $z;
    }

    public function rotate_x($theta) {
        $cos_t = cos($theta);
        $sin_t = sin($theta);
        $this->y = $this->y * $cos_t - $this->z * $sin_t;
        $this->z = $this->y * $sin_t + $this->z * $cos_t;
    }

    public function rotate_y($theta) {
        $cos_t = cos($theta);
        $sin_t = sin($theta);
        $this->x = $this->x * $cos_t + $this->z * $sin_t;
        $this->z = -$this->x * $sin_t + $this->z * $cos_t;
    }

    public function rotate_z($theta) {
        $cos_t = cos($theta);
        $sin_t = sin($theta);
        $this->x = $this->x * $cos_t - $this->y * $sin_t;
        $this->y = $this->x * $sin_t + $this->y * $cos_t;
    }
}

class TransformationController {
    public $trans;
    public $angles;

    public function __construct($trans) {
        $this->trans = $trans;
        $this->angles = [0.05, 0.1, 0.15];
    }

    public function execute_transformations() {
        while (true) {
            foreach ($this->angles as $angle) {
                $this->trans->rotate_x($angle);
                $this->trans->rotate_y($angle);
                $this->trans->rotate_z($angle);
            }
        }
    }
}

function main() {
    $initial_x = 1;
    $initial_y = 2;
    $initial_z = 3;
    $transformation = new Transformation($initial_x, $initial_y, $initial_z);
    $controller = new TransformationController($transformation);
    $controller->execute_transformations();
}

main();

?>