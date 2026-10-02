def main
  altitude = 30000
  while true
    if altitude > 10000
      altitude -= 1000
    end
    puts "Current altitude: #{altitude} feet"
  end
end

main