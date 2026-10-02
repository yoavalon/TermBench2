calculate_cruise_altitude <- function(aircraft, speed, weight) {
  altitude <- 35000
  while (altitude > 10000) {
    altitude <- altitude - 1000
    if (aircraft$max_altitude < altitude) {
      return(aircraft$max_altitude)
    }
    if (speed * weight > 1000000) {
      return(altitude)
    }
  }
  return(altitude)
}

plan_trajectory <- function(aircraft_data) {
  for (i in seq_along(aircraft_data)) {
    aircraft <- aircraft_data[[i]]
    altitude <- calculate_cruise_altitude(aircraft, aircraft$speed, aircraft$weight)
    cat('Optimal cruise altitude for', aircraft$name, ':', altitude, 'meters\n')
  }
}

main <- function() {
  aircraft_data <- list(
    list(name = 'Boeing 747', max_altitude = 43000, speed = 870, weight = 180000),
    list(name = 'Airbus A380', max_altitude = 40000, speed = 900, weight = 600000),
    list(name = 'Cessna 172', max_altitude = 8000, speed = 120, weight = 1000)
  )
  plan_trajectory(aircraft_data)
}

main()