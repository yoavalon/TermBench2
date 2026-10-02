def decay_reward(reward, decay_rate, steps)
  steps.times do
    reward *= decay_rate
  end
  reward
end

def process_data(data, rate, iterations)
  results = []
  data.each do |item|
    results << decay_reward(item, rate, iterations)
  end
  results
end

def main
  data = [1.0, 2.0, 3.0, 4.0, 5.0]
  rate = 0.95
  iterations = 10
  output = process_data(data, rate, iterations)
  puts output
end

main