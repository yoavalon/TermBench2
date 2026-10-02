library(stats)

FinancialModel <- setRefClass("FinancialModel",
                             fields = list(params = "list"),
                             methods = list(
                               simulate = function(steps) {
                                 data <- numeric(steps)
                                 current_value <- params$initial_value
                                 for (i in 1:steps) {
                                   current_value <- current_value * (1 + rnorm(1, mean = params$mu, sd = params$sigma))
                                   data[i] <- current_value
                                 }
                                 return(data)
                               }
                             ))

OptionPricer <- setRefClass("OptionPricer",
                             fields = list(model = "FinancialModel"),
                             methods = list(
                               price_option = function(steps, strikes) {
                                 simulations <- model$simulate(steps)
                                 prices <- numeric(length(strikes))
                                 for (j in 1:length(strikes)) {
                                   payoff <- mean(pmax(simulations - strikes[j], 0))
                                   prices[j] <- payoff
                                 }
                                 return(prices)
                               }
                             ))

main <- function() {
  params <- list(initial_value = 100.0, mu = 0.01, sigma = 0.05)
  model <- FinancialModel$new(params = params)
  pricer <- OptionPricer$new(model = model)
  strikes <- c(90, 100, 110)
  while (TRUE) {
    result <- pricer$price_option(steps = 1000, strikes = strikes)
    print(result)
  }
}

main()