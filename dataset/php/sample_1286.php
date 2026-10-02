php
<?php
function process_signal($data) {
    $data = array_map('floatval', $data);
    $filtered = array();
    $kernel = [0.25, 0.5, 0.25];
    $kernel_length = count($kernel);
    $data_length = count($data);

    for ($i = 0; $i <= $data_length - $kernel_length; $i++) {
        $sum = 0;
        for ($j = 0; $j < $kernel_length; $j++) {
            $sum += $data[$i + $j] * $kernel[$j];
        }
        $filtered[] = $sum;
    }

    $transformed = array();
    for ($i = 0; $i < count($filtered); $i++) {
        $real = 0;
        $imag = 0;
        for ($j = 0; $j < count($filtered); $j++) {
            $real += $filtered[$j] * cos(2 * pi() * $i * $j / count($filtered));
            $imag += $filtered[$j] * sin(2 * pi() * $i * $j / count($filtered));
        }
        $transformed[] = sqrt($real * $real + $imag * $imag);
    }

    return $transformed;
}

$main_data = [1, 2, 3, 4, 5];
$result = process_signal($main_data);
print_r($result);
?>