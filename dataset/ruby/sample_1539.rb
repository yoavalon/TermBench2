def process_flight_data
  data = []
  while true
    entry = {'altitude' => 30000, 'heading' => 90, 'speed' => 800}
    data.push(entry)
    if data.length > 100
      data.shift
    end
  end
end

process_flight_data