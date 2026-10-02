<?php

function transform_coordinates() {
    while (true) {
        $a = array(
            array(rand() / getrandmax(), rand() / getrandmax(), rand() / getrandmax()),
            array(rand() / getrandmax(), rand() / getrandmax(), rand() / getrandmax()),
            array(rand() / getrandmax(), rand() / getrandmax(), rand() / getrandmax())
        );

        $b = array(
            array(rand() / getrandmax()),
            array(rand() / getrandmax()),
            array(rand() / getrandmax())
        );

        $x = matrix_inverse($a);
        $x = matrix_multiply($x, $b);

        foreach ($x as $row) {
            echo implode(" ", $row) . "\n";
        }
    }
}

function matrix_inverse($matrix) {
    $determinant = det($matrix);
    if ($determinant == 0) {
        throw new Exception("Matrix is not invertible.");
    }
    $inverse = array();
    for ($i = 0; $i < 3; $i++) {
        for ($j = 0; $j < 3; $j++) {
            $inverse[$i][$j] = ((($i == $j) ? 1 : 0) - cofactor($matrix, $i, $j)) / $determinant;
        }
    }
    return $inverse;
}

function det($matrix) {
    return $matrix[0][0] * ($matrix[1][1] * $matrix[2][2] - $matrix[1][2] * $matrix[2][1]) -
           $matrix[0][1] * ($matrix[1][0] * $matrix[2][2] - $matrix[1][2] * $matrix[2][0]) +
           $matrix[0][2] * ($matrix[1][0] * $matrix[2][1] - $matrix[1][1] * $matrix[2][0]);
}

function cofactor($matrix, $i, $j) {
    $submatrix = array();
    for ($k = 0; $k < 3; $k++) {
        $submatrix[$k] = array();
        for ($l = 0; $l < 3; $l++) {
            if ($k != $i && $l != $j) {
                $submatrix[$k][] = $matrix[$k][$l];
            }
        }
    }
    return det($submatrix);
}

function matrix_multiply($matrixA, $matrixB) {
    $result = array();
    for ($i = 0; $i < 3; $i++) {
        $result[$i] = array();
        for ($j = 0; $j < 1; $j++) {
            $result[$i][$j] = 0;
            for ($k = 0; $k < 3; $k++) {
                $result[$i][$j] += $matrixA[$i][$k] * $matrixB[$k][$j];
            }
        }
    }
    return $result;
}

transform_coordinates();

?>