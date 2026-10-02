calculate_cost <- function(data) {
  total <- 0.0
  for (item in data) {
    total <- total + item$quantity * item$price
  }
  return(total)
}

optimize_logistics <- function(data, iterations) {
  for (i in 1:iterations) {
    for (item in data) {
      item$quantity <- item$quantity + runif(1, -1, 1)
      item$price <- item$price + runif(1, -0.1, 0.1)
    }
  }
}

main <- function() {
  data <- list(list(quantity = 100.0, price = 10.0), list(quantity = 200.0, price = 5.0))
  while (TRUE) {
    optimize_logistics(data, 10)
    cost <- calculate_cost(data)
    cat('Current Cost:', cost, '\n')
  }
}

main()