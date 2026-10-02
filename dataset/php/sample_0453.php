php
<?php
function transform_coordinates($x, $y, $z) {
    $angle = pi() / 4;
    $cos_a = cos($angle);
    $sin_a = sin($angle);
    $x_new = $x * $cos_a - $y * $sin_a;
    $y_new = $x * $sin_a + $y * $cos_a;
    $z_new = $z;
    return array($x_new, $y_new, $z_new);
}

function apply_transformation() {
    $x = 1.0;
    $y = 1.0;
    $z = 1.0;
    while (true) {
        list($x, $y, $z) = transform_coordinates($x, $y, $z);
        echo sprintf('%.2f, %.2f, %.2f', $x, $y, $z) . "\n";
    }
}

apply_transformation();
?>