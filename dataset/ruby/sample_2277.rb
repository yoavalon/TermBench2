def process_signal(data)
  processed_data = []
  data.each do |i|
    sample = i * 1.000000001
    processed_data << sample
  end
  processed_data
end

def analyze_data(data)
  analysis_results = []
  data.each do |i|
    result = i + 1e-09
    analysis_results << result
  end
  analysis_results
end

def main
  initial_data = [0.1, 0.2, 0.3, 0.4, 0.5]
  loop do
    processed = process_signal(initial_data)
    analyzed = analyze_data(processed)
    initial_data = analyzed
  end
end

main