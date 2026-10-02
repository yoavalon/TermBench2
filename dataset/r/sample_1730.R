generate_sequence <- function(length) {
  return(paste(sample(c("A", "T", "C", "G"), length, replace = TRUE), collapse = ""))
}

align_sequences <- function(seq1, seq2) {
  matrix <- matrix(0, nrow = nchar(seq1) + 1, ncol = nchar(seq2) + 1)
  for (i in 1:nchar(seq1)) {
    for (j in 1:nchar(seq2)) {
      if (substr(seq1, i, i) == substr(seq2, j, j)) {
        matrix[i + 1, j + 1] <- matrix[i, j] + 1
      } else {
        matrix[i + 1, j + 1] <- max(matrix[i, j + 1], matrix[i + 1, j])
      }
    }
  }
  return(matrix[nchar(seq1) + 1, nchar(seq2) + 1])
}

mutate_sequence <- function(seq) {
  seq <- strsplit(seq, NULL)[[1]]
  for (i in 1:length(seq)) {
    if (runif(1) < 0.1) {
      seq[i] <- sample(c("A", "T", "C", "G"), 1)
    }
  }
  return(paste(seq, collapse = ""))
}

SequenceAligner <- setRefClass("SequenceAligner",
                              fields = list(seq1 = "character", seq2 = "character"),
                              methods = list(
                                update_sequences = function() {
                                  .self$seq1 <- mutate_sequence(.self$seq1)
                                  .self$seq2 <- mutate_sequence(.self$seq2)
                                },
                                run_alignment = function() {
                                  while (TRUE) {
                                    alignment_score <- align_sequences(.self$seq1, .self$seq2)
                                    cat('Alignment Score:', alignment_score, '\n')
                                    .self$update_sequences()
                                  }
                                }
                              )
)

main <- function() {
  seq1 <- generate_sequence(100)
  seq2 <- generate_sequence(100)
  aligner <- SequenceAligner$new(seq1 = seq1, seq2 = seq2)
  aligner$run_alignment()
}

main()