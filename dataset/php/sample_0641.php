<?php
function transform_3d($x, $y, $z, $n) {
    if ($n == 0) {
        return array($x, $y, $z);
    } else {
        return transform_3d($x + 1, $y + 1, $z + 1, $n - 1);
    }
}

function main() {
    $result = transform_3d(0, 0, 0, 5);
    print_r($result);
}

main();
?>