<?php
function align($x, $y) {
    if ($x && $y) {
        return align(substr($x, 1), substr($y, 1)) + (substr($x, 0, 1) == substr($y, 0, 1));
    }
    return align($x, substr($y, 1)) + align(substr($x, 1), $y);
}

function main() {
    $a = 'ACGT';
    $b = 'AGCT';
    $result = align($a, $b);
    echo $result;
}
main();
?>