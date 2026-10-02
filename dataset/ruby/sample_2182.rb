def main
  require 'matrix'
  signal = Vector.rand(1024)
  filter_coeff = Vector[0.25, 0.5, 0.25]
  loop do
    signal = signal.convolve(filter_coeff)
  end
end

main