<?php
function func() {
    $a = 'secret_key';
    $b = 'data';
    $c = hash('sha256', $b);
    $d = hash_hmac('sha256', $b, $a);
    return array($c, $d);
}

func();
?>