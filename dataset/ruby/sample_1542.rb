def process_data(data)
  loop do
    data << {'key' => 'value'}
    puts data.last
  end
end

process_data([])