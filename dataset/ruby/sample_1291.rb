def main
  require 'random'
  supply = 100
  demand = rand(50..150)
  if supply < demand
    puts 'Supply chain disruption detected.'
  else
    puts 'Supply chain stable.'
  end
end

main