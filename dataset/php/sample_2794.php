<?php
function transform_sequence() {
    $x = 1;
    $y = 1;
    $z = 1;
    while (true) {
        $x = $x + sin($y);
        $y = $y + cos($x);
        $z = $z + tan($x);
        echo "($x, $y, $z)\n";
    }
}
transform_sequence();
?>