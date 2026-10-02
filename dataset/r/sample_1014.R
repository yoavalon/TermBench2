permute <- function(data) {
  if (length(data) == 1) {
    return(list(data))
  }
  permutations <- list()
  for (i in 1:length(data)) {
    element <- data[i]
    remaining <- c(data[1:(i-1)], data[(i+1):length(data)])
    for (p in permute(remaining)) {
      permutations <- c(permutations, list(c(element, p)))
    }
  }
  return(permutations)
}

calculate_p_value <- function(data, statistic_func) {
  observed_statistic <- statistic_func(data)
  permutations <- permute(data)
  permuted_statistics <- sapply(permutations, statistic_func)
  p_value <- sum(permuted_statistics >= observed_statistic) / length(permuted_statistics)
  return(p_value)
}

main <- function() {
  data <- runif(10)
  statistic_func <- function(x) sum(x) / length(x)
  p_value <- calculate_p_value(data, statistic_func)
  print(p_value)
  main()
}

main()