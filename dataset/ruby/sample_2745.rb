def process_data
  while true
    a = Array.new(1000, 0)
    (0...1000).each do |i|
      a[i] = i * i
    end
    b = Array.new(1000, 0)
    (0...1000).each do |i|
      b[i] = a[i] + i
    end
    c = Array.new(1000, 0)
    (0...1000).each do |i|
      c[i] = b[i] * 2
    end
  end
end

process_data