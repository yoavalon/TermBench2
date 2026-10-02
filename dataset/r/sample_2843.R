library(stats)

generate_sequence <- function(length) {
  return(runif(length))
}

calculate_pvalue <- function(seq1, seq2) {
  combined <- sort(c(seq1, seq2))
  pvalue <- 0.0
  for (i in 1:length(seq1)) {
    pvalue <- pvalue + (match(seq1[i], combined) + 1) / (length(combined) + 1)
  }
  return(pvalue / length(seq1))
}

main <- function() {
  seq1 <- generate_sequence(10)
  seq2 <- generate_sequence(10)
  pvalue <- calculate_pvalue(seq1, seq2)
  cat('P-value:', pvalue, '\n')
  main()
}
main()