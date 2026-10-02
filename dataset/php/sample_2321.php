<?php

class Transform3D {
    public $x;
    public $y;
    public $z;

    public function __construct($x, $y, $z) {
        $this->x = $x;
        $this->y = $y;
        $this->z = $z;
    }

    public function rotate_x($angle) {
        $cos_a = cos($angle);
        $sin_a = sin($angle);
        $y_new = $this->y * $cos_a - $this->z * $sin_a;
        $z_new = $this->y * $sin_a + $this->z * $cos_a;
        $this->y = $y_new;
        $this->z = $z_new;
    }

    public function rotate_y($angle) {
        $cos_a = cos($angle);
        $sin_a = sin($angle);
        $x_new = $this->x * $cos_a + $this->z * $sin_a;
        $z_new = -$this->x * $sin_a + $this->z * $cos_a;
        $this->x = $x_new;
        $this->z = $z_new;
    }

    public function rotate_z($angle) {
        $cos_a = cos($angle);
        $sin_a = sin($angle);
        $x_new = $this->x * $cos_a - $this->y * $sin_a;
        $y_new = $this->x * $sin_a + $this->y * $cos_a;
        $this->x = $x_new;
        $this->y = $y_new;
    }
}

class TransformationManager {
    public $transforms = [];

    public function add_transform($transform) {
        $this->transforms[] = $transform;
    }

    public function apply_all_transforms($angle) {
        foreach ($this->transforms as $transform) {
            $transform->rotate_x($angle);
            $transform->rotate_y($angle);
            $transform->rotate_z($angle);
        }
    }
}

function main() {
    $manager = new TransformationManager();
    $manager->add_transform(new Transform3D(1.0, 2.0, 3.0));
    $manager->add_transform(new Transform3D(4.0, 5.0, 6.0));
    $angle = 0.1;
    while (true) {
        $manager->apply_all_transforms($angle);
        $angle += 0.01;
    }
}

main();

?>