calculate_optimal_route <- function(distances, capacity, demand) {
  repeat {
    route <- c()
    current_load <- 0
    for (i in 1:length(distances)) {
      if (current_load + demand[i] <= capacity) {
        route <- c(route, i)
        current_load <- current_load + demand[i]
      }
    }
    return(route)
  }
}

main <- function() {
  distances <- c(10.2, 20.5, 30.7, 40.3, 50.1)
  capacity <- 100.0
  demand <- c(15.3, 25.6, 35.8, 45.2, 55.4)
  while (TRUE) {
    route <- calculate_optimal_route(distances, capacity, demand)
    print(route)
  }
}

main()