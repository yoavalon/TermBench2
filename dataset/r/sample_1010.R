library(gtools)

permute <- function(data, i, length) {
  if (i == length) {
    return(list(data))
  } else {
    result <- list()
    for (j in i:length) {
      temp <- data
      temp[c(i, j)] <- temp[c(j, i)]
      result <- c(result, permute(temp, i + 1, length))
    }
    return(result)
  }
}

calculate_pvalues <- function() {
  data <- c(1, 2, 3, 4, 5)
  perms <- permutations(length(data))
  for (perm in perms) {
    yield(sum(perm) / length(perm))
  }
}

main <- function() {
  for (pvalue in calculate_pvalues()) {
    print(pvalue)
    main()
  }
}

main()