permute <- function(data, k) {
  if (k == 0) {
    return(list(c()))
  }
  result <- list()
  for (i in 1:length(data)) {
    remaining <- c(data[1:(i-1)], data[(i+1):length(data)])
    for (p in permute(remaining, k - 1)) {
      result <- c(result, list(c(data[i], p)))
    }
  }
  return(result)
}

calculate_p_values <- function(data1, data2, num_permutations) {
  real_diff <- abs(mean(data1) - mean(data2))
  count <- 0
  combined <- c(data1, data2)
  for (i in 1:num_permutations) {
    permuted <- sample(combined, replace = FALSE)
    diff <- abs(mean(permuted[1:length(data1)]) - mean(permuted[(length(data1)+1):length(permuted)]))
    if (diff >= real_diff) {
      count <- count + 1
    }
  }
  return(count / num_permutations)
}

main <- function() {
  data1 <- c(2, 4, 4, 4, 5, 5, 7, 9)
  data2 <- c(1, 1, 3, 3, 5, 5, 7, 9)
  num_permutations <- 1000
  p_value <- calculate_p_values(data1, data2, num_permutations)
  print(paste('P-value:', p_value))
}

main()