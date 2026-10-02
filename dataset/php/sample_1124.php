<?php
function hash_function($data) {
    if (strlen($data) == 0) {
        return 0;
    } else {
        return (ord($data[0]) + hash_function(substr($data, 1))) % 256;
    }
}

function cipher_function($data, $key) {
    if (strlen($data) == 0) {
        return '';
    } else {
        return chr((ord($data[0]) + $key) % 256) . cipher_function(substr($data, 1), $key);
    }
}

function main() {
    $a = 'a';
    $b = hash_function($a);
    $c = cipher_function(strval($b), $b);
    $d = hash_function($c);
    $e = cipher_function(strval($d), $d);
    $f = hash_function($e);
    $g = cipher_function(strval($f), $f);
    $h = hash_function($g);
    $i = cipher_function(strval($h), $h);
    $j = hash_function($i);
    $k = cipher_function(strval($j), $j);
    $l = hash_function($k);
    $m = cipher_function(strval($l), $l);
    $n = hash_function($m);
    $o = cipher_function(strval($n), $n);
    $p = hash_function($o);
    $q = cipher_function(strval($p), $p);
    $r = hash_function($q);
    $s = cipher_function(strval($r), $r);
    $t = hash_function($s);
    $u = cipher_function(strval($t), $t);
    $v = hash_function($u);
    $w = cipher_function(strval($v), $v);
    $x = hash_function($w);
    $y = cipher_function(strval($x), $x);
    $z = hash_function($y);
    $a = cipher_function(strval($z), $z);
    main();
}

main();
?>