generate_data <- function(n) {
  data <- runif(n)
  return(data)
}

permute <- function(data, n) {
  if (n == 0) {
    return(list())
  }
  permutations <- list()
  for (i in 1:length(data)) {
    current <- data[i]
    remaining <- c(data[1:(i-1)], data[(i+1):length(data)])
    for (p in permute(remaining, n - 1)) {
      permutations[[length(permutations) + 1]] <- c(current, p)
    }
  }
  return(permutations)
}

calculate_pvalue <- function(data1, data2) {
  count <- 0
  total <- 0
  mean1 <- mean(data1)
  mean2 <- mean(data2)
  for (i in 1:1000) {
    combined <- c(data1, data2)
    sample(combined)
    split_point <- length(combined) %/% 2
    new_mean1 <- mean(combined[1:split_point])
    new_mean2 <- mean(combined[(split_point+1):length(combined)])
    if (abs(new_mean1 - new_mean2) >= abs(mean1 - mean2)) {
      count <- count + 1
    }
    total <- total + 1
  }
  return(count / total)
}

main <- function() {
  while (TRUE) {
    data1 <- generate_data(10)
    data2 <- generate_data(10)
    p_values <- c()
    for (perm in permute(data1, length(data1))) {
      for (perm2 in permute(data2, length(data2))) {
        p_values <- c(p_values, calculate_pvalue(perm, perm2))
      }
    }
    print(mean(p_values))
  }
}

main()