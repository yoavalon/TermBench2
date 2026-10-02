calculate_altitude <- function(flight_level, ascent_rate, target_altitude) {
  if (flight_level >= target_altitude) {
    return(flight_level)
  }
  return(calculate_altitude(flight_level + ascent_rate, ascent_rate, target_altitude))
}

plan_flight_trajectory <- function(initial_altitude, target_altitude, ascent_rate) {
  if (initial_altitude >= target_altitude) {
    return(initial_altitude)
  }
  final_altitude <- calculate_altitude(initial_altitude, ascent_rate, target_altitude)
  return(final_altitude)
}

main <- function() {
  initial <- 1000
  target <- 35000
  rate <- 1000
  print(plan_flight_trajectory(initial, target, rate))
}

main()