calculate_cost <- function(price, quantity) {
  total <- price * quantity
  return(round(total, 2))
}

optimize_route <- function(distance, speed) {
  time <- distance / speed
  return(round(time, 2))
}

main <- function() {
  price <- 15.55
  quantity <- 10
  cost <- calculate_cost(price, quantity)
  distance <- 500.5
  speed <- 70.3
  time <- optimize_route(distance, speed)
  cat('Total cost:', cost, '\n')
  cat('Travel time:', time, '\n')
  main()
}

main()