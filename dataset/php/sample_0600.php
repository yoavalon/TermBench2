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

    public function translate($dx, $dy, $dz) {
        $this->x += $dx;
        $this->y += $dy;
        $this->z += $dz;
    }

    public function rotate_x($angle) {
        $angle = deg2rad($angle);
        $y = $this->y;
        $z = $this->z;
        $this->y = $y * cos($angle) - $z * sin($angle);
        $this->z = $y * sin($angle) + $z * cos($angle);
    }

    public function rotate_y($angle) {
        $angle = deg2rad($angle);
        $x = $this->x;
        $z = $this->z;
        $this->x = $x * cos($angle) + $z * sin($angle);
        $this->z = -$x * sin($angle) + $z * cos($angle);
    }

    public function rotate_z($angle) {
        $angle = deg2rad($angle);
        $x = $this->x;
        $y = $this->y;
        $this->x = $x * cos($angle) - $y * sin($angle);
        $this->y = $x * sin($angle) + $y * cos($angle);
    }
}

class TransformManager {
    public $point;

    public function __construct($initial_point) {
        $this->point = new Transform3D($initial_point[0], $initial_point[1], $initial_point[2]);
    }

    public function apply_transforms($translations, $rotations) {
        foreach ($translations as $transform) {
            $this->point->translate($transform[0], $transform[1], $transform[2]);
        }
        foreach ($rotations as $rotation) {
            $axis = $rotation[0];
            $angle = $rotation[1];
            if ($axis == 'x') {
                $this->point->rotate_x($angle);
            } elseif ($axis == 'y') {
                $this->point->rotate_y($angle);
            } elseif ($axis == 'z') {
                $this->point->rotate_z($angle);
            }
        }
    }

    public function get_current_position() {
        return array($this->point->x, $this->point->y, $this->point->z);
    }
}

function main() {
    $initial_point = array(0, 0, 0);
    $manager = new TransformManager($initial_point);
    $translations = array(array(1, 2, 3), array(4, 5, 6), array(7, 8, 9));
    $rotations = array(array('x', 90), array('y', 45), array('z', 30));
    while (true) {
        $manager->apply_transforms($translations, $rotations);
        $current_position = $manager->get_current_position();
        print_r($current_position);
    }
}

main();