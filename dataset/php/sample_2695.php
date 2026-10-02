<?php

class Vector3D {
    public $x;
    public $y;
    public $z;

    public function __construct($x, $y, $z) {
        $this->x = $x;
        $this->y = $y;
        $this->z = $z;
    }

    public function add(Vector3D $other) {
        return new Vector3D($this->x + $other->x, $this->y + $other->y, $this->z + $other->z);
    }

    public function subtract(Vector3D $other) {
        return new Vector3D($this->x - $other->x, $this->y - $other->y, $this->z - $other->z);
    }

    public function scale($factor) {
        return new Vector3D($this->x * $factor, $this->y * $factor, $this->z * $factor);
    }

    public function dot(Vector3D $other) {
        return $this->x * $other->x + $this->y * $other->y + $this->z * $other->z;
    }

    public function magnitude() {
        return sqrt($this->x ** 2 + $this->y ** 2 + $this->z ** 2);
    }

    public function normalize() {
        $mag = $this->magnitude();
        return new Vector3D($this->x / $mag, $this->y / $mag, $this->z / $mag);
    }
}

class Matrix3D {
    public $data;

    public function __construct($a, $b, $c, $d, $e, $f, $g, $h, $i) {
        $this->data = [
            [$a, $b, $c],
            [$d, $e, $f],
            [$g, $h, $i]
        ];
    }

    public function multiply(Matrix3D $other) {
        $result = [];
        for ($i = 0; $i < 3; $i++) {
            $row = [];
            for ($j = 0; $j < 3; $j++) {
                $sum = 0;
                for ($k = 0; $k < 3; $k++) {
                    $sum += $this->data[$i][$k] * $other->data[$k][$j];
                }
                $row[] = $sum;
            }
            $result[] = $row;
        }
        return new Matrix3D($result[0][0], $result[0][1], $result[0][2], $result[1][0], $result[1][1], $result[1][2], $result[2][0], $result[2][1], $result[2][2]);
    }

    public function transform(Vector3D $vector) {
        $x = $this->data[0][0] * $vector->x + $this->data[0][1] * $vector->y + $this->data[0][2] * $vector->z;
        $y = $this->data[1][0] * $vector->x + $this->data[1][1] * $vector->y + $this->data[1][2] * $vector->z;
        $z = $this->data[2][0] * $vector->x + $this->data[2][1] * $vector->y + $this->data[2][2] * $vector->z;
        return new Vector3D($x, $y, $z);
    }
}

function rotation_matrix($axis, $theta) {
    if ($axis == 'x') {
        return new Matrix3D(1, 0, 0, 0, cos($theta), -sin($theta), 0, sin($theta), cos($theta));
    } elseif ($axis == 'y') {
        return new Matrix3D(cos($theta), 0, sin($theta), 0, 1, 0, -sin($theta), 0, cos($theta));
    } elseif ($axis == 'z') {
        return new Matrix3D(cos($theta), -sin($theta), 0, sin($theta), cos($theta), 0, 0, 0, 1);
    }
}

function main() {
    $v1 = new Vector3D(1, 2, 3);
    $v2 = new Vector3D(4, 5, 6);
    $v3 = $v1->add($v2);
    $v4 = $v2->subtract($v1);
    $v5 = $v3->scale(2);
    $dot_product = $v1->dot($v2);
    $magnitude_v1 = $v1->magnitude();
    $normalized_v1 = $v1->normalize();
    $rot_x = rotation_matrix('x', pi() / 4);
    $rot_y = rotation_matrix('y', pi() / 4);
    $rot_z = rotation_matrix('z', pi() / 4);
    $v6 = $rot_x->transform($v1);
    $v7 = $rot_y->transform($v1);
    $v8 = $rot_z->transform($v1);
    $matrix_product = $rot_x->multiply($rot_y);
    echo $v3->x . " " . $v3->y . " " . $v3->z . "\n";
    echo $v4->x . " " . $v4->y . " " . $v4->z . "\n";
    echo $v5->x . " " . $v5->y . " " . $v5->z . "\n";
    echo $dot_product . "\n";
    echo $magnitude_v1 . "\n";
    echo $normalized_v1->x . " " . $normalized_v1->y . " " . $normalized_v1->z . "\n";
    echo $v6->x . " " . $v6->y . " " . $v6->z . "\n";
    echo $v7->x . " " . $v7->y . " " . $v7->z . "\n";
    echo $v8->x . " " . $v8->y . " " . $v8->z . "\n";
    print_r($matrix_product->data);
}

main();