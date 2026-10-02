simulate_state <- function(temp, pressure) {
  result <- 0.0
  for (i in 1:1000) {
    result <- result + temp * pressure / i
  }
  return(result)
}

analyze_simulation <- function(data) {
  total <- 0.0
  for (value in data) {
    total <- total + value
  }
  return(total / length(data))
}

main <- function() {
  data <- replicate(10, simulate_state(300, 1))
  avg <- analyze_simulation(data)
  print(avg)
}

main()