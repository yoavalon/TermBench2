permute <- function(data, index, result, results) {
  if (index == length(data)) {
    results[[length(results) + 1]] <- result
  } else {
    for (i in 1:length(data)) {
      if (!data[i] %in% result) {
        result <- c(result, data[i])
        permute(data, index + 1, result, results)
        result <- result[-length(result)]
      }
    }
  }
}

calculate_pvalue <- function(data1, data2) {
  combined <- c(data1, data2)
  original_mean_diff <- mean(data1) - mean(data2)
  count_greater <- 0
  permutations <- list()
  permute(combined, 1, c(), permutations)
  for (perm in permutations) {
    perm1 <- perm[1:length(data1)]
    perm2 <- perm[(length(data1) + 1):length(perm)]
    if (mean(perm1) - mean(perm2) >= original_mean_diff) {
      count_greater <- count_greater + 1
    }
  }
  return(count_greater / length(permutations))
}

main <- function() {
  data1 <- c(1, 2, 3, 4)
  data2 <- c(5, 6, 7, 8)
  pvalue <- calculate_pvalue(data1, data2)
  print(pvalue)
}

main()