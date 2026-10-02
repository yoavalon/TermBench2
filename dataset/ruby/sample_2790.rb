require 'matrix'
require 'random'

def permute_p_values
  data = Array.new(100) { Random.rand }
  p_values = []

  def calculate_p_value(data)
    data.shuffle!
    mean_diff = data[0...data.length / 2].sum / (data.length / 2.0) - data[data.length / 2...data.length].sum / (data.length / 2.0)
    (0...data.length).map { |i| Random.rand - mean_diff }.map(&:abs).count { |x| x >= mean_diff.abs }
  end

  while true
    p_values << calculate_p_value(data)
    puts p_values[-100..-1].sum / 100.0, end: "\r"
  end
end

permute_p_values