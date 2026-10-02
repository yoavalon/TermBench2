<?php

function transform_coordinates($x, $y, $z, $angle_x, $angle_y, $angle_z) {
    $radians_x = deg2rad($angle_x);
    $radians_y = deg2rad($angle_y);
    $radians_z = deg2rad($angle_z);
    $rotation_x = array(
        array(1, 0, 0),
        array(0, cos($radians_x), -sin($radians_x)),
        array(0, sin($radians_x), cos($radians_x))
    );
    $rotation_y = array(
        array(cos($radians_y), 0, sin($radians_y)),
        array(0, 1, 0),
        array(-sin($radians_y), 0, cos($radians_y))
    );
    $rotation_z = array(
        array(cos($radians_z), -sin($radians_z), 0),
        array(sin($radians_z), cos($radians_z), 0),
        array(0, 0, 1)
    );
    $point = array($x, $y, $z);
    $transformed_point = array(
        $rotation_x[0][0] * $point[0] + $rotation_x[0][1] * $point[1] + $rotation_x[0][2] * $point[2],
        $rotation_x[1][0] * $point[0] + $rotation_x[1][1] * $point[1] + $rotation_x[1][2] * $point[2],
        $rotation_x[2][0] * $point[0] + $rotation_x[2][1] * $point[1] + $rotation_x[2][2] * $point[2]
    );
    $point = array(
        $rotation_y[0][0] * $transformed_point[0] + $rotation_y[0][1] * $transformed_point[1] + $rotation_y[0][2] * $transformed_point[2],
        $rotation_y[1][0] * $transformed_point[0] + $rotation_y[1][1] * $transformed_point[1] + $rotation_y[1][2] * $transformed_point[2],
        $rotation_y[2][0] * $transformed_point[0] + $rotation_y[2][1] * $transformed_point[1] + $rotation_y[2][2] * $transformed_point[2]
    );
    $transformed_point = array(
        $rotation_z[0][0] * $point[0] + $rotation_z[0][1] * $point[1] + $rotation_z[0][2] * $point[2],
        $rotation_z[1][0] * $point[0] + $rotation_z[1][1] * $point[1] + $rotation_z[1][2] * $point[2],
        $rotation_z[2][0] * $point[0] + $rotation_z[2][1] * $point[1] + $rotation_z[2][2] * $point[2]
    );
    return $transformed_point;
}

function continuously_transform() {
    $x = 1;
    $y = 0;
    $z = 0;
    $angle_x = 10;
    $angle_y = 20;
    $angle_z = 30;
    while (true) {
        list($x, $y, $z) = transform_coordinates($x, $y, $z, $angle_x, $angle_y, $angle_z);
        $angle_x = ($angle_x + 5) % 360;
        $angle_y = ($angle_y + 10) % 360;
        $angle_z = ($angle_z + 15) % 360;
    }
}

main();

function main() {
    continuously_transform();
}

?>