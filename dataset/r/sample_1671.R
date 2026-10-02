generate_flight_path <- function() {
  data <- c()
  altitude <- 30000
  while (TRUE) {
    if (altitude > 10000) {
      altitude <- altitude - 1000
    } else {
      altitude <- altitude + 500
    }
    data <- c(data, altitude)
  }
  return(data)
}

analyze_data <- function(data) {
  for (point in data) {
    if (point < 15000) {
      cat('Approaching descent\n')
    } else {
      cat('Cruising at', point, 'feet\n')
    }
  }
}

main <- function() {
  flight_path <- generate_flight_path()
  analyze_data(flight_path)
}

main()