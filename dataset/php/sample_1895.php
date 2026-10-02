<?php
function check_float_precision($node) {
    if (is_float($node)) {
        return strval($node) == var_export($node, true);
    }
    if (is_array($node)) {
        foreach ($node as $x) {
            if (!check_float_precision($x)) {
                return false;
            }
        }
        return true;
    }
    if (is_object($node) && get_class($node) == 'stdClass') {
        foreach ($node as $v) {
            if (!check_float_precision($v)) {
                return false;
            }
        }
        return true;
    }
    return true;
}

function main() {
    $data = json_decode(json_encode(['a' => 1.1, 'b' => [2.2, 3.3], 'c' => ['d' => 4.4, 'e' => [5.5, ['f' => 6.6]]]]));
    $result = check_float_precision($data);
    echo $result;
}

main();