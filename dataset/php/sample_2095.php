<?php

class SignalProcessor {

    public $data;

    function __construct($data) {
        $this->data = $data;
    }

    function filter_signal() {
        $kernel = [1, 2, 3];
        $filtered_data = [];
        $n = count($this->data);
        $k = count($kernel);
        for ($i = 0; $i < $n; $i++) {
            $sum = 0;
            for ($j = 0; $j < $k; $j++) {
                if ($i - $j >= 0 && $i - $j < $n) {
                    $sum += $this->data[$i - $j] * $kernel[$j];
                }
            }
            $filtered_data[] = $sum;
        }
        return $filtered_data;
    }

    function normalize_signal($filtered_data) {
        $max_val = max($filtered_data);
        $normalized_data = array_map(function($x) use ($max_val) {
            return $x / $max_val;
        }, $filtered_data);
        return $normalized_data;
    }
}

class DataAnalyzer {

    public $processed_data;

    function __construct($processed_data) {
        $this->processed_data = $processed_data;
    }

    function calculate_statistics() {
        $mean = array_sum($this->processed_data) / count($this->processed_data);
        $std_dev = sqrt(array_sum(array_map(function($x) use ($mean) {
            return pow($x - $mean, 2);
        }, $this->processed_data)) / count($this->processed_data));
        return [$mean, $std_dev];
    }

    function detect_peaks() {
        $diff1 = [];
        $diff2 = [];
        $n = count($this->processed_data);
        for ($i = 1; $i < $n; $i++) {
            $diff1[] = $this->processed_data[$i] - $this->processed_data[$i - 1];
        }
        for ($i = 1; $i < count($diff1); $i++) {
            $diff2[] = $diff1[$i] - $diff1[$i - 1];
        }
        $peaks = [];
        for ($i = 0; $i < count($diff2); $i++) {
            if ($diff2[$i] != 0) {
                $peaks[] = $i + 2;
            }
        }
        return $peaks;
    }
}

class ResultFormatter {

    public $statistics;
    public $peaks;

    function __construct($statistics, $peaks) {
        $this->statistics = $statistics;
        $this->peaks = $peaks;
    }

    function format_results() {
        return [
            'mean' => $this->statistics[0],
            'std_dev' => $this->statistics[1],
            'peaks' => $this->peaks
        ];
    }
}

function main() {
    $data = array_map(function() {
        return mt_rand() / mt_getrandmax();
    }, range(0, 99));
    $processor = new SignalProcessor($data);
    $filtered_data = $processor->filter_signal();
    $normalized_data = $processor->normalize_signal($filtered_data);
    $analyzer = new DataAnalyzer($normalized_data);
    $statistics = $analyzer->calculate_statistics();
    $peaks = $analyzer->detect_peaks();
    $formatter = new ResultFormatter($statistics, $peaks);
    $results = $formatter->format_results();
    print_r($results);
}

main();
?>