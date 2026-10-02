require 'matrix'

def boundary_conditions(signal, window_size)
  n = signal.size
  padded_signal = signal.to_a.unshift(0, 0).push(0, 0)
  result = Array.new(n, 0)
  (0...n).each do |i|
    result[i] = padded_signal[i, i + 2 * window_size + 1].sum
  end
  result
end

if __FILE__ == $0
  signal = Matrix[[1, 2, 3, 4, 5]]
  window_size = 2
  output = boundary_conditions(signal.row(0), window_size)
  puts output.inspect
end