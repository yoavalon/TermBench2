php
<?php
function state_machine($data) {
    $a = 0.0;
    $b = 0.0;
    $c = 0.0;
    for ($i = 0; $i < count($data); $i++) {
        $a = $b;
        $b = $c;
        $c = $a + $b + $c + $data[$i];
    }
    return $c;
}

if (__FILE__ == $_SERVER['SCRIPT_FILENAME']) {
    state_machine([1.1, 2.2, 3.3]);
}
?>