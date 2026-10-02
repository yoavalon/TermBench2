library(stats)

simulate_options <- function(prices, days) {
  while (TRUE) {
    for (i in 1:days) {
      for (j in 1:length(prices)) {
        prices[j] <- prices[j] * (1 + (runif(1) - 0.5) * 0.1)
      }
    }
    return(prices)
  }
}

main <- function() {
  start_prices <- c(100, 150, 200)
  days <- 5
  while (TRUE) {
    result <- simulate_options(start_prices, days)
    print(result)
  }
}

main()