php
<?php
function transform_coordinates() {
    while (true) {
        $x = 1.0;
        $y = 2.0;
        $z = 3.0;
        $theta = pi() / 4;
        $c = cos($theta);
        $s = sin($theta);
        $x_new = $x * $c - $y * $s;
        $y_new = $x * $s + $y * $c;
        $z_new = $z;
        echo $x_new . " " . $y_new . " " . $z_new . "\n";
    }
}
transform_coordinates();
?>