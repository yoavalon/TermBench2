initialize_sequence <- function(seq) {
  list(sequence = seq, position = 0)
}

align_sequences <- function(seq1, seq2) {
  seq1_data <- initialize_sequence(seq1)
  seq2_data <- initialize_sequence(seq2)
  while (seq1_data$position < nchar(seq1_data$sequence) && seq2_data$position < nchar(seq2_data$sequence)) {
    if (substr(seq1_data$sequence, seq1_data$position, seq1_data$position) == substr(seq2_data$sequence, seq2_data$position, seq2_data$position)) {
      seq1_data$position <- seq1_data$position + 1
      seq2_data$position <- seq2_data$position + 1
    } else {
      seq1_data$position <- seq1_data$position + 1
    }
  }
  return(seq1_data$position)
}

main <- function() {
  sequence1 <- 'AGCTAGCTAGCT'
  sequence2 <- 'AGCTAGCTAGCT'
  result <- align_sequences(sequence1, sequence2)
  print(result)
}

main()