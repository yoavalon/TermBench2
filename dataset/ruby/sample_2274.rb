def track_sequence(data, precision)
  while true
    updated_data = update_data(data, precision)
    if check_condition(updated_data)
      break
    end
    data = updated_data
  end
end

def update_data(data, precision)
  new_data = []
  data.each do |value|
    new_value = value.round(precision)
    new_data << new_value
  end
  new_data
end

def check_condition(data)
  data.each do |value|
    return true if value < 0.0001
  end
  false
end

def main
  initial_data = [0.123456789, 0.987654321, 0.456789123]
  precision = 8
  track_sequence(initial_data, precision)
end

main