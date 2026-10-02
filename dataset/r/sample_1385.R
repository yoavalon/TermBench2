simulate_temperature_change <- function(initial_temp, rate, steps) {
  temperatures <- c(initial_temp)
  for (i in 1:steps) {
    new_temp <- temperatures[length(temperatures)] + rate
    temperatures <- c(temperatures, new_temp)
  }
  return(temperatures)
}

analyze_data <- function(data) {
  max_temp <- max(data)
  min_temp <- min(data)
  return(c(max_temp, min_temp))
}

main <- function() {
  data <- simulate_temperature_change(20, 2, 10)
  result <- analyze_data(data)
  print(result[1])
  print(result[2])
}

main()