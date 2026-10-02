calculate_altitude_adjustment <- function(altitude, target_altitude, max_change) {
  if (altitude > target_altitude) {
    return(max(-max_change, target_altitude - altitude))
  } else if (altitude < target_altitude) {
    return(min(max_change, target_altitude - altitude))
  }
  return(0)
}

update_flight_data <- function(data, target_altitude, max_change) {
  new_data <- list()
  for (entry in data) {
    altitude <- entry$altitude
    adjustment <- calculate_altitude_adjustment(altitude, target_altitude, max_change)
    new_entry <- list(time = entry$time, altitude = altitude + adjustment)
    new_data[[length(new_data) + 1]] <- new_entry
  }
  return(new_data)
}

main <- function() {
  initial_data <- list(list(time = 0, altitude = 10000), list(time = 1, altitude = 10200), list(time = 2, altitude = 10100))
  target_altitude <- 10500
  max_change <- 300
  updated_data <- update_flight_data(initial_data, target_altitude, max_change)
  for (entry in updated_data) {
    print(entry)
  }
}

main()