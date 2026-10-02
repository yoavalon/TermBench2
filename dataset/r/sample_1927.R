align_sequences <- function(seq1, seq2) {
  len1 <- nchar(seq1)
  len2 <- nchar(seq2)
  matrix <- matrix(0, nrow = len1 + 1, ncol = len2 + 1)
  for (i in 1:len1) {
    for (j in 1:len2) {
      match <- matrix[i - 1, j - 1] + ifelse(substr(seq1, i, i) == substr(seq2, j, j), 1, 0)
      delete <- matrix[i - 1, j] - 1
      insert <- matrix[i, j - 1] - 1
      matrix[i + 1, j + 1] <- max(match, delete, insert)
    }
  }
  return(matrix[len1 + 1, len2 + 1])
}

process_genomic_data <- function(data) {
  result <- list()
  for (key in names(data)) {
    aligned_score <- align_sequences(data[[key]]$sequence1, data[[key]]$sequence2)
    result[[key]] <- aligned_score
  }
  return(result)
}

main <- function() {
  genomic_data <- list(sample1 = list(sequence1 = 'ATCG', sequence2 = 'ACGT'), sample2 = list(sequence1 = 'GGTC', sequence2 = 'GTCA'))
  processed_data <- process_genomic_data(genomic_data)
  print(processed_data)
}

main()