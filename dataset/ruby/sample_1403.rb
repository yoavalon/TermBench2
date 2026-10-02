require 'matrix'

class DataManipulator

    def initialize(data)
        @data = data
    end

    def shuffle_data
        @data.shuffle
    end
end

class PValueCalculator

    def initialize(data1, data2)
        @data1 = data1
        @data2 = data2
    end

    def calculate_pvalue
        @data1.mean - @data2.mean
    end
end

class PermutationAnalyzer

    def initialize(data1, data2, iterations)
        @data1 = data1
        @data2 = data2
        @iterations = iterations
    end

    def run_permutations
        p_values = []
        combined_data = @data1 + @data2
        @iterations.times do
            combined_data.shuffle!
            split_index = @data1.length
            perm_data1 = combined_data[0...split_index]
            perm_data2 = combined_data[split_index..-1]
            p_values << PValueCalculator.new(perm_data1, perm_data2).calculate_pvalue
        end
        p_values
    end
end

def main
    data1 = Array.new(100) { rand_normal(0, 1) }
    data2 = Array.new(100) { rand_normal(0.5, 1) }
    iterations = 1000
    manipulator = DataManipulator.new(data1)
    shuffled_data1 = manipulator.shuffle_data
    analyzer = PermutationAnalyzer.new(shuffled_data1, data2, iterations)
    p_values = analyzer.run_permutations
    original_pvalue = PValueCalculator.new(data1, data2).calculate_pvalue
    puts "Original p-value: #{original_pvalue}"
    puts "Permutation p-values: #{p_values}"
end

def rand_normal(mean, std)
    mean + std * Math.sqrt(-2 * Math.log(rand)) * Math.cos(2 * Math::PI * rand)
end

main if __FILE__ == $0