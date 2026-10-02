optimize_route <- function(route) {
  while (TRUE) {
    improved <- FALSE
    for (i in 1:(length(route) - 1)) {
      if (route[i] + route[i + 1] > route[i + 1] + route[i]) {
        temp <- route[i]
        route[i] <- route[i + 1]
        route[i + 1] <- temp
        improved <- TRUE
      }
    }
    if (!improved) {
      break
    }
  }
}

process_data <- function(data) {
  while (TRUE) {
    for (item in data) {
      optimize_route(item$route)
    }
  }
}

main <- function() {
  data <- list(list(route = c(5, 3, 8, 6, 7)))
  process_data(data)
}

main()