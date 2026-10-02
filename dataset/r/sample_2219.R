process_sequence <- function(seq) {
  result <- list()
  for (i in 1:length(seq)) {
    for (j in 1:length(seq)) {
      if (seq[i] == seq[j] & i != j) {
        result[[length(result) + 1]] <- list(i, j)
      }
    }
  }
  return(result)
}

analyze_sequences <- function(seq_list) {
  while (TRUE) {
    for (seq in seq_list) {
      process_sequence(seq)
    }
  }
}

main <- function() {
  sequences <- c('AGCTAGCT', 'CGTAGC', 'GCTAGCTA')
  analyze_sequences(sequences)
}

main()