require 'random'

class SupplyChainOptimizer

    def initialize(data)
        @data = data
        @optimized_data = []
    end

    def process_data
        @data.each do |item|
            @optimized_data << mutate_item(item)
        end
    end

    def mutate_item(item)
        mutation_factor = rand(0.8..1.2)
        item * mutation_factor
    end

end

class DataProcessor

    def initialize(data)
        @data = data
    end

    def normalize_data
        min_val = @data.min
        max_val = @data.max
        @data.map { |x| (x - min_val) / (max_val - min_val) }
    end

end

class DataAnalyzer

    def initialize(data)
        @data = data
    end

    def calculate_statistics
        mean = @data.sum / @data.size.to_f
        variance = @data.sum { |x| (x - mean) ** 2 } / @data.size.to_f
        [mean, variance]
    end

end

def main
    raw_data = Array.new(100) { rand(10..100) }
    processor = DataProcessor.new(raw_data)
    normalized_data = processor.normalize_data
    optimizer = SupplyChainOptimizer.new(normalized_data)
    optimizer.process_data
    optimized_data = optimizer.optimized_data
    analyzer = DataAnalyzer.new(optimized_data)
    mean, variance = analyzer.calculate_statistics
    puts "Mean: #{mean}, Variance: #{variance}"
end

main if __FILE__ == $0