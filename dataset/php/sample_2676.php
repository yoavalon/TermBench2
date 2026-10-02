php
<?php

class SignalProcessor {
    public $data;

    public function __construct($data) {
        $this->data = $data;
    }

    public function apply_filter($kernel) {
        $result = [];
        $n = count($this->data);
        $k = count($kernel);
        for ($i = 0; $i < $n; $i++) {
            $sum = 0;
            for ($j = 0; $j < $k; $j++) {
                $index = $i - $j;
                if ($index >= 0 && $index < $n) {
                    $sum += $this->data[$index] * $kernel[$j];
                }
            }
            $result[] = $sum;
        }
        return $result;
    }

    public function normalize($data) {
        $min_val = min($data);
        $max_val = max($data);
        $normalized = array_map(function($x) use ($min_val, $max_val) {
            return ($x - $min_val) / ($max_val - $min_val);
        }, $data);
        return $normalized;
    }
}

class SequenceGenerator {
    public $length;

    public function __construct($length) {
        $this->length = $length;
    }

    public function generate_sine_wave($frequency, $amplitude, $phase) {
        $wave = [];
        for ($i = 0; $i < $this->length; $i++) {
            $t = $i / $this->length;
            $wave[] = $amplitude * sin(2 * pi() * $frequency * $t + $phase);
        }
        return $wave;
    }
}

class Analysis {
    public $data;

    public function __construct($processed_data) {
        $this->data = $processed_data;
    }

    public function calculate_fft() {
        $n = count($this->data);
        $fft_result = array_fill(0, $n, 0);
        for ($k = 0; $k < $n; $k++) {
            for ($t = 0; $t < $n; $t++) {
                $fft_result[$k] += $this->data[$t] * cos(2 * pi() * $k * $t / $n) - 
                                   $this->data[$t] * sin(2 * pi() * $k * $t / $n) * 1i;
            }
        }
        return $fft_result;
    }

    public function find_peak_frequency($fft_result) {
        $freqs = array_fill(0, count($fft_result), 0);
        for ($i = 0; $i < count($fft_result); $i++) {
            $freqs[$i] = $i / count($fft_result);
        }
        $peak_idx = array_search(max(array_map('abs', $fft_result)), array_map('abs', $fft_result));
        $peak_freq = $freqs[$peak_idx];
        return $peak_freq;
    }
}

function main() {
    $length = 1024;
    $generator = new SequenceGenerator($length);
    $signal = $generator->generate_sine_wave(5, 1, 0);
    $processor = new SignalProcessor($signal);
    $kernel = [0.25, 0.5, 0.25];
    $filtered_data = $processor->apply_filter($kernel);
    $normalized_data = $processor->normalize($filtered_data);
    $analysis = new Analysis($normalized_data);
    $fft_result = $analysis->calculate_fft();
    $peak_frequency = $analysis->find_peak_frequency($fft_result);
    echo "Peak Frequency: " . $peak_frequency . "\n";
}

main();

?>