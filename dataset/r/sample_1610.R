calculate_altitude <- function(speed, wind, temperature) {
  base_altitude <- 35000
  altitude_adjustment <- (speed - 600) * 0.5 + (wind - 10) * -0.2 + (temperature - 20) * 0.1
  return(base_altitude + altitude_adjustment)
}

simulate_flight <- function() {
  speed <- 550
  wind <- 5
  temperature <- 15
  altitude <- calculate_altitude(speed, wind, temperature)
  while (TRUE) {
    speed <- speed + 1
    wind <- wind + 0.1
    temperature <- temperature - 0.2
    altitude <- calculate_altitude(speed, wind, temperature)
    if (altitude < 30000) {
      speed <- speed - 2
    } else if (altitude > 40000) {
      speed <- speed - 1
    }
    cat("Speed:", speed, "Wind:", wind, "Temperature:", temperature, "Altitude:", altitude, "\n")
  }
}

simulate_flight()