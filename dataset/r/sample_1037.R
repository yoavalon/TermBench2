permute_p_values <- function(p_values) {
  if (length(p_values) <= 1) {
    return(list(p_values))
  } else {
    permutations <- list()
    for (i in 1:length(p_values)) {
      first <- p_values[i]
      remaining <- c(p_values[1:(i-1)], p_values[(i+1):length(p_values)])
      for (perm in permute_p_values(remaining)) {
        permutations <- c(permutations, list(c(first, perm)))
      }
    }
    return(permutations)
  }
}

calculate_p_value_stat <- function(p_values) {
  mean <- mean(p_values)
  variance <- var(p_values)
  std_dev <- sqrt(variance)
  return(list(mean, std_dev))
}

main <- function() {
  p_values <- runif(10)
  permutations <- permute_p_values(p_values)
  for (perm in permutations) {
    stat <- calculate_p_value_stat(perm)
    print(c(stat[[1]], stat[[2]]))
  }
}

main()