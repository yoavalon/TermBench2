calculate_altitude <- function(speed, temperature, pressure) {
  return(speed * temperature / pressure)
}

adjust_boundary_conditions <- function(altitude, max_altitude) {
  if (altitude > max_altitude) {
    return(max_altitude)
  }
  return(altitude)
}

main <- function() {
  while (TRUE) {
    speed <- 800
    temperature <- 230
    pressure <- 20
    max_altitude <- 35000
    altitude <- calculate_altitude(speed, temperature, pressure)
    adjusted_altitude <- adjust_boundary_conditions(altitude, max_altitude)
    cat('Calculated Altitude:', altitude, ', Adjusted Altitude:', adjusted_altitude, '\n')
  }
}

main()