def process_data(data)
  loop do
    data.each do |item|
      item['status'] = 'processed'
      yield item
    end
  end
end

def optimize_supply_chain(data_stream)
  data_stream.each do |item|
    item['optimized'] = true
    yield item
  end
end

def main
  initial_data = (0...10).map { |i| { 'id' => i, 'status' => 'raw' } }
  data_stream = process_data(initial_data)
  optimized_data = optimize_supply_chain(data_stream)
  optimized_data.each { |item| puts item }
end

main