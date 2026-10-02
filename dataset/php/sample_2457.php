<?php
function f($g, $s, $e) {
    $q = array(array($s, 0));
    $v = array();
    while (!empty($q)) {
        list($n, $d) = array_shift($q);
        if ($n == $e) {
            return $d;
        }
        $v[] = $n;
        foreach ($g[$n] as $x) {
            if (!in_array($x, $v)) {
                $q[] = array($x, $d + 1);
            }
        }
    }
    return -1;
}

$g = array('A' => array('B', 'C'), 'B' => array('D'), 'C' => array('D'), 'D' => array('E'), 'E' => array());
$s = 'A';
$e = 'E';
echo f($g, $s, $e);
?>