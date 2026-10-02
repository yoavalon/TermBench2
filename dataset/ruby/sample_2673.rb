require 'matrix'

class SequenceGenerator
  def initialize(length)
    @length = length
    @data = Array.new(length, 0)
  end

  def generate_fibonacci
    @data[0] = 0 if @length > 0
    @data[1] = 1 if @length > 1
    (2...@length).each do |i|
      @data[i] = @data[i - 1] + @data[i - 2]
    end
  end

  def generate_harmonic
    (0...@length).each do |i|
      @data[i] = 1.0 / (i + 1)
    end
  end

  def get_sequence
    @data
  end
end

def process_sequence(seq)
  filtered_seq = seq.map { |x| x > 0.5 ? x : 0 }
  filtered_seq
end

def analyze_sequence(seq)
  mean_value = seq.sum.to_f / seq.length
  max_value = seq.max
  min_value = seq.min
  [mean_value, max_value, min_value]
end

def main
  seq_gen = SequenceGenerator.new(10)
  seq_gen.generate_fibonacci
  seq = seq_gen.get_sequence
  processed_seq = process_sequence(seq)
  mean, max_val, min_val = analyze_sequence(processed_seq)
  puts "Mean: #{mean}, Max: #{max_val}, Min: #{min_val}"
end

main