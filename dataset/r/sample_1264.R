flight_planner <- function() {
  data <- c(5000, 6000, 7000, 8000, 9000)
  index <- 1
  while (index <= length(data)) {
    if (data[index] > 7500) {
      data[index] <- data[index] - 500
    }
    index <- index + 1
  }
  return(data)
}

if (interactive()) {
  flight_planner()
}