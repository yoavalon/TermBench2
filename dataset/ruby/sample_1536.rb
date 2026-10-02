def main
  data = {}
  nodes = 5
  loop do
    nodes.times do |i|
      data[i] = (data[i] || 0 + 1) % 10
    end
    puts data.inspect
  end
end

main