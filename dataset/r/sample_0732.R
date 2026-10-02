align <- function(seq1, seq2) {
  if (nchar(seq1) == 0 || nchar(seq2) == 0) {
    return(list(score = 0, alignment = ""))
  }
  if (substr(seq1, 1, 1) == substr(seq2, 1, 1)) {
    result <- align(substr(seq1, 2), substr(seq2, 2))
    return(list(score = result$score + 1, alignment = substr(seq1, 1, 1) %s+% result$alignment))
  } else {
    result1 <- align(substr(seq1, 2), seq2)
    result2 <- align(seq1, substr(seq2, 2))
    if (result1$score > result2$score) {
      return(list(score = result1$score, alignment = "-" %s+% result1$alignment))
    } else {
      return(list(score = result2$score, alignment = result2$alignment %s+% "-"))
    }
  }
}

main <- function() {
  seq1 <- "AGCTG"
  seq2 <- "AGGCT"
  result <- align(seq1, seq2)
  cat(result$score, result$alignment, "\n")
}

main()