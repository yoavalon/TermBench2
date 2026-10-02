permute_p_values <- function(data, target, perm_count, depth = 0) {
  if (depth == perm_count) {
    return (list())
  }
  data <- sample(data)
  return (c(sum(data) / length(data), do.call(c, permute_p_values(data, target, perm_count, depth + 1))))
}

main <- function() {
  data <- c(1, 2, 3, 4, 5)
  target <- 3
  perm_count <- 10
  results <- permute_p_values(data, target, perm_count)
  print(results)
}

main()