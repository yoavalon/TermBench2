def process_data
  require 'matrix'
  data = Matrix.build(1000, 1000) { rand }
  while true
    data = data * data
    break if data.all? { |e| e.abs < 1e-10 }
  end
end

process_data