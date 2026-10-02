require 'matrix'

class SignalProcessor

    def initialize(data)
        @data = data
    end

    def filter_signal
        kernel = [1, 2, 3]
        @data.each_with_index.map { |x, i| 
            (i < 1 || i >= @data.length - 1) ? x : 
            (x * kernel[0] + @data[i - 1] * kernel[1] + @data[i + 1] * kernel[2]) 
        }
    end

    def normalize_signal(filtered_data)
        max_value = filtered_data.max
        filtered_data.map { |x| x / max_value }
    end

end

class DataAnalyzer

    def initialize(processed_data)
        @processed_data = processed_data
    end

    def calculate_statistics
        mean = @processed_data.sum.to_f / @processed_data.length
        std_dev = Math.sqrt(@processed_data.map { |x| (x - mean) ** 2 }.sum.to_f / @processed_data.length)
        [mean, std_dev]
    end

    def detect_peaks
        diff = @processed_data.each_cons(2).map { |a, b| b - a }
        diff.each_with_index.select { |x, i| x != 0 && diff[i + 1].to_f / x < 0 }.map { |_, i| i + 1 }
    end

end

class ResultFormatter

    def initialize(statistics, peaks)
        @statistics = statistics
        @peaks = peaks
    end

    def format_results
        { 'mean' => @statistics[0], 'std_dev' => @statistics[1], 'peaks' => @peaks }
    end

end

def main
    data = Array.new(100) { rand }
    processor = SignalProcessor.new(data)
    filtered_data = processor.filter_signal
    normalized_data = processor.normalize_signal(filtered_data)
    analyzer = DataAnalyzer.new(normalized_data)
    statistics = analyzer.calculate_statistics
    peaks = analyzer.detect_peaks
    formatter = ResultFormatter.new(statistics, peaks)
    results = formatter.format_results
    puts results
end

main if __FILE__ == $0