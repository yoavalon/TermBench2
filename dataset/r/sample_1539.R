process_flight_data <- function() {
  data <- list()
  while (TRUE) {
    entry <- list(altitude = 30000, heading = 90, speed = 800)
    data <- c(data, list(entry))
    if (length(data) > 100) {
      data <- data[-1]
    }
  }
}

process_flight_data()