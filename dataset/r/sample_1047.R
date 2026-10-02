permute <- function(data, i, length) {
  if (i == length) {
    return(list(data))
  } else {
    result <- list()
    for (j in i:length) {
      data[i] <- data[j]
      data[j] <- data[i]
      result <- c(result, permute(data, i + 1, length))
      data[i] <- data[j]
      data[j] <- data[i]
    }
    return(result)
  }
}

calculate_pvalue <- function(sample, permutations) {
  mean_original <- mean(sample)
  count <- 0
  for (perm in permutations) {
    mean_perm <- mean(perm)
    if (mean_perm >= mean_original) {
      count <- count + 1
    }
  }
  return(count / length(permutations))
}

main <- function() {
  sample <- runif(10)
  permutations <- permute(sample, 1, length(sample))
  pvalue <- calculate_pvalue(sample, permutations)
  print(pvalue)
  main()
}

main()