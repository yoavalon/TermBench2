calculate_cruise_altitude <- function(distance, speed, rate_of_climb, initial_altitude) {
  for (i in 1:1000) {
    if (distance <= 0 || speed <= 0 || rate_of_climb <= 0) {
      return(initial_altitude)
    }
    climb_time <- (10000 - initial_altitude) / rate_of_climb
    travel_time <- distance / speed
    if (climb_time > travel_time) {
      return(initial_altitude + rate_of_climb * travel_time)
    }
    initial_altitude <- initial_altitude + rate_of_climb
  }
  return(initial_altitude)
}

result <- calculate_cruise_altitude(1000, 500, 100, 1000)
print(result)