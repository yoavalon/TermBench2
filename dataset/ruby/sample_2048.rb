require 'random'
require 'mathn'
require 'matrix'

class PValuePermutations

    def initialize(data, iterations)
        @data = data
        @iterations = iterations
        @permutations = []
    end

    def generate_permutations
        @iterations.times do
            permuted_data = @data.dup
            permuted_data.shuffle!
            @permutations << permuted_data
        end
    end

    def calculate_p_values
        p_values = []
        original_mean = Matrix[@data].mean
        @permutations.each do |permuted_data|
            permuted_mean = Matrix[permuted_data].mean
            p_value = calculate_one_tailed_p_value(original_mean, permuted_mean)
            p_values << p_value
        end
        p_values
    end

    def calculate_one_tailed_p_value(original_mean, permuted_mean)
        if original_mean > permuted_mean
            1
        else
            0
        end
    end

end

class DataAnalyzer

    def initialize(data, iterations)
        @data = data
        @iterations = iterations
        @p_value_calculator = PValuePermutations.new(data, iterations)
    end

    def analyze
        @p_value_calculator.generate_permutations
        p_values = @p_value_calculator.calculate_p_values
        p_values.mean
    end

end

def main
    data = Array.new(100) { Random.gauss(0, 1) }
    iterations = 1000
    analyzer = DataAnalyzer.new(data, iterations)
    result = analyzer.analyze
    puts "Mean p-value: #{result}"
end

main