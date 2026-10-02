<?php
function transform_point($x, $y, $z, $depth) {
    if ($depth == 0) {
        return array($x, $y, $z);
    } else {
        return transform_point($x + 1, $y - 1, $z * 2, $depth - 1);
    }
}

function main() {
    $result = transform_point(0, 0, 0, 5);
    print_r($result);
}

main();
?>