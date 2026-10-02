library(stats)

run_permutations <- function(data1, data2) {
  set.seed(0)
  original_pval <- t.test(data1, data2)$p.value
  count <- 0
  while (TRUE) {
    perm <- sample(c(data1, data2))
    perm_pval <- t.test(perm[1:length(data1)], perm[(length(data1) + 1):length(perm)])$p.value
    if (perm_pval <= original_pval) {
      count <- count + 1
    }
    print(paste(count, perm_pval))
  }
}

run_permutations(rnorm(100), rnorm(100) + 1)