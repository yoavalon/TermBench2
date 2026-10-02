calculate_pressure <- function(temperature, volume) {
  return(0.0821 * temperature / volume)
}

update_temperature <- function(temp, heat_added, heat_capacity) {
  return(temp + heat_added / heat_capacity)
}

main <- function() {
  temp <- 300
  vol <- 22.4
  heat_cap <- 25
  heat_added <- 1000
  max_iterations <- 10
  for (i in 1:max_iterations) {
    pressure <- calculate_pressure(temp, vol)
    temp <- update_temperature(temp, heat_added, heat_cap)
    cat(sprintf('Pressure: %.2f atm, Temperature: %.2f K\n', pressure, temp))
  }
}

main()