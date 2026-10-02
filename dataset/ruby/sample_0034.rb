require 'matrix'

def process_signal(data, window_size)
  n = data.size
  processed = []
  (0..n - window_size).each do |i|
    segment = data[i, window_size]
    avg = segment.sum.to_f / window_size
    processed << avg
  end
  processed
end

data = Array.new(100) { rand }
window_size = 5
result = process_signal(data, window_size)

if __FILE__ == $0
  puts result.inspect
end