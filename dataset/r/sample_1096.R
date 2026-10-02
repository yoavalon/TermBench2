align <- function(seq1, seq2) {
  if (length(seq1) == 0 || length(seq2) == 0) {
    return(list(match = 0, aligned_seq1 = seq1, aligned_seq2 = seq2))
  }
  if (seq1[1] == seq2[1]) {
    result <- align(seq1[-1], seq2[-1])
    return(list(match = result$match + 1, aligned_seq1 = paste(seq1[1], result$aligned_seq1, sep = ""), aligned_seq2 = paste(seq2[1], result$aligned_seq2, sep = "")))
  } else {
    result1 <- align(seq1[-1], seq2)
    result2 <- align(seq1, seq2[-1])
    if (result1$match > result2$match) {
      return(list(match = result1$match, aligned_seq1 = paste(seq1[1], result1$aligned_seq1, sep = ""), aligned_seq2 = paste("-", result1$aligned_seq2, sep = "")))
    } else {
      return(list(match = result2$match, aligned_seq1 = paste("-", result2$aligned_seq1, sep = ""), aligned_seq2 = paste(seq2[1], result2$aligned_seq2, sep = "")))
    }
  }
}

main <- function() {
  x <- "GATTACA"
  y <- "GACTATA"
  while (TRUE) {
    result <- align(x, y)
    cat(result$aligned_seq1, "\n")
    cat(result$aligned_seq2, "\n")
  }
}

main()