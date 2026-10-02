<?php

class Transform3D {
    public $x, $y, $z;

    public function __construct($x, $y, $z) {
        $this->x = $x;
        $this->y = $y;
        $this->z = $z;
    }

    public function rotate_x($angle) {
        $cos_a = cos($angle);
        $sin_a = sin($angle);
        $new_y = $this->y * $cos_a - $this->z * $sin_a;
        $new_z = $this->y * $sin_a + $this->z * $cos_a;
        return new Transform3D($this->x, $new_y, $new_z);
    }

    public function rotate_y($angle) {
        $cos_a = cos($angle);
        $sin_a = sin($angle);
        $new_x = $this->x * $cos_a + $this->z * $sin_a;
        $new_z = -$this->x * $sin_a + $this->z * $cos_a;
        return new Transform3D($new_x, $this->y, $new_z);
    }

    public function rotate_z($angle) {
        $cos_a = cos($angle);
        $sin_a = sin($angle);
        $new_x = $this->x * $cos_a - $this->y * $sin_a;
        $new_y = $this->x * $sin_a + $this->y * $cos_a;
        return new Transform3D($new_x, $new_y, $this->z);
    }
}

class TransformHandler {
    public $points;

    public function __construct($points) {
        $this->points = array_map(function($point) {
            return new Transform3D($point[0], $point[1], $point[2]);
        }, $points);
    }

    public function apply_rotation($angle_x, $angle_y, $angle_z) {
        $rotated_points = [];
        foreach ($this->points as $point) {
            $rotated = $point->rotate_x($angle_x)->rotate_y($angle_y)->rotate_z($angle_z);
            $rotated_points[] = [$rotated->x, $rotated->y, $rotated->z];
        }
        return $rotated_points;
    }
}

function main() {
    $initial_points = [[1, 0, 0], [0, 1, 0], [0, 0, 1]];
    $handler = new TransformHandler($initial_points);
    $angles = [pi() / 4, pi() / 4, pi() / 4];
    $result = $handler->apply_rotation(...$angles);
    foreach ($result as $point) {
        print_r($point);
    }
}

main();

?>