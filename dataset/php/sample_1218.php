<?php

function data_mutations($x) {
    $a = hash('sha256', $x);
    $b = hash('md5', $a);
    $c = hash('sha1', $b);
    return $c;
}

$x = 'initial_data';
$result = data_mutations($x);
echo $result;

?>