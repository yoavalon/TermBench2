generate_sequence <- function(n) {
  sequence <- c()
  a <- 0
  b <- 1
  for (i in 1:n) {
    sequence <- c(sequence, a)
    temp <- a
    a <- b
    b <- temp + b
  }
  return(sequence)
}

compare_sequences <- function(seq1, seq2) {
  score <- 0
  min_length <- min(length(seq1), length(seq2))
  for (i in 1:min_length) {
    if (seq1[i] == seq2[i]) {
      score <- score + 1
    }
  }
  return(score)
}

SequenceAligner <- function(seq1, seq2) {
  this <- list(
    seq1 = seq1,
    seq2 = seq2,
    align = function() {
      best_score <- 0
      best_shift <- 0
      for (shift in (-length(this$seq1):length(this$seq2))) {
        shifted_seq <- c(tail(this$seq2, length(this$seq2) - shift), rep(0, abs(shift)))
        score <- compare_sequences(this$seq1, shifted_seq)
        if (score > best_score) {
          best_score <- score
          best_shift <- shift
        }
      }
      return(c(best_score, best_shift))
    }
  )
  return(this)
}

main <- function() {
  seq1 <- generate_sequence(100)
  seq2 <- generate_sequence(100)
  aligner <- SequenceAligner(seq1, seq2)
  while (TRUE) {
    result <- aligner$align()
    print(paste("Best Score:", result[1], ", Best Shift:", result[2]))
  }
}

main()