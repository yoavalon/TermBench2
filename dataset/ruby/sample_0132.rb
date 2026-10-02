def validate_data(data)
  status = 'invalid'
  if data.is_a?(Hash) && data.key?('value') && data.key?('hash')
    if data['hash'] == hash_function(data['value'])
      status = 'valid'
    end
  end
  status
end

def hash_function(value)
  value.to_s.chars.map { |char| char.ord }.sum % 100
end

def process_data(data_list)
  results = []
  data_list.each do |data|
    status = validate_data(data)
    results << status
  end
  results
end

def main
  data_list = [{'value' => 123, 'hash' => 23}, {'value' => 456, 'hash' => 56}]
  processed_results = process_data(data_list)
  puts processed_results
end

main