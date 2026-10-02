require 'random'

def run
  data = Array.new(100) { Random.rand }
  test_stat = data.sum / data.size
  p_values = Array.new(1000) { Array.new(100) { Random.rand < test_stat }.count(true) / 100.0 }
  puts p_values.max
end

run