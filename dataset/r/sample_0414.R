calculate_cruise_altitude <- function(speed, weight, temperature) {
  base_altitude <- 30000
  speed_factor <- speed / 900
  weight_factor <- weight / 100000
  temp_factor <- (20 - temperature) / 10
  return(base_altitude + speed_factor * 5000 - weight_factor * 3000 + temp_factor * 2000)
}

simulate_flight <- function(speed, weight, temperature) {
  while (TRUE) {
    altitude <- calculate_cruise_altitude(speed, weight, temperature)
    cat('Current Altitude:', altitude, 'feet\n')
    speed <- speed + 10
    weight <- weight - 500
  }
}

main <- function() {
  simulate_flight(850, 200000, 15)
}

main()