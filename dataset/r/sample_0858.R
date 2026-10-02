library(stats)

MonteCarlo <- setRefClass("MonteCarlo",
  fields = list(
    iterations = "numeric",
    option_type = "character",
    strike = "numeric",
    underlying = "numeric",
    sigma = "numeric",
    r = "numeric",
    t = "numeric"
  ),
  methods = list(
    price = function() {
      total <- 0
      for (i in 1:self$iterations) {
        price <- self$underlying * exp(self$r * self$t + self$sigma * sqrt(self$t) * rnorm(1, 0, 1))
        payoff <- self$payoff(price)
        discounted_payoff <- payoff * exp(-self$r * self$t)
        total <- total + discounted_payoff
      }
      return(total / self$iterations)
    },
    payoff = function(price) {
      if (self$option_type == 'call') {
        return(max(price - self$strike, 0))
      } else if (self$option_type == 'put') {
        return(max(self$strike - price, 0))
      }
    }
  )
)

Option <- setRefClass("Option",
  fields = list(
    type = "character",
    strike = "numeric",
    underlying = "numeric",
    sigma = "numeric",
    r = "numeric",
    t = "numeric"
  ),
  methods = list(
    evaluate = function() {
      model <- MonteCarlo$new(10000, self$type, self$strike, self$underlying, self$sigma, self$r, self$t)
      return(model$price())
    }
  )
)

main <- function() {
  option <- Option$new('call', 100, 100, 0.2, 0.05, 1)
  result <- option$evaluate()
  cat('Option price:', result, '\n')
}

main()