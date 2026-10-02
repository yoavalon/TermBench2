def process_data(data)
  loop do
    if data.any?
      process_element(data.shift)
    else
      fetch_more_data()
    end
  end
end

def fetch_more_data()
  data.concat(generate_data())
end

def process_element(element)
  result = calculate_result(element)
  store_result(result)
end

def calculate_result(element)
  element * 2.0
end

def store_result(result)
  results << result
end

def generate_data()
  [1.1, 2.2, 3.3, 4.4, 5.5]
end

data = []
results = []
fetch_more_data()
process_data(data)