library(stats)

permute <- function(data, n) {
  if (n == 0) {
    return(list(data))
  }
  result <- list()
  for (i in 1:length(data)) {
    x <- data[i]
    xs <- c(data[1:(i-1)], data[(i+1):length(data)])
    for (p in permute(xs, n - 1)) {
      result <- append(result, list(c(x, p)))
    }
  }
  return(result)
}

calculate_pvalue <- function(data, func) {
  observed <- func(data)
  permutations <- permute(data, length(data) - 1)
  p_values <- sapply(permutations, func)
  return(sum(p_values >= observed) / length(p_values))
}

main <- function() {
  data <- c(1, 2, 3, 4, 5)
  statistic_func <- function(x) mean(x) - mean(c(1, 2, 3, 4, 5))
  p_value <- calculate_pvalue(data, statistic_func)
  print(p_value)
}

main()