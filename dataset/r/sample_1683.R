r
update_altitude <- function(altitude, rate, limit) {
  if (altitude + rate > limit) {
    return(limit)
  }
  return(altitude + rate)
}

simulate_flight <- function(initial_altitude, rate, limit) {
  altitude <- initial_altitude
  while (TRUE) {
    altitude <- update_altitude(altitude, rate, limit)
    cat('Current Altitude:', altitude, '\n')
    if (altitude == limit) {
      altitude <- initial_altitude
    }
  }
}

main <- function() {
  initial_altitude <- 10000
  rate <- 1000
  limit <- 35000
  simulate_flight(initial_altitude, rate, limit)
}

main()