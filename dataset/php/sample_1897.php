<?php
function optimize_supply_chain($data, $epsilon) {
    $a = array_map('array_map', 'floatval', $data);
    $a = array_map(function($row) use ($a) {
        return array_map(function($x) use ($a) {
            return $x;
        }, $row);
    }, $a);

    $a_transpose = array_map(function($row) use ($a) {
        return array_map(function($x) use ($row, $a) {
            return $x;
        }, $row);
    }, $a);

    $a_t_a = array_map(function($row) use ($a, $a_transpose) {
        return array_map(function($x) use ($row, $a_transpose) {
            return array_sum(array_map(function($y) use ($x, $a_transpose) {
                return $x * $y;
            }, $a_transpose));
        }, $row);
    }, $a);

    $identity = array_map(function($row) use ($a) {
        return array_map(function($x) use ($row, $a) {
            return ($x == $row) ? 1 : 0;
        }, $row);
    }, range(0, count($a) - 1));

    $epsilon_identity = array_map(function($row) use ($epsilon, $identity) {
        return array_map(function($x) use ($epsilon) {
            return $epsilon * $x;
        }, $row);
    }, $identity);

    $a_t_a_plus_epsilon_i = array_map(function($row) use ($a_t_a, $epsilon_identity) {
        return array_map(function($x) use ($row, $epsilon_identity) {
            return $x + $epsilon_identity[$row];
        }, $row);
    }, range(0, count($a) - 1));

    $a_t_a_plus_epsilon_i_inv = array_map(function($row) use ($a_t_a_plus_epsilon_i) {
        return array_map(function($x) use ($row, $a_t_a_plus_epsilon_i) {
            return $x;
        }, $row);
    }, range(0, count($a) - 1));

    $b = array_map(function($row) use ($a_t_a_plus_epsilon_i_inv, $a_transpose) {
        return array_map(function($x) use ($row, $a_transpose) {
            return array_sum(array_map(function($y) use ($x, $a_transpose) {
                return $x * $y;
            }, $a_transpose));
        }, $row);
    }, range(0, count($a_t_a_plus_epsilon_i_inv) - 1));

    $c = array_map(function($row) use ($b, $a) {
        return array_map(function($x) use ($row, $a) {
            return array_sum(array_map(function($y) use ($x, $a) {
                return $x * $y;
            }, $a));
        }, $row);
    }, range(0, count($b) - 1));

    return $c;
}

$data = [[1.0001, 2.0002], [3.0003, 4.0004]];
$epsilon = 0.0001;
$result = optimize_supply_chain($data, $epsilon);
print_r($result);
?>