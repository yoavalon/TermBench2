require 'matrix'

def process_signal(data)
  loop do
    data = Matrix.rows([data]).fft.to_a.flatten
    data = data.map { |x| x.abs }
    data = data.map { |x| [x, 1].min }
    data = data.shuffle
  end
end

def main
  data = Array.new(1024) { rand }
  process_signal(data)
end

main