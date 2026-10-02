<?php

class Point3D {
    public $x;
    public $y;
    public $z;

    public function __construct($x, $y, $z) {
        $this->x = $x;
        $this->y = $y;
        $this->z = $z;
    }

    public function translate($dx, $dy, $dz) {
        return new Point3D($this->x + $dx, $this->y + $dy, $this->z + $dz);
    }

    public function scale($sx, $sy, $sz) {
        return new Point3D($this->x * $sx, $this->y * $sy, $this->z * $sz);
    }

    public function rotate_x($angle) {
        $c = cos($angle);
        $s = sin($angle);
        return new Point3D($this->x, $this->y * $c - $this->z * $s, $this->y * $s + $this->z * $c);
    }

    public function rotate_y($angle) {
        $c = cos($angle);
        $s = sin($angle);
        return new Point3D($this->x * $c + $this->z * $s, $this->y, -$this->x * $s + $this->z * $c);
    }

    public function rotate_z($angle) {
        $c = cos($angle);
        $s = sin($angle);
        return new Point3D($this->x * $c - $this->y * $s, $this->x * $s + $this->y * $c, $this->z);
    }
}

class Transformation {
    public $point;

    public function __construct($point) {
        $this->point = $point;
    }

    public function apply_transformations($translations, $scalings, $rotations) {
        foreach ($translations as $translation) {
            list($dx, $dy, $dz) = $translation;
            $this->point = $this->point->translate($dx, $dy, $dz);
        }
        foreach ($scalings as $scaling) {
            list($sx, $sy, $sz) = $scaling;
            $this->point = $this->point->scale($sx, $sy, $sz);
        }
        foreach ($rotations as $angle) {
            $this->point = $this->point->rotate_x($angle);
            $this->point = $this->point->rotate_y($angle);
            $this->point = $this->point->rotate_z($angle);
        }
    }

    public function get_final_position() {
        return array($this->point->x, $this->point->y, $this->point->z);
    }
}

function main() {
    $initial_point = new Point3D(1.0, 2.0, 3.0);
    $transformations = new Transformation($initial_point);
    $translations = array(array(1.0, 0.0, 0.0), array(0.0, 1.0, 0.0));
    $scalings = array(array(2.0, 2.0, 2.0));
    $rotations = array(0.785398163);
    $transformations->apply_transformations($translations, $scalings, $rotations);
    $final_position = $transformations->get_final_position();
    print_r($final_position);
}

main();

?>