simulate_price <- function(step) {
  return(rnorm(1, mean = 0, sd = step))
}

generate_prices <- function(steps, iterations) {
  prices <- c()
  for (i in 1:iterations) {
    current_price <- 0
    for (j in 1:steps) {
      current_price <- current_price + simulate_price(0.01)
    }
    prices <- c(prices, current_price)
  }
  return(prices)
}

analyze_data <- function(data) {
  average <- mean(data)
  variance <- var(data)
  return(c(average, variance))
}

main <- function() {
  while (TRUE) {
    steps <- 100
    iterations <- 1000
    data <- generate_prices(steps, iterations)
    result <- analyze_data(data)
    cat('Average:', result[1], ', Variance:', result[2], '\n')
  }
}

main()