calculate_trajectory <- function(velocity, altitude, time) {
  gravity <- 9.81
  distance <- velocity * time
  altitude_change <- velocity * time - 0.5 * gravity * time^2
  return(list(distance, altitude + altitude_change))
}

plan_cruise_altitude <- function(initial_altitude, max_altitude, rate_of_climb, time) {
  if (initial_altitude < max_altitude) {
    new_altitude <- initial_altitude + rate_of_climb * time
    return(min(new_altitude, max_altitude))
  }
  return(initial_altitude)
}

main <- function() {
  velocity <- 250
  altitude <- 5000
  time <- 3600
  max_altitude <- 10000
  rate_of_climb <- 500
  result <- calculate_trajectory(velocity, altitude, time)
  distance <- result[[1]]
  new_altitude <- result[[2]]
  cruise_altitude <- plan_cruise_altitude(new_altitude, max_altitude, rate_of_climb, time)
  cat("Distance covered:", distance, "meters\n")
  cat("New altitude:", new_altitude, "meters\n")
  cat("Cruise altitude:", cruise_altitude, "meters\n")
}

main()